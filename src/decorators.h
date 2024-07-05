#ifndef DECORATORS_H
#define DECORATORS_H
#include <cmath>
#include <functional>
#include <stdexcept>
#include <tuple>
#include <utility>

namespace s21 {
template <typename... Args>
class Component {
 public:
  virtual double operation(Args...) = 0;
  virtual ~Component() = default;
};

template <typename... Args>
class ConcreteComponent : public Component<Args...> {
 private:
  std::function<double(Args...)> func_;

 public:
  ConcreteComponent(std::function<double(Args...)> func) : func_(func) {}
  double operation(Args... args) override { return func_(args...); }
};

template <typename... Args>
class Decorator : public Component<Args...> {
 protected:
  Component<Args...>* component_;

 public:
  Decorator(Component<Args...>* component) : component_(component) {}
  virtual double operation(Args... args) {
    return component_->operation(args...);
  }
};

template <typename... Args>
class DivideByZeroDecorator : public Decorator<Args...> {
 public:
  DivideByZeroDecorator(Component<Args...>* component)
      : Decorator<Args...>(component) {}
  double operation(Args... args) override {
    if (sizeof...(args) == 2 &&
        std::get<1>(std::forward_as_tuple(args...)) == 0) {
      throw std::runtime_error("Division by zero");
    }
    return Decorator<Args...>::operation(args...);
  }
};

template <typename... Args>
class NormalValueCheckDecorator : public Decorator<Args...> {
 public:
  NormalValueCheckDecorator(Component<Args...>* component)
      : Decorator<Args...>(component) {}
  double operation(Args... args) override {
    double value = Decorator<Args...>::operation(args...);
    if (std::isnan(value)) {
      throw std::domain_error("Error: NaN detected");
    }
    if (std::isinf(value) && value > 0) {
      throw std::domain_error("Error: Positive inf detected");
    }
    if (std::isinf(value) && value < 0) {
      throw std::domain_error("Error: Negative inf detected");
    }
    return value;
  }
};
}  // namespace s21
#endif  // DECORATORS_H
