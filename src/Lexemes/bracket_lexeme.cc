#include "bracket_lexeme.h"
#include "../operator_map.h"
#include <string>
#include <regex>
#include <stdexcept>

namespace s21 {
    std::regex BracketLexeme::operations_pattern;

    void BracketLexeme::InitializeOperationsPattern(OperatorMap* operator_map) {
        operations_pattern = operator_map->GetFunctionOperationsRegex(0);
    }

    BracketLexeme::BracketLexeme(std::string lex) : OperatorLexeme(lex) {
        if (OperatorLexeme::is_valid) {
            if (operations_pattern.mark_count() == 0)
                throw std::runtime_error("Static variable of pattern not initialized");
            BracketLexeme::Validate(lex);
        }
    }

    void BracketLexeme::Validate(std::string& str) {
        is_valid = std::regex_match(str, operations_pattern);
    }

} // namespace s21
