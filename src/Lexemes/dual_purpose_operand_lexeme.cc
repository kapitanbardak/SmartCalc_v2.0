#include "dual_purpose_operand_lexeme.h"
#include "../operator_map.h"
#include <string>
#include <regex>
#include <stdexcept>

namespace s21 {
    std::regex DualPurposeOperandLexeme::operations_pattern;

    void DualPurposeOperandLexeme::InitializeOperationsPattern(OperatorMap* operator_map) {
        operations_pattern = operator_map->GetDualOperandRegex();
    }

    DualPurposeOperandLexeme::DualPurposeOperandLexeme(std::string lex) : OperandLexeme(lex) {
        if (OperandLexeme::is_valid) {
            if (operations_pattern.mark_count() == 0)
                throw std::runtime_error("Static variable of pattern not initialized");
            DualPurposeOperandLexeme::Validate(lex);
            Lexeme::type_code = Lexeme::LexType(DUAL_PURPOSE_OPERAND);
        }
    }

    void DualPurposeOperandLexeme::Validate(std::string& str) {
        is_valid = std::regex_match(str, operations_pattern);
    }

} // namespace s21
