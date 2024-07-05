#include "numeric_lexeme.h"
#include <string>
#include <regex>

namespace s21 {
    const std::regex NumericLexeme::PATTERN("^(([0-9]*[.])?[0-9]+([eE][-+]?[0-9]+)?)|pi|x|exp$");

    void NumericLexeme::Validate(std::string& str)  {
        is_valid = std::regex_match(str, PATTERN);
    }

    NumericLexeme::NumericLexeme(std::string lex)  : Lexeme(lex){

        NumericLexeme::Validate(lex);
        Lexeme::type_code = Lexeme::LexType(NUMERIC);
    }

} // namespace s21
