#ifndef X_INPUT_WIDGET_H
#define X_INPUT_WIDGET_H

#include <QDialog>
#include <QLineEdit>
#include "../controller.h"

namespace Ui {
class x_input_widget;
}

class x_input_widget : public QDialog
{
    Q_OBJECT

public:
    std::string parent_line_input;
    QLineEdit *parent_line_edit;

public:
    x_input_widget(QWidget *parent, std::string input, QLineEdit* parent_line_edit, s21::Controller* controller);
    ~x_input_widget();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::x_input_widget *ui;
    s21::Controller* controller;
};

#endif // X_INPUT_WIDGET_H
