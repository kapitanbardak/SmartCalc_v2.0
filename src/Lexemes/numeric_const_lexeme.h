#ifndef NUMERIC_CONST_LEXEME_H
#define NUMERIC_CONST_LEXEME_H
#include <string>
#include <regex>
#include "numeric_lexeme.h"
#include <any>

namespace s21 {
    class NumericConstLexeme : public NumericLexeme {
    public:
        static const std::regex PATTERN;
        NumericConstLexeme(std::string);
        void Validate(std::string&) override;
        double GetValue() override;
        static void SetX(std::string str);
    private:
        static double x_value;
    };

} // s21

#endif // NUMERIC_CONST_LEXEME_H
