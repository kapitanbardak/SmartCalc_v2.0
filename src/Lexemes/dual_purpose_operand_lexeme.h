#ifndef DUAL_PURPOSE_OPERAND_LEXEME_H
#define DUAL_PURPOSE_OPERAND_LEXEME_H
#include <string>
#include <regex>
#include "operand_lexeme.h"
#include "../operator_map.h"

namespace s21 {

    class DualPurposeOperandLexeme : public OperandLexeme {
    public:
        DualPurposeOperandLexeme(std::string);
        void Validate(std::string&) override;
        static void InitializeOperationsPattern(OperatorMap*);
    private:
        static std::regex operations_pattern;
    };

} // s21
#endif // DUAL_PURPOSE_OPERAND_LEXEME_H
