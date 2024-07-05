#ifndef UNARY_OPERAND_LEXEME_H
#define UNARY_OPERAND_LEXEME_H
#include <string>
#include "operator_lexeme.h"

namespace s21 {

    class UnaryLexeme : public OperatorLexeme {
    public:
        UnaryLexeme(std::string);
    };

} // s21
#endif // UNARY_OPERAND_LEXEME_H
