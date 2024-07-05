#ifndef OPERATIONS_H
#define OPERATIONS_H
#include "decorators.h"
namespace s21 {
class Operations {
 public:
  Operations();
  ~Operations();
  Component<double, double>* decorated_add;
  Component<double, double>* decorated_sub;
  Component<double, double>* decorated_mul;
  Component<double, double>* decorated_div;
  Component<double, double>* decorated_mod;
  Component<double, double>* decorated_pow;
  Component<double>* decorated_sqrt;
  Component<double>* decorated_log;
  Component<double>* decorated_ln;
  Component<double>* decorated_sin;
  Component<double>* decorated_cos;
  Component<double>* decorated_tan;
  Component<double>* decorated_asin;
  Component<double>* decorated_acos;
  Component<double>* decorated_atan;
  Component<double>* decorated_un_plus;
  Component<double>* decorated_un_minus;

 private:
  Component<double, double>* component_add;
  Component<double, double>* component_sub;
  Component<double, double>* component_mul;
  Component<double, double>* zero_check_div;
  Component<double, double>* component_div;
  Component<double, double>* zero_check_mod;
  Component<double, double>* component_mod;
  Component<double, double>* component_pow;
  Component<double>* component_sqrt;
  Component<double>* component_log;
  Component<double>* component_ln;
  Component<double>* component_sin;
  Component<double>* component_cos;
  Component<double>* component_tan;
  Component<double>* component_asin;
  Component<double>* component_acos;
  Component<double>* component_atan;
  Component<double>* component_un_plus;
  Component<double>* component_un_minus;
};
}  // namespace s21

#endif  // OPERATIONS_H
