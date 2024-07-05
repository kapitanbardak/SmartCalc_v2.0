#ifndef NUMERIC_USUAL_LEXEME_H
#define NUMERIC_USUAL_LEXEME_H
#include <string>
#include <regex>
#include "numeric_lexeme.h"
#include <any>

namespace s21 {
    class NumericUsualLexeme : public NumericLexeme {
    public:
        static const std::regex PATTERN;
        NumericUsualLexeme(std::string);
        void Validate(std::string&) override;
        double GetValue() override;
    };

} // s21

#endif // NUMERIC_USUAL_LEXEME_H
