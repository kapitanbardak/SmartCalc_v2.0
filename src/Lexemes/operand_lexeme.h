#ifndef OPERAND_LEXEME_H
#define OPERAND_LEXEME_H
#include <string>
#include <regex>
#include "operator_lexeme.h"
#include "../operator_map.h"

namespace s21 {

    class OperandLexeme : public OperatorLexeme {
    public:
        OperandLexeme(std::string);
        void Validate(std::string&) override;
        static void InitializeOperationsPattern(OperatorMap*);
    private:
        static std::regex operations_pattern;
    };

} // s21
#endif // OPERAND_LEXEME_H
