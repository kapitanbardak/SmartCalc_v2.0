#include "string_reader.h"

#include <string.h>

#include <cctype>

#include "Lexemes/bracket_lexeme.h"
#include "Lexemes/close_bracket_lexeme.h"
#include "Lexemes/dual_purpose_operand_lexeme.h"
#include "Lexemes/function_lexeme.h"
#include "Lexemes/lexeme.h"
#include "Lexemes/numeric_const_lexeme.h"
#include "Lexemes/numeric_usual_lexeme.h"
#include "Lexemes/open_bracket_lexeme.h"
#include "Lexemes/operand_lexeme.h"
#include "Lexemes/operator_lexeme.h"
#include "Lexemes/unary_operand_lexeme.h"
#include "Lexemes/usual_operand_lexeme.h"
#include "operator_map.h"

namespace s21 {
StringReader::StringReader() = default;

int StringReader::sequence_validation_matrix
    [StringReader::FIRST_LEX_TYPE_NUM][StringReader::SECOND_LEX_TYPE_NUM] = {
        // num                                  usual_operand
        // dual_purpose_operand         function open_bracket close_bracket
        // const_num
        {ValidationCase(WRONG), ValidationCase(NORMAL), ValidationCase(NORMAL),
         ValidationCase(INSERT_MULT), ValidationCase(INSERT_MULT),
         ValidationCase(NORMAL), ValidationCase(INSERT_MULT)},
        {ValidationCase(NORMAL), ValidationCase(WRONG), ValidationCase(WRONG),
         ValidationCase(NORMAL), ValidationCase(NORMAL), ValidationCase(WRONG),
         ValidationCase(NORMAL)},
        {ValidationCase(NORMAL), ValidationCase(WRONG), ValidationCase(WRONG),
         ValidationCase(NORMAL), ValidationCase(NORMAL), ValidationCase(WRONG),
         ValidationCase(NORMAL)},
        {ValidationCase(WRONG), ValidationCase(WRONG), ValidationCase(WRONG),
         ValidationCase(WRONG), ValidationCase(NORMAL), ValidationCase(WRONG),
         ValidationCase(WRONG)},
        {ValidationCase(NORMAL), ValidationCase(WRONG),
         ValidationCase(CONVERT_TO_UNARY), ValidationCase(NORMAL),
         ValidationCase(NORMAL), ValidationCase(WRONG), ValidationCase(NORMAL)},
        {ValidationCase(INSERT_MULT), ValidationCase(NORMAL),
         ValidationCase(NORMAL), ValidationCase(INSERT_MULT),
         ValidationCase(WRONG), ValidationCase(NORMAL),
         ValidationCase(INSERT_MULT)},
        {ValidationCase(INSERT_MULT), ValidationCase(NORMAL),
         ValidationCase(NORMAL), ValidationCase(INSERT_MULT),
         ValidationCase(INSERT_MULT), ValidationCase(NORMAL),
         ValidationCase(WRONG)}};

int StringReader::first_validation_vector[StringReader::FIRST_LEX_TYPE_NUM] = {
    ValidationCase(NORMAL),
    ValidationCase(WRONG),
    ValidationCase(CONVERT_TO_UNARY),
    ValidationCase(NORMAL),
    ValidationCase(NORMAL),
    ValidationCase(WRONG),
    ValidationCase(NORMAL)};
int StringReader::last_validation_vector[StringReader::FIRST_LEX_TYPE_NUM] = {
    ValidationCase(NORMAL), ValidationCase(WRONG), ValidationCase(WRONG),
    ValidationCase(WRONG),  ValidationCase(WRONG), ValidationCase(NORMAL),
    ValidationCase(NORMAL)};

StringReader::StringReader(OperatorMap* operator_map) {
  OperatorLexeme::InitializeOperationsPattern(operator_map);
  OperandLexeme::InitializeOperationsPattern(operator_map);
  UsualOperandLexeme::InitializeOperationsPattern(operator_map);
  DualPurposeOperandLexeme::InitializeOperationsPattern(operator_map);
  FunctionLexeme::InitializeOperationsPattern(operator_map);
  BracketLexeme::InitializeOperationsPattern(operator_map);
  OpenBracketLexeme::InitializeOperationsPattern(operator_map);
  CloseBracketLexeme::InitializeOperationsPattern(operator_map);
}

StringReader::~StringReader() {
  if (!StringReader::tokens.empty()) {
    for (auto i : StringReader::tokens) {
      delete i;
    }
  }
}

void StringReader::Tokenize(const std::string& str) {
  std::string f_str = FormatString(str);
  if (f_str == last_string)
    return;
  else {
    tokens.clear();
    last_string = f_str;
    int length = f_str.size();
    int cursor = 0;
    int back_counter;
    while (cursor < length) {
      back_counter = length;
      bool valid_lexeme = false;
      std::string substr = f_str.substr(cursor, back_counter);
      while (substr.size()) {
        if (Lexeme* lex = GenerateLexemeBySubstring(substr)) {
          tokens.push_back(lex);
          cursor += substr.size();
          valid_lexeme = true;
          break;
        } else {
          substr = f_str.substr(cursor, --back_counter - cursor);
        }
      }
      if (!valid_lexeme) throw std::invalid_argument("Incorrect input");
    }
    StringReader::InnerValidation();
    StringReader::EdgeValidation(StringReader::first_validation_vector, 0);
    StringReader::EdgeValidation(StringReader::last_validation_vector,
                                 tokens.size() - 1);
    StringReader::BracketValidation();
  }
}

Lexeme* StringReader::GenerateLexemeBySubstring(std::string& str) {
  Lexeme* result;
  result = new NumericUsualLexeme(str);
  if (result->is_valid)
    return result;
  else
    delete result;
  result = new NumericConstLexeme(str);
  if (result->is_valid)
    return result;
  else
    delete result;
  result = new UsualOperandLexeme(str);
  if (result->is_valid)
    return result;
  else
    delete result;
  result = new DualPurposeOperandLexeme(str);
  if (result->is_valid)
    return result;
  else
    delete result;
  result = new FunctionLexeme(str);
  if (result->is_valid)
    return result;
  else
    delete result;
  result = new OpenBracketLexeme(str);
  if (result->is_valid)
    return result;
  else
    delete result;
  result = new CloseBracketLexeme(str);
  if (result->is_valid)
    return result;
  else {
    delete result;
    result = nullptr;
  }
  return result;
}

std::string StringReader::ToLowerCase(const std::string& str) {
  std::string result = str;
  for (char& c : result) {
    c = std::tolower(c);
  }
  return result;
}

void StringReader::RemoveSpaces(std::string& str) {
  str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}

void StringReader::ReplaceCommasWithDots(std::string& str) {
  std::replace(str.begin(), str.end(), ',', '.');
}

std::string StringReader::FormatString(const std::string& input) {
  std::string formattedString = input;
  RemoveSpaces(formattedString);
  ReplaceCommasWithDots(formattedString);
  formattedString = ToLowerCase(formattedString);
  return formattedString;
}

void StringReader::InnerValidation() {
  size_t length = tokens.size();
  for (size_t i = 0; i < length - 1; ++i) {
    switch (sequence_validation_matrix[tokens[i]->type_code]
                                      [tokens[i + 1]->type_code]) {
      case ValidationCase(WRONG): {
        throw std::invalid_argument("Incorrect input");
        break;
      }

      case ValidationCase(CONVERT_TO_UNARY): {
        Lexeme* temp = tokens[i + 1];
        Lexeme* unary = new UnaryLexeme("u" + temp->value);
        unary->type_code = temp->type_code;
        tokens[i + 1] = unary;
        delete temp;
        break;
      }

      case ValidationCase(INSERT_MULT): {
        auto it = tokens.begin() + i + 1;
        Lexeme* mult = new UsualOperandLexeme("*");
        tokens.insert(it, mult);
        ++length;
        break;
      }

      default:
        break;
    }
  }
};

void StringReader::EdgeValidation(int* validation_vector, int pos) {
  switch (validation_vector[tokens[pos]->type_code]) {
    case ValidationCase(WRONG): {
      throw std::invalid_argument("Incorrect input on edge");
      break;
    }

    case ValidationCase(CONVERT_TO_UNARY): {
      Lexeme* temp = tokens[pos];
      Lexeme* unary = new UnaryLexeme("u" + temp->value);
      unary->type_code = temp->type_code;
      tokens[pos] = unary;
      delete temp;
      break;
    }

    default:
      break;
  }
}

void StringReader::BracketValidation() {
  int subs = 0;
  for (size_t i = 0; i < tokens.size(); ++i) {
    if (dynamic_cast<OpenBracketLexeme*>(tokens[i])) {
      ++subs;
      continue;
    }
    if (dynamic_cast<CloseBracketLexeme*>(tokens[i])) {
      --subs;
    }
  }
  if (subs != 0) throw std::invalid_argument("Incorrect input");
}

std::vector<Lexeme*> StringReader::GetLexemeSequence() { return tokens; }

}  // namespace s21
