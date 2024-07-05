#include <gtest/gtest.h>

#include <iostream>

#include "model.h"

class TestModelCalculationResult1 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "7+8";
    model->ValidateInput(expr);
    result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult2 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "0.003 + 9";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult3 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "2,6+   0.4";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult4 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "2 6+   0.4";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult5 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "+   0.4";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult6 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "6+ ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult7 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "0+0";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult8 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "+ ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult9 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "5+6+3";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult10 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "0.003 - 9";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult11 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "2,6-   0.4";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult12 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "2 6-   0.4";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult13 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "-   0.4";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult14 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "6- ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult15 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "0-0";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult16 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "- ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult17 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "-(3) ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult18 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "-(-3) ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult19 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "0.003 * 9";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult20 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "2,6*   0.4";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult21 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "2 6*   0.4";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult22 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "*   0.4";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult23 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "6* ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult24 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "0*0";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult25 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "* ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult26 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "*(3) ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult27 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "5*(4*3) ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult28 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "0.003 / 9";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult29 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "2,6/   (-0.4)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult30 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "2 6/   0.4";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult31 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "/   0.4";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult32 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "6/ ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult33 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "0/0";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult34 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "/ ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult35 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "12.6/(3)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult36 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "5/(4/3) ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult37 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "5/4/3-0.75 ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult38 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "5-5/4/3";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult39 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "() ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult40 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "(";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult41 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "0.003 ^ 9";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult42 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "2,6^   (-0.4)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult43 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "2 6^   0.4";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult44 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "^   0.4";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult45 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "6^ ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult46 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "0^0";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult47 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "^ ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult48 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "12.6^3+2";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult49 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "2^3^2";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult50 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "(2^3)^2";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult51 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "4^(1/2)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult52 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "0.003 mod 9";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult53 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "2,6 mod   (+0.4)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult54 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "5 mod (-5)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult55 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "mod   0.4";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult56 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "6mod ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult57 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "0 mod 0";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult58 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "mod ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult59 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "12.6^3 mod 2";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult60 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "2 mod 3 mod 2";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult61 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "15 mod 6 mod 2";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult62 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "4 mod (1/2)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult63 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "cos(9)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult64 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "cos(-0)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult65 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "cos(5/3)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult66 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "cos";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult67 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "cos(-) ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult68 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "cos(100 mod (-3))";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult69 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "cos(3.14)^2";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult70 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "(cos(3.6)) mod (cos(8))";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult71 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "cos(cos(10))";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult72 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "cos(15 mod 6 mod 2)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult73 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "2^3*cos(3.14)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult74 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "sin(9)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult75 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "sin(-0)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult76 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "sin(5/3)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult77 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "siin";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult78 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "sin(5.36.5) ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult79 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "sin(100 mod 3)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult80 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "sin(3.14/2)^2";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult81 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "(sin(2.6)) mod (sin(8))";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult82 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "sin(sin(10))";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult83 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "sin(15 mod 6 mod 2)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult84 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "2^3*sin(3.14/2)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult85 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "tan(9)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult86 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "tan(-0)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult87 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "tan(5/3)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult88 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "tan";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult89 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "sin(5)^2+cos(5)^2 ";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult90 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "tan(100 mod 3)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult91 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "tan(3.14/2)^2";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult92 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "tan(4) mod sin(8)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult93 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "tan(sin(10))";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult94 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "tan(15 mod 6 mod 2)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult95 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "2^3*tan(3.14/2)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult96 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "acos(-3)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult97 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "acos(0.5)^2+asin(0.5)^2";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult98 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "acos(100 mod 3)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult99 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "acos(0)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult100 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "acos(sqrt(2)/2)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult101 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "acos(0.3) mod acos(0.3)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult102 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "ASIN(-3)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult103 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "asin(0.5)^2+asin(0.5)^2";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult104 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "asin(100 mod 3)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult105 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "asin(0)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult106 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "asin(sqrt(2)/2)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult107 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "asin(0.3) mod acos(0.3)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult108 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "atan(-3)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult109 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "atan(0.5)^2+asin(0.5)^2";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult110 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "atan(100 mod 3)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult111 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "atan(0)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult112 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "atan(sqrt(2)/2)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult113 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "atan(0.3) mod acos(0.3)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult114 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "sqrt(-3)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult115 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "sqrt(5)^2";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult116 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "sqrt(100) mod 3";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult117 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "sqrt(0)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult118 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "sqrt(sqrt(2)/2+2.6)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult119 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "ln(-3)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult120 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "ln(-0)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult121 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "ln(2.71828182845904523536)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult122 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "ln(0.6)^2";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult123 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "sqrt(ln(2)/2+2.6)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult124 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "sin(asin(0.3))";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult125 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "cos(acos(0.6))";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult126 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "log(-3)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult127 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "log(-0)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult128 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "log(10 + 0.0000001)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult129 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "log(0.6)^2";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult130 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "sqrt(log(9 mod 5)/2+2.6)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult131 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "sqrt(log(9 mod x)/2+2.6)";
    x = "5";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateVariableExpression(x);
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
  std::string x;
};

