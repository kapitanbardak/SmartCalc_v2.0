#ifndef STRING_READER_H
#define STRING_READER_H

#include <string.h>

#include <cctype>
#include <iostream>
#include <vector>

#include "Lexemes/lexeme.h"
#include "operator_map.h"

namespace s21 {
class StringReader {
 public:
  enum ValidationCase { NORMAL, CONVERT_TO_UNARY, INSERT_MULT, WRONG };
  StringReader();
  ~StringReader();
  StringReader(OperatorMap*);
  void Tokenize(const std::string&);
  std::vector<Lexeme*> GetLexemeSequence();

 private:
  Lexeme* GenerateLexemeBySubstring(std::string&);
  std::string last_string;
  std::vector<Lexeme*> tokens;
  std::string ToLowerCase(const std::string&);
  void RemoveSpaces(std::string&);
  void ReplaceCommasWithDots(std::string&);
  std::string FormatString(const std::string&);
  void InnerValidation();
  void EdgeValidation(int*, int);
  void BracketValidation();
  static const int FIRST_LEX_TYPE_NUM = 7;
  static const int SECOND_LEX_TYPE_NUM = 7;
  static int sequence_validation_matrix[FIRST_LEX_TYPE_NUM]
                                       [SECOND_LEX_TYPE_NUM];
  static int first_validation_vector[FIRST_LEX_TYPE_NUM];
  static int last_validation_vector[FIRST_LEX_TYPE_NUM];
};
}  // namespace s21

#endif  // STRING_READER_H
