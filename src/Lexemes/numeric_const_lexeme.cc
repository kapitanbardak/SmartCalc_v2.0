#include "numeric_const_lexeme.h"
#include "numeric_lexeme.h"
#include <string>
#include <regex>

namespace s21 {
    const std::regex NumericConstLexeme::PATTERN("^pi|x|exp$");
    double NumericConstLexeme::x_value = 0.0;

    void NumericConstLexeme::Validate(std::string& str)  {
        is_valid = std::regex_match(str, PATTERN);
    }

    NumericConstLexeme::NumericConstLexeme(std::string lex)  : NumericLexeme(lex){

        NumericConstLexeme::Validate(lex);
        Lexeme::type_code = Lexeme::LexType(NUMERIC_CONST);
    }

    double NumericConstLexeme::GetValue() {
        if (value == "exp")
            return std::exp(1.0);
        if (value == "pi")
            return std::atan(1)*4;;
        return NumericConstLexeme::x_value;
    }

    void NumericConstLexeme::SetX(std::string value) {
        x_value = std::stod(value);
    }

} // namespace s21
