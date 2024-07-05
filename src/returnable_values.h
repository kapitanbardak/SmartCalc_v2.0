#ifndef RETURNABLE_VALUES_H
#define RETURNABLE_VALUES_H
namespace s21 {
enum class ReturnableValues {
  kNormalValue = 0,
  kDivistionByZero,
  kPositiveInf,
  kNegativeInf,
  kNanValue
};
}  // namespace s21

#endif  // RETURNABLE_VALUES_H
