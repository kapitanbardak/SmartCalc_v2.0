#include "lexeme.h"
#include <string>
#include <regex>

namespace s21 {

    Lexeme::Lexeme(std::string& lex) : is_valid(false), value(lex) {}
    Lexeme::~Lexeme() = default;

} // namespace s21