class TestModelCalculationResult132 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "log(10 + x)";
    x = "0.0000001";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateVariableExpression(x);
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
  std::string x;
};

class TestModelCalculationResult133 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "x";
    x = "5";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateVariableExpression(x);
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
  std::string x;
};

class TestModelCalculationResult134 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr =
        "15/(7-(1+x))*3-(2+(1+x))*15/(7-(200+x))*3-(2+(1+x))*(15/(7-(1+1))*3"
        "-(x+(1+1))+15/(7-(1+1))*x-(2+(1+1)))";
    x = "3.2";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateVariableExpression(x);
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
  std::string x;
};

class TestModelCalculationResult135 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "(cos(-2^4)^2)*5/3+(ln(sqrt(+25))-(sin(-4)))";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult136 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "(-cos(-2^4)^2)*5/3+(ln(sqrt(25))-(sin(-4)))";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult137 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "sin(sin(10)";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

class TestModelCalculationResult138 : public ::testing::Test {
 protected:
  void SetUp() {
    model = new s21::Model();
    expr = "sin(sin(+-10))";
    result = model->ValidateInput(expr);
    if (result != "Error") result = model->CalculateNoVariableExpression();
  }

  void TearDown() { delete model; }

  s21::Model *model;
  std::string result;
  std::string expr;
};

TEST_F(TestModelCalculationResult1, test1) { ASSERT_EQ(result, "15.000000"); }

TEST_F(TestModelCalculationResult2, test2) { ASSERT_EQ(result, "9.003000"); }

TEST_F(TestModelCalculationResult3, test3) { ASSERT_EQ(result, "3.000000"); }

TEST_F(TestModelCalculationResult4, test4) { ASSERT_EQ(result, "26.400000"); }

TEST_F(TestModelCalculationResult5, test5) { ASSERT_EQ(result, "0.400000"); }

TEST_F(TestModelCalculationResult6, test6) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult7, test7) { ASSERT_EQ(result, "0.000000"); }

TEST_F(TestModelCalculationResult8, test8) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult9, test9) { ASSERT_EQ(result, "14.000000"); }

TEST_F(TestModelCalculationResult10, test10) { ASSERT_EQ(result, "-8.997000"); }

TEST_F(TestModelCalculationResult11, test11) { ASSERT_EQ(result, "2.200000"); }

TEST_F(TestModelCalculationResult12, test12) { ASSERT_EQ(result, "25.600000"); }

TEST_F(TestModelCalculationResult13, test13) { ASSERT_EQ(result, "-0.400000"); }

TEST_F(TestModelCalculationResult14, test14) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult15, test15) { ASSERT_EQ(result, "0.000000"); }

TEST_F(TestModelCalculationResult16, test16) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult17, test17) { ASSERT_EQ(result, "-3.000000"); }

TEST_F(TestModelCalculationResult18, test18) { ASSERT_EQ(result, "3.000000"); }

TEST_F(TestModelCalculationResult19, test19) { ASSERT_EQ(result, "0.027000"); }

TEST_F(TestModelCalculationResult20, test20) { ASSERT_EQ(result, "1.040000"); }

TEST_F(TestModelCalculationResult21, test21) { ASSERT_EQ(result, "10.400000"); }

TEST_F(TestModelCalculationResult22, test22) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult23, test23) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult24, test24) { ASSERT_EQ(result, "0.000000"); }

TEST_F(TestModelCalculationResult25, test25) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult26, test26) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult27, test27) { ASSERT_EQ(result, "60.000000"); }

TEST_F(TestModelCalculationResult28, test28) { ASSERT_EQ(result, "0.000333"); }

TEST_F(TestModelCalculationResult29, test29) { ASSERT_EQ(result, "-6.500000"); }

TEST_F(TestModelCalculationResult30, test30) { ASSERT_EQ(result, "65.000000"); }

TEST_F(TestModelCalculationResult31, test31) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult32, test32) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult33, test33) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult34, test34) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult35, test35) { ASSERT_EQ(result, "4.200000"); }

