#include "operations.h"

#include <cmath>

#include "decorators.h"

namespace s21 {
Operations::Operations() {
  component_add = new ConcreteComponent<double, double>(
      [](double a, double b) -> double { return a + b; });
  decorated_add = new NormalValueCheckDecorator<double, double>(component_add);

  component_sub = new ConcreteComponent<double, double>(
      [](double a, double b) -> double { return a - b; });
  decorated_sub = new NormalValueCheckDecorator<double, double>(component_sub);

  component_mul = new ConcreteComponent<double, double>(
      [](double a, double b) -> double { return a * b; });
  decorated_mul = new NormalValueCheckDecorator<double, double>(component_mul);

  component_div = new ConcreteComponent<double, double>(
      [](double a, double b) -> double { return a / b; });
  zero_check_div = new DivideByZeroDecorator<double, double>(component_div);
  decorated_div = new NormalValueCheckDecorator<double, double>(zero_check_div);

  component_mod = new ConcreteComponent<double, double>(
      [](double a, double b) -> double { return std::fmod(a, b); });
  zero_check_mod = new DivideByZeroDecorator<double, double>(component_mod);
  decorated_mod = new NormalValueCheckDecorator<double, double>(zero_check_mod);

  component_pow = new ConcreteComponent<double, double>(
      [](double a, double b) -> double { return std::pow(a, b); });
  decorated_pow = new NormalValueCheckDecorator<double, double>(component_pow);

  component_sqrt = new ConcreteComponent<double>(
      [](double a) -> double { return std::sqrt(a); });
  decorated_sqrt = new NormalValueCheckDecorator<double>(component_sqrt);

  component_log = new ConcreteComponent<double>(
      [](double a) -> double { return std::log10(a); });
  decorated_log = new NormalValueCheckDecorator<double>(component_log);

  component_ln = new ConcreteComponent<double>(
      [](double a) -> double { return std::log(a); });
  decorated_ln = new NormalValueCheckDecorator<double>(component_ln);

  component_sin = new ConcreteComponent<double>(
      [](double a) -> double { return std::sin(a); });
  decorated_sin = new NormalValueCheckDecorator<double>(component_sin);

  component_cos = new ConcreteComponent<double>(
      [](double a) -> double { return std::cos(a); });
  decorated_cos = new NormalValueCheckDecorator<double>(component_cos);

  component_tan = new ConcreteComponent<double>(
      [](double a) -> double { return std::tan(a); });
  decorated_tan = new NormalValueCheckDecorator<double>(component_tan);

  component_asin = new ConcreteComponent<double>(
      [](double a) -> double { return std::asin(a); });
  decorated_asin = new NormalValueCheckDecorator<double>(component_asin);

  component_acos = new ConcreteComponent<double>(
      [](double a) -> double { return std::acos(a); });
  decorated_acos = new NormalValueCheckDecorator<double>(component_acos);

  component_atan = new ConcreteComponent<double>(
      [](double a) -> double { return std::atan(a); });
  decorated_atan = new NormalValueCheckDecorator<double>(component_atan);

  component_un_plus =
      new ConcreteComponent<double>([](double a) -> double { return a; });
  decorated_un_plus = new NormalValueCheckDecorator<double>(component_un_plus);

  component_un_minus =
      new ConcreteComponent<double>([](double a) -> double { return -a; });
  decorated_un_minus =
      new NormalValueCheckDecorator<double>(component_un_minus);
}

Operations::~Operations() {
  delete component_add;
  delete decorated_add;
  delete component_sub;
  delete decorated_sub;
  delete component_mul;
  delete decorated_mul;
  delete component_div;
  delete zero_check_div;
  delete decorated_div;
  delete component_mod;
  delete zero_check_mod;
  delete decorated_mod;
  delete component_pow;
  delete decorated_pow;
  delete component_sqrt;
  delete decorated_sqrt;
  delete component_log;
  delete decorated_log;
  delete component_ln;
  delete decorated_ln;
  delete component_sin;
  delete decorated_sin;
  delete component_cos;
  delete decorated_cos;
  delete component_tan;
  delete decorated_tan;
  delete component_asin;
  delete decorated_asin;
  delete component_acos;
  delete decorated_acos;
  delete component_atan;
  delete decorated_atan;
  delete component_un_plus;
  delete decorated_un_plus;
  delete component_un_minus;
  delete decorated_un_minus;
}

}  // namespace s21
