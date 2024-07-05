#ifndef LEXEME_H
#define LEXEME_H
#include <string>
#include <regex>

namespace s21 {
    class Lexeme {
    public:
        enum LexType {
            NUMERIC,
            USUAL_OPERAND,
            DUAL_PURPOSE_OPERAND,
            FUNCTION,
            OPEN_BRACKET,
            CLOSE_BRACKET,
            NUMERIC_CONST
        };
        Lexeme(std::string& lex);
        virtual ~Lexeme();
        bool is_valid;
        std::string value;
        int type_code;
        virtual void Validate(std::string&) = 0;
    };

} // s21

#endif // LEXEME_H