TEST_F(TestModelCalculationResult36, test36) { ASSERT_EQ(result, "3.750000"); }

TEST_F(TestModelCalculationResult37, test37) { ASSERT_EQ(result, "-0.333333"); }

TEST_F(TestModelCalculationResult38, test38) { ASSERT_EQ(result, "4.583333"); }

TEST_F(TestModelCalculationResult39, test39) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult40, test40) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult41, test41) { ASSERT_EQ(result, "0.000000"); }

TEST_F(TestModelCalculationResult42, test42) { ASSERT_EQ(result, "0.682355"); }

TEST_F(TestModelCalculationResult43, test43) { ASSERT_EQ(result, "3.681199"); }

TEST_F(TestModelCalculationResult44, test44) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult45, test45) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult46, test46) { ASSERT_EQ(result, "1.000000"); }

TEST_F(TestModelCalculationResult47, test47) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult48, test48) {
  ASSERT_EQ(result, "2002.376000");
}

TEST_F(TestModelCalculationResult49, test49) { ASSERT_EQ(result, "64.000000"); }

TEST_F(TestModelCalculationResult50, test50) { ASSERT_EQ(result, "64.000000"); }

TEST_F(TestModelCalculationResult51, test51) { ASSERT_EQ(result, "2.000000"); }

TEST_F(TestModelCalculationResult52, test52) { ASSERT_EQ(result, "0.003000"); }

TEST_F(TestModelCalculationResult53, test53) { ASSERT_EQ(result, "0.200000"); }

TEST_F(TestModelCalculationResult54, test54) { ASSERT_EQ(result, "0.000000"); }

TEST_F(TestModelCalculationResult55, test55) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult56, test56) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult57, test57) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult58, test58) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult59, test59) { ASSERT_EQ(result, "0.376000"); }

TEST_F(TestModelCalculationResult60, test60) { ASSERT_EQ(result, "0.000000"); }

TEST_F(TestModelCalculationResult61, test61) { ASSERT_EQ(result, "1.000000"); }

TEST_F(TestModelCalculationResult62, test62) { ASSERT_EQ(result, "0.000000"); }

TEST_F(TestModelCalculationResult63, test63) { ASSERT_EQ(result, "-0.911130"); }

TEST_F(TestModelCalculationResult64, test64) { ASSERT_EQ(result, "1.000000"); }

TEST_F(TestModelCalculationResult65, test65) { ASSERT_EQ(result, "-0.095724"); }

TEST_F(TestModelCalculationResult66, test66) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult67, test67) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult68, test68) { ASSERT_EQ(result, "0.540302"); }

TEST_F(TestModelCalculationResult69, test69) { ASSERT_EQ(result, "0.999997"); }

TEST_F(TestModelCalculationResult70, test70) { ASSERT_EQ(result, "-0.023758"); }

TEST_F(TestModelCalculationResult71, test71) { ASSERT_EQ(result, "0.668154"); }

TEST_F(TestModelCalculationResult72, test72) { ASSERT_EQ(result, "0.540302"); }

TEST_F(TestModelCalculationResult73, test73) { ASSERT_EQ(result, "-7.999990"); }

TEST_F(TestModelCalculationResult74, test74) { ASSERT_EQ(result, "0.412118"); }

TEST_F(TestModelCalculationResult75, test75) { ASSERT_EQ(result, "0.000000"); }

TEST_F(TestModelCalculationResult76, test76) { ASSERT_EQ(result, "0.995408"); }

TEST_F(TestModelCalculationResult77, test77) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult78, test78) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult79, test79) { ASSERT_EQ(result, "0.841471"); }

TEST_F(TestModelCalculationResult80, test80) { ASSERT_EQ(result, "0.999999"); }

TEST_F(TestModelCalculationResult81, test81) { ASSERT_EQ(result, "0.515501"); }

TEST_F(TestModelCalculationResult82, test82) { ASSERT_EQ(result, "-0.517581"); }

TEST_F(TestModelCalculationResult83, test83) { ASSERT_EQ(result, "0.841471"); }

TEST_F(TestModelCalculationResult84, test84) { ASSERT_EQ(result, "7.999997"); }

TEST_F(TestModelCalculationResult85, test85) { ASSERT_EQ(result, "-0.452316"); }

TEST_F(TestModelCalculationResult86, test86) { ASSERT_EQ(result, "0.000000"); }

TEST_F(TestModelCalculationResult87, test87) {
  ASSERT_EQ(result, "-10.398778");
}

TEST_F(TestModelCalculationResult88, test88) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult89, test89) { ASSERT_EQ(result, "1.000000"); }

TEST_F(TestModelCalculationResult90, test90) { ASSERT_EQ(result, "1.557408"); }

