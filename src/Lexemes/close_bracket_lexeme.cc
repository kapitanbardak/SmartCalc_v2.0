#include "close_bracket_lexeme.h"
#include "../operator_map.h"
#include <string>
#include <regex>
#include <stdexcept>

namespace s21 {
    std::regex CloseBracketLexeme::operations_pattern;

    void CloseBracketLexeme::InitializeOperationsPattern(OperatorMap* operator_map) {
        operations_pattern = operator_map->GetBracketOperationsRegex(")");
    }

    CloseBracketLexeme::CloseBracketLexeme(std::string lex) : BracketLexeme(lex) {
        if (BracketLexeme::is_valid) {
            if (operations_pattern.mark_count() == 0)
                throw std::runtime_error("Static variable of pattern not initialized");
            CloseBracketLexeme::Validate(lex);
            Lexeme::type_code = Lexeme::LexType(CLOSE_BRACKET);
        }
    }

    void CloseBracketLexeme::Validate(std::string& str) {
        is_valid = std::regex_match(str, operations_pattern);
    }

} // namespace s21
