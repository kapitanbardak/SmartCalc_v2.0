#include "open_bracket_lexeme.h"
#include "../operator_map.h"
#include <string>
#include <regex>
#include <stdexcept>

namespace s21 {
    std::regex OpenBracketLexeme::operations_pattern;

    void OpenBracketLexeme::InitializeOperationsPattern(OperatorMap* operator_map) {
        operations_pattern = operator_map->GetBracketOperationsRegex("(");
    }

    OpenBracketLexeme::OpenBracketLexeme(std::string lex) : BracketLexeme(lex) {
        if (BracketLexeme::is_valid) {
            if (operations_pattern.mark_count() == 0)
                throw std::runtime_error("Static variable of pattern not initialized");
            OpenBracketLexeme::Validate(lex);
            Lexeme::type_code = Lexeme::LexType(OPEN_BRACKET);
        }
    }

    void OpenBracketLexeme::Validate(std::string& str) {
        is_valid = std::regex_match(str, operations_pattern);
    }

} // namespace s21
