#ifndef NUMERIC_LEXEME_H
#define NUMERIC_LEXEME_H
#include <string>
#include <regex>
#include "lexeme.h"
#include <any>

namespace s21 {
    class NumericLexeme : public Lexeme {
    public:
        static const std::regex PATTERN;
        NumericLexeme(std::string);
        void Validate(std::string&) override;
        virtual double GetValue() = 0;
    };

} // s21

#endif // NUMERIC_LEXEME_H