TEST_F(TestModelCalculationResult91, test91) {
  ASSERT_EQ(result, "1576947.220797");
}

TEST_F(TestModelCalculationResult92, test92) { ASSERT_EQ(result, "0.168463"); }

TEST_F(TestModelCalculationResult93, test93) { ASSERT_EQ(result, "-0.604909"); }

TEST_F(TestModelCalculationResult94, test94) { ASSERT_EQ(result, "1.557408"); }

TEST_F(TestModelCalculationResult95, test95) {
  ASSERT_EQ(result, "10046.124732");
}

TEST_F(TestModelCalculationResult96, test96) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult97, test97) { ASSERT_EQ(result, "1.370778"); }

TEST_F(TestModelCalculationResult98, test98) { ASSERT_EQ(result, "0.000000"); }

TEST_F(TestModelCalculationResult99, test99) { ASSERT_EQ(result, "1.570796"); }

TEST_F(TestModelCalculationResult100, test100) {
  ASSERT_EQ(result, "0.785398");
}

TEST_F(TestModelCalculationResult101, test101) {
  ASSERT_EQ(result, "0.000000");
}

TEST_F(TestModelCalculationResult102, test102) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult103, test103) {
  ASSERT_EQ(result, "0.548311");
}

TEST_F(TestModelCalculationResult104, test104) {
  ASSERT_EQ(result, "1.570796");
}

TEST_F(TestModelCalculationResult105, test105) {
  ASSERT_EQ(result, "0.000000");
}

TEST_F(TestModelCalculationResult106, test106) {
  ASSERT_EQ(result, "0.785398");
}

TEST_F(TestModelCalculationResult107, test107) {
  ASSERT_EQ(result, "0.304693");
}

TEST_F(TestModelCalculationResult108, test108) {
  ASSERT_EQ(result, "-1.249046");
}

TEST_F(TestModelCalculationResult109, test109) {
  ASSERT_EQ(result, "0.489125");
}

TEST_F(TestModelCalculationResult110, test110) {
  ASSERT_EQ(result, "0.785398");
}

TEST_F(TestModelCalculationResult111, test111) {
  ASSERT_EQ(result, "0.000000");
}

TEST_F(TestModelCalculationResult112, test112) {
  ASSERT_EQ(result, "0.615480");
}

TEST_F(TestModelCalculationResult113, test113) {
  ASSERT_EQ(result, "0.291457");
}

TEST_F(TestModelCalculationResult114, test114) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult115, test115) {
  ASSERT_EQ(result, "5.000000");
}

TEST_F(TestModelCalculationResult116, test116) {
  ASSERT_EQ(result, "1.000000");
}

TEST_F(TestModelCalculationResult117, test117) {
  ASSERT_EQ(result, "0.000000");
}

TEST_F(TestModelCalculationResult118, test118) {
  ASSERT_EQ(result, "1.818545");
}

TEST_F(TestModelCalculationResult119, test119) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult120, test120) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult121, test121) {
  ASSERT_EQ(result, "1.000000");
}

TEST_F(TestModelCalculationResult122, test122) {
  ASSERT_EQ(result, "0.260943");
}

TEST_F(TestModelCalculationResult123, test123) {
  ASSERT_EQ(result, "1.716559");
}

TEST_F(TestModelCalculationResult124, test124) {
  ASSERT_EQ(result, "0.300000");
}

TEST_F(TestModelCalculationResult125, test125) {
  ASSERT_EQ(result, "0.600000");
}

TEST_F(TestModelCalculationResult126, test126) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult127, test127) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult128, test128) {
  ASSERT_EQ(result, "1.000000");
}

TEST_F(TestModelCalculationResult129, test129) {
  ASSERT_EQ(result, "0.049217");
}

TEST_F(TestModelCalculationResult130, test130) {
  ASSERT_EQ(result, "1.703241");
}

TEST_F(TestModelCalculationResult131, test131) {
  ASSERT_EQ(result, "1.703241");
}

TEST_F(TestModelCalculationResult132, test132) {
  ASSERT_EQ(result, "1.000000");
}

TEST_F(TestModelCalculationResult133, test133) {
  ASSERT_EQ(result, "5.000000");
}

TEST_F(TestModelCalculationResult134, test134) {
  ASSERT_EQ(result, "-40.786553");
}

TEST_F(TestModelCalculationResult135, test135) {
  ASSERT_EQ(result, "2.381155");
}

TEST_F(TestModelCalculationResult136, test136) {
  ASSERT_EQ(result, "-0.675884");
}

TEST_F(TestModelCalculationResult137, test137) { ASSERT_EQ(result, "Error"); }

TEST_F(TestModelCalculationResult138, test138) { ASSERT_EQ(result, "Error"); }

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}