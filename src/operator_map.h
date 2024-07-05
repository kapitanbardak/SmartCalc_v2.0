#ifndef OPERATOR_MAP_H
#define OPERATOR_MAP_H

#include <map>
#include <regex>
#include <stdexcept>
#include <string>

#include "operations.h"
#include "operator.h"

namespace s21 {
class OperatorMap {
 public:
  OperatorMap();
  ~OperatorMap();

  double CalcOperation(const std::string& lexeme, const double value);
  double CalcOperation(const std::string& lexeme, const double first_value,
                       const double second_value);

  Operator& GetOperatorByLexeme(const std::string&);

  template <typename... Args>
  void AddOperation(const std::string& lexeme, unsigned char rang, bool prefix,
                    unsigned char arg_num, Component<Args...>* comp) {
    m_operators[lexeme] = Operator(rang, prefix, arg_num, comp);
  };
  void AddOperation(const std::string& lexeme, unsigned char rang, bool prefix,
                    unsigned char arg_num) {
    m_operators[lexeme] = Operator(rang, prefix, arg_num, lexeme);
  }
  std::regex GetAllOperationsRegex();
  std::regex GetFunctionOperationsRegex(const unsigned int&);
  std::regex GetBracketOperationsRegex(const std::string&);
  std::regex GetDualOperandRegex();
  std::regex GetUsualOperandRegex();

 private:
  std::map<std::string, Operator> m_operators;
  std::string escapeRegex(const std::string&);
  Operations* ops;
};

}  // namespace s21

#endif  // OPERATOR_MAP_H
