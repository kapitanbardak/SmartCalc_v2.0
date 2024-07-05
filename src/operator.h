#ifndef OPERATOR_H
#define OPERATOR_H

#include <any>
#include <functional>

#include "decorators.h"

namespace s21 {
class Operator {
  enum BRACKETS { NOT_BRACKET, OPEN, CLOSE };

 public:
  Operator() = default;

  template <typename... Args>
  Operator(unsigned char rang, bool prefix, unsigned char arg_num,
           std::any comp)
      : rang(rang),
        prefix(prefix),
        arg_num(arg_num),
        saved_func(comp),
        bracket_flag(BRACKETS(NOT_BRACKET)) {}

  Operator(unsigned char rang, bool prefix, unsigned char arg_num,
           const std::string& lexeme);

  unsigned char rang;
  bool prefix;
  unsigned char arg_num;
  std::any saved_func;
  int bracket_flag;

  bool IsOpenBracket();
  bool IsCloseBracket();
  bool IsBracket();

  template <typename... Args>
  double CallFunction(Args... args) const {
    Component<Args...>* comp_ptr =
        std::any_cast<Component<Args...>*>(saved_func);
    return comp_ptr->operation(args...);
  }
};

}  // namespace s21

#endif  // OPERATOR_H
