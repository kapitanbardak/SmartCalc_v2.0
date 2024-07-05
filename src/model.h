#ifndef SRC_MODEL_H
#define SRC_MODEL_H

#include <string.h>

#include "operator_map.h"
#include "string_reader.h"
#include "two_stack_calculator.h"

namespace s21 {
class Model {
 public:
  Model();
  ~Model();
  std::string ValidateInput(std::string);
  std::string CalculateNoVariableExpression();
  std::string CalculateVariableExpression(std::string);
  bool NeedAdditionalInput;

 private:
  OperatorMap* operator_map;
  StringReader string_reader;
  TwoStackCalculator stack_calculator;
  std::vector<Lexeme*> sequence;
  std::string CalcSequence();
};
}  // namespace s21

#endif  // SRC_MODEL_H
