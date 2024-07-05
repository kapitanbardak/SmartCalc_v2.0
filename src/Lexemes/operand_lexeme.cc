#include "operand_lexeme.h"
#include "../operator_map.h"
#include <string>
#include <regex>
#include <stdexcept>

namespace s21 {
    std::regex OperandLexeme::operations_pattern;

    void OperandLexeme::InitializeOperationsPattern(OperatorMap* operator_map) {
        operations_pattern = operator_map->GetFunctionOperationsRegex(2);
    }

    OperandLexeme::OperandLexeme(std::string lex) : OperatorLexeme(lex) {
        if (OperatorLexeme::is_valid) {
            if (operations_pattern.mark_count() == 0)
                throw std::runtime_error("Static variable of pattern not initialized");
            OperandLexeme::Validate(lex);
        }
    }

    void OperandLexeme::Validate(std::string& str) {
        is_valid = std::regex_match(str, operations_pattern);
    }

} // namespace s21
