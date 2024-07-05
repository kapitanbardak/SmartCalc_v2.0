#ifndef FUNCTION_LEXEME_H
#define FUNCTION_LEXEME_H
#include <string>
#include <regex>
#include "operator_lexeme.h"
#include "../operator_map.h"

namespace s21 {

    class FunctionLexeme : public OperatorLexeme {
    public:
        FunctionLexeme(std::string);
        void Validate(std::string&) override;
        static void InitializeOperationsPattern(OperatorMap*);
    private:
        static std::regex operations_pattern;
    };

} // s21
#endif // FUNCTION_LEXEME_H
