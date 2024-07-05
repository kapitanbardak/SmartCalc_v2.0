#include "two_stack_calculator.h"

#include <iostream>

namespace s21 {
void TwoStackCalculator::AddNumber(double value) { number_stack.push(value); }

void TwoStackCalculator::AddOperator(Operator added_operator) {
  if (!added_operator.IsCloseBracket()) {
    if (operator_stack.empty() || added_operator.IsOpenBracket()) {
      operator_stack.push(added_operator);
    } else {
      if (added_operator.rang > operator_stack.top().rang) {
        operator_stack.push(added_operator);
      } else {
        ExecuteLastOperator();
        AddOperator(added_operator);
      }
    }
  } else {
    if (operator_stack.top().IsOpenBracket()) {
      operator_stack.pop();
    } else {
      ExecuteLastOperator();
      AddOperator(added_operator);
    }
  }
}

void TwoStackCalculator::ExecuteLastOperator() {
  Operator op = operator_stack.top();
  operator_stack.pop();

  std::vector<double> args;

  for (int i = 0; i < op.arg_num; i++) {
    double value = number_stack.top();
    number_stack.pop();
    args.insert(args.begin(), value);
  }
  double result;
  if (op.arg_num == 1) result = op.CallFunction<double>(args[0]);
  if (op.arg_num == 2)
    result = op.CallFunction<double, double>(args[0], args[1]);
  number_stack.push(result);
}

void TwoStackCalculator::FinalizeStacks() {
  while (!operator_stack.empty()) {
    ExecuteLastOperator();
  }
}

double TwoStackCalculator::GetResult() { return number_stack.top(); }

}  // namespace s21
