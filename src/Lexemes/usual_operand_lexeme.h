#ifndef USUAL_OPERAND_LEXEME_H
#define USUAL_OPERAND_LEXEME_H
#include <string>
#include <regex>
#include "operand_lexeme.h"
#include "../operator_map.h"

namespace s21 {

    class UsualOperandLexeme : public OperandLexeme {
    public:
        UsualOperandLexeme(std::string);
        void Validate(std::string&) override;
        static void InitializeOperationsPattern(OperatorMap*);
    private:
        static std::regex operations_pattern;
    };

} // s21
#endif // USUAL_OPERAND_LEXEME_H
