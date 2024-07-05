#ifndef SRC_CONTROLLER_H
#define SRC_CONTROLLER_H

#include <string.h>

#include <QMainWindow>

#include "model.h"

namespace s21 {

class Controller {
 public:
  Controller(QMainWindow *mainWindow);
  std::string DoCalculationOnModel(std::string);
  double DoubleCalculateVariableExpression(std::string, double);

 private:
  QMainWindow *_window;
  s21::Model *_model;
};

}  // namespace s21

#endif  // SRC_CONTROLLER_H
