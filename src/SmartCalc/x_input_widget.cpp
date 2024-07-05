#include "x_input_widget.h"
#include "ui_x_input_widget.h"
#include <QDoubleValidator>
#include "../controller.h"

x_input_widget::x_input_widget(QWidget *parent, std::string input, QLineEdit *parent_line_edit, s21::Controller* controller) :
    QDialog(parent),
    parent_line_input(input),
    parent_line_edit(parent_line_edit),
    ui(new Ui::x_input_widget),
    controller(controller)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QDoubleValidator(this));
}

x_input_widget::~x_input_widget()
{
    delete ui;
}

void x_input_widget::on_pushButton_2_clicked()
{
    this->close();
}

void x_input_widget::on_pushButton_clicked()
{
    double xmax;
    if (ui->lineEdit->text().isEmpty())
        xmax = std::numeric_limits<double>::quiet_NaN();
    else
        xmax = ui->lineEdit->text().toDouble();
    
    std::string result = std::to_string(controller->DoubleCalculateVariableExpression(parent_line_input, xmax));
    QString resultAsString = QString::fromStdString(result);
    this->parent_line_edit->setText(resultAsString);
    this->close();
}

