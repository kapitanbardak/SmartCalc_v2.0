#include "function_lexeme.h"
#include "../operator_map.h"
#include <string>
#include <regex>
#include <stdexcept>

namespace s21 {
    std::regex FunctionLexeme::operations_pattern;

    void FunctionLexeme::InitializeOperationsPattern(OperatorMap* operator_map) {
        operations_pattern = operator_map->GetFunctionOperationsRegex(1);
    }

    FunctionLexeme::FunctionLexeme(std::string lex) : OperatorLexeme(lex) {
        if (OperatorLexeme::is_valid) {
            if (operations_pattern.mark_count() == 0)
                throw std::runtime_error("Static variable of pattern not initialized");
            FunctionLexeme::Validate(lex);
            Lexeme::type_code = Lexeme::LexType(FUNCTION);
        }
    }

    void FunctionLexeme::Validate(std::string& str) {
        is_valid = std::regex_match(str, operations_pattern);
    }

} // namespace s21
