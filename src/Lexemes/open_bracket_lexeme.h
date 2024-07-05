#ifndef OPEN_BRACKET_LEXEME_COPY_H
#define OPEN_BRACKET_LEXEME_COPY_H
#include "bracket_lexeme.h"

namespace s21 {

    class OpenBracketLexeme : public BracketLexeme {
    public:
        OpenBracketLexeme(std::string);
        void Validate(std::string&) override;
        static void InitializeOperationsPattern(OperatorMap*);
    private:
        static std::regex operations_pattern;
    };

}
#endif // OPEN_BRACKET_LEXEME_COPY_H
