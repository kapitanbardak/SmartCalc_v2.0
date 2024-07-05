#ifndef TWO_STACK_CALCULATOR_H
#define TWO_STACK_CALCULATOR_H
#include <stack>

#include "operator.h"

namespace s21 {
class TwoStackCalculator {
 public:
  void AddOperator(Operator);
  void ExecuteLastOperator();
  void AddNumber(double);
  void FinalizeStacks();
  double GetResult();

 private:
  std::stack<double> number_stack;
  std::stack<Operator> operator_stack;
};

}  // namespace s21
#endif  // TWO_STACK_CALCULATOR_H
