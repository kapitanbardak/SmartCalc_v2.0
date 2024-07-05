#ifndef BRACKET_LEXEME_H
#define BRACKET_LEXEME_H
#include <string>
#include <regex>
#include "operator_lexeme.h"
#include "../operator_map.h"

namespace s21 {

    class BracketLexeme : public OperatorLexeme {
    public:
        BracketLexeme(std::string);
        void Validate(std::string&) override;
        static void InitializeOperationsPattern(OperatorMap*);
    private:
        static std::regex operations_pattern;
    };

} // s21
#endif // BRACKET_LEXEME_H
