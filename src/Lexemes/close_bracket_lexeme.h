#ifndef CLOSE_BRACKET_LEXEME_H
#define CLOSE_BRACKET_LEXEME_H
#include "bracket_lexeme.h"

namespace s21 {

    class CloseBracketLexeme : public BracketLexeme {
    public:
        CloseBracketLexeme(std::string);
        void Validate(std::string&) override;
        static void InitializeOperationsPattern(OperatorMap*);
    private:
        static std::regex operations_pattern;
    };

}
#endif // CLOSE_BRACKET_LEXEME_H
