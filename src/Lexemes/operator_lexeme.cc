#include "operator_lexeme.h"
#include "../operator_map.h"
#include <string>
#include <regex>
#include <stdexcept>

namespace s21 {
    std::regex OperatorLexeme::operations_pattern;

    void OperatorLexeme::InitializeOperationsPattern(OperatorMap* operator_map) {
        operations_pattern = operator_map->GetAllOperationsRegex();
    }

    OperatorLexeme::OperatorLexeme(std::string& lex) : Lexeme(lex) {
        if (OperatorLexeme::operations_pattern.mark_count() == 0)
            throw std::runtime_error("Static variable of pattern not initialized!");
        OperatorLexeme::Validate(lex);
    }

    void OperatorLexeme::Validate(std::string& str) {
        is_valid = std::regex_match(str, operations_pattern);
    }

    std::string OperatorLexeme::GetValue() {
        return value;
    }

} // namespace s21
