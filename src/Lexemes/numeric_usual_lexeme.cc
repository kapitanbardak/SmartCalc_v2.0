#include "numeric_usual_lexeme.h"
#include "lexeme.h"
#include <string>
#include <regex>

namespace s21 {
    const std::regex NumericUsualLexeme::PATTERN("^(([0-9]*[.])?[0-9]+([eE][-+]?[0-9]+)?)$");

    void NumericUsualLexeme::Validate(std::string& str)  {
        is_valid = std::regex_match(str, PATTERN);
    }

    NumericUsualLexeme::NumericUsualLexeme(std::string lex)  : NumericLexeme(lex){

        NumericUsualLexeme::Validate(lex);
        Lexeme::type_code = Lexeme::LexType(NUMERIC);
    }

    double NumericUsualLexeme::GetValue() {
        return (std::stod(value));
    }

} // namespace s21
