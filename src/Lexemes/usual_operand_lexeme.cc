#include "usual_operand_lexeme.h"
#include "../operator_map.h"
#include <string>
#include <regex>
#include <stdexcept>

namespace s21 {
    std::regex UsualOperandLexeme::operations_pattern;

    void UsualOperandLexeme::InitializeOperationsPattern(OperatorMap* operator_map) {
        operations_pattern = operator_map->GetUsualOperandRegex();
    }

    UsualOperandLexeme::UsualOperandLexeme(std::string lex) : OperandLexeme(lex) {
        if (OperandLexeme::is_valid) {
            if (operations_pattern.mark_count() == 0)
                throw std::runtime_error("Static variable of pattern not initialized");
            UsualOperandLexeme::Validate(lex);
            Lexeme::type_code = Lexeme::LexType(USUAL_OPERAND);
        }
    }

    void UsualOperandLexeme::Validate(std::string& str) {
        is_valid = std::regex_match(str, operations_pattern);
    }

} // namespace s21
