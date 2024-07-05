#include "model.h"

#include <cmath>
#include <stdexcept>
#include <vector>

#include "Lexemes/lexeme.h"
#include "Lexemes/numeric_const_lexeme.h"
#include "Lexemes/numeric_lexeme.h"
#include "Lexemes/numeric_usual_lexeme.h"
#include "Lexemes/operator_lexeme.h"
#include "operator_map.h"
#include "string_reader.h"

namespace s21 {
Model::Model() {
  operator_map = new OperatorMap();
  string_reader = StringReader(operator_map);
  stack_calculator = TwoStackCalculator();
}

Model::~Model() { delete operator_map; }

std::string Model::CalculateNoVariableExpression() {
  try {
    return CalcSequence();
  } catch (...) {
    return "Error";
  }
}

std::string Model::CalculateVariableExpression(std::string x) {
  NumericConstLexeme::SetX(x);
  return CalculateNoVariableExpression();
}

std::string Model::CalcSequence() {
  for (auto i : sequence) {
    if (dynamic_cast<NumericLexeme *>(i)) {
      stack_calculator.AddNumber(dynamic_cast<NumericLexeme *>(i)->GetValue());
    } else {
      stack_calculator.AddOperator(operator_map->GetOperatorByLexeme(
          dynamic_cast<OperatorLexeme *>(i)->GetValue()));
    }
  }
  stack_calculator.FinalizeStacks();
  double result = stack_calculator.GetResult();
  if (result == 0) result = std::abs(result);
  return std::to_string(result);
}

std::string Model::ValidateInput(std::string str) {
  try {
    NeedAdditionalInput = false;
    string_reader.Tokenize(str);
    sequence = string_reader.GetLexemeSequence();
    std::string result = "correct";
    for (auto i : sequence) {
      if (i->value == "x") {
        NeedAdditionalInput = true;
        result = "x input is needed";
        break;
      }
    }
    return result;
  } catch (...) {
    return "Error";
  }
}

}  // namespace s21
