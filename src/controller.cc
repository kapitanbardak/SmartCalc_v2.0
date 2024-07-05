#include "controller.h"

#include <QMainWindow>

#include "mainwindow.h"
#include "model.h"

namespace s21 {
Controller::Controller(QMainWindow *mainWindow) : _window(mainWindow) {
  _model = new Model();
}
std::string Controller::DoCalculationOnModel(std::string expression) {
  std::string result = _model->ValidateInput(expression);
  if (result != "Error") {
    if (!_model->NeedAdditionalInput) {
      return _model->CalculateNoVariableExpression();
    } else {
      dynamic_cast<MainWindow *>(_window)->ask_additional_input(expression);
    }
  }
  return result;
}

double Controller::DoubleCalculateVariableExpression(std::string str,
                                                     double x) {
  std::string result = _model->ValidateInput(str);
  if (result != "Error") {
    std::string result = _model->CalculateVariableExpression(std::to_string(x));
    if (result != "Error")
      return std::stod(result);
    else
      return NAN;
  }
  return 0;
}

}  // namespace s21
