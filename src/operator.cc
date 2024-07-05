#include "operator.h"

#include <string>

namespace s21 {

Operator::Operator(unsigned char rang, bool prefix, unsigned char arg_num,
                   const std::string& lexeme)
    : rang(rang), prefix(prefix), arg_num(arg_num) {
  if (lexeme == std::string("(") || lexeme == std::string(")")) {
    switch (int(lexeme == "(")) {
      case 1:
        Operator::bracket_flag = BRACKETS(OPEN);
        break;
      default:
        Operator::bracket_flag = BRACKETS(CLOSE);
    }
  }
}

bool Operator::IsBracket() {
  return bracket_flag == BRACKETS(OPEN) || bracket_flag == BRACKETS(CLOSE);
}

bool Operator::IsOpenBracket() { return bracket_flag == BRACKETS(OPEN); }

bool Operator::IsCloseBracket() { return bracket_flag == BRACKETS(CLOSE); }

}  // namespace s21
