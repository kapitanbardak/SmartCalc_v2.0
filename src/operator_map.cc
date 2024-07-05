#include "operator_map.h"

#include <regex>

#include "operations.h"

namespace s21 {
OperatorMap::OperatorMap() {
  ops = new Operations();

  AddOperation("+", 2, false, 2, ops->decorated_add);
  AddOperation("-", 2, false, 2, ops->decorated_sub);
  AddOperation("*", 3, false, 2, ops->decorated_mul);
  AddOperation("/", 3, false, 2, ops->decorated_div);
  AddOperation("mod", 4, false, 2, ops->decorated_mod);
  AddOperation("^", 5, false, 2, ops->decorated_pow);
  AddOperation("sqrt", 6, false, 1, ops->decorated_sqrt);
  AddOperation("log", 6, false, 1, ops->decorated_log);
  AddOperation("ln", 6, false, 1, ops->decorated_ln);
  AddOperation("sin", 6, false, 1, ops->decorated_sin);
  AddOperation("cos", 6, false, 1, ops->decorated_cos);
  AddOperation("tan", 6, false, 1, ops->decorated_tan);
  AddOperation("asin", 6, false, 1, ops->decorated_asin);
  AddOperation("acos", 6, false, 1, ops->decorated_acos);
  AddOperation("atan", 6, false, 1, ops->decorated_atan);
  AddOperation("u+", 4, true, 1, ops->decorated_un_plus);
  AddOperation("u-", 4, true, 1, ops->decorated_un_minus);
  AddOperation("(", 1, false, 0);
  AddOperation(")", 1, false, 0);
}

OperatorMap::~OperatorMap() { delete ops; }

double OperatorMap::CalcOperation(const std::string &lexeme,
                                  const double value) {
  auto op = m_operators[lexeme];
  if (op.arg_num == 1) {
    return op.CallFunction<double>(value);
  } else
    throw std::runtime_error("The lexeme needs one argument");
}

double OperatorMap::CalcOperation(const std::string &lexeme,
                                  const double first_value,
                                  const double second_value) {
  auto op = m_operators[lexeme];
  if (op.arg_num == 2)
    return op.CallFunction<double, double>(first_value, second_value);
  else
    throw std::runtime_error("The lexeme needs two arguments");
}

std::regex OperatorMap::GetAllOperationsRegex() {
  std::string result = "^(";
  for (auto item = m_operators.begin(); item != m_operators.end(); ++item) {
    std::string temp_pat = escapeRegex(item->first);
    if (item != m_operators.end()) result += temp_pat + "|";
  }
  result.pop_back();
  result += ")$";
  return std::regex(result);
}

std::regex OperatorMap::GetFunctionOperationsRegex(
    const unsigned int &arg_num) {
  std::string result = "^(";
  for (auto item = m_operators.begin(); item != m_operators.end(); ++item) {
    std::string temp_pat = escapeRegex(item->first);
    if (item->second.arg_num == arg_num) {
      result += temp_pat + "|";
    }
  }
  result.pop_back();
  result += ")$";
  return std::regex(result);
}

std::regex OperatorMap::GetDualOperandRegex() {
  std::string result = "^(";
  for (auto item = m_operators.begin(); item != m_operators.end(); ++item) {
    std::string temp_pat = escapeRegex(item->first);
    if (item->second.arg_num == 2 && item->second.rang == 2) {
      result += temp_pat + "|";
    }
  }
  result.pop_back();
  result += ")$";
  return std::regex(result);
}

std::regex OperatorMap::GetUsualOperandRegex() {
  std::string result = "^(";
  for (auto item = m_operators.begin(); item != m_operators.end(); ++item) {
    std::string temp_pat = escapeRegex(item->first);
    if (item->second.arg_num == 2 && item->second.rang != 2) {
      result += temp_pat + "|";
    }
  }
  result.pop_back();
  result += ")$";
  return std::regex(result);
}

std::regex OperatorMap::GetBracketOperationsRegex(
    const std::string &bracket_str) {
  std::string result = "^(";
  for (auto item = m_operators.begin(); item != m_operators.end(); ++item) {
    if (item->first == bracket_str &&
        (bracket_str == "(" || bracket_str == ")")) {
      std::string temp_pat = escapeRegex(item->first);
      result += temp_pat;
    }
  }
  result += ")$";
  return std::regex(result);
}

std::string OperatorMap::escapeRegex(const std::string &input) {
  std::string result;
  for (char c : input) {
    if (c == '\\' || c == '.' || c == '*' || c == '+' || c == '?' || c == '(' ||
        c == ')' || c == '[' || c == ']' || c == '{' || c == '}' || c == '^' ||
        c == '$' || c == '|') {
      result += '\\';
    }
    result += c;
  }
  return result;
}

Operator &OperatorMap::GetOperatorByLexeme(const std::string &lexeme) {
  return m_operators[lexeme];
}
}  // namespace s21
