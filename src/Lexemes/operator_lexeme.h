#ifndef OPERATOR_LEXEME_H
#define OPERATOR_LEXEME_H
#include <string>
#include <regex>
#include "lexeme.h"
#include "../operator_map.h"

namespace s21 {

    class OperatorLexeme : public Lexeme {
    public:
        OperatorLexeme(std::string&);
        void Validate(std::string&) override;
        static void InitializeOperationsPattern(OperatorMap*);
        std::string GetValue();
    private:
        static std::regex operations_pattern;
    };

} // s21

#endif // OPERATOR_LEXEME_H
