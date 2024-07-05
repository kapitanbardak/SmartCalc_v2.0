#include "mainwindow.h"
#include "plot_widget.h"
#include "x_input_widget.h"
#include "ui_mainwindow.h"
#include <cstring>
#include <QDate>
#include "../controller.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui = new Ui::MainWindow;
    ui->setupUi(this);
    controller = new s21::Controller(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_1_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "1");
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "2");
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "3");
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "4");
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "5");
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "6");
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "7");
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "8");
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "9");
}

void MainWindow::on_pushButton_0_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "0");
}

void MainWindow::on_pushButton_x_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "x");
}

void MainWindow::on_pushButton_dot_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + ".");
}

void MainWindow::on_pushButton_add_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "+");
}

void MainWindow::on_pushButton_sub_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "-");
}

void MainWindow::on_pushButton_mul_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "*");
}

void MainWindow::on_pushButton_div_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "/");
}

void MainWindow::on_pushButton_close_bracket_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + ")");
}

void MainWindow::on_pushButton_open_bracket_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "(");
}

void MainWindow::on_pushButton_clear_clicked()
{
    QString line = ui->lineEdit_input->text();
    line.chop(1);
    ui->lineEdit_input->setText(line);
}

void MainWindow::on_pushButton_backspace_clicked()
{
    ui->lineEdit_input->clear();
}

void MainWindow::on_pushButton_mod_clicked()
{
   ui->lineEdit_input->setText(ui->lineEdit_input->text() + " mod ");
}

void MainWindow::on_pushButton_pi_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "pi");
}

void MainWindow::on_pushButton_exp_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "exp");
}

void MainWindow::on_pushButton_pow_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "^");
}

void MainWindow::on_pushButton_sqrt_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "sqrt(");
}

void MainWindow::on_pushButton_ln_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "ln(");
}

void MainWindow::on_pushButton_log_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "log(");
}

void MainWindow::on_pushButton_sin_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "sin(");
}

void MainWindow::on_pushButton_cos_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "cos(");
}

void MainWindow::on_pushButton_tan_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "tan(");
}

void MainWindow::on_pushButton_asin_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "asin(");
}

void MainWindow::on_pushButton_acos_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "acos(");
}

void MainWindow::on_pushButton_atan_clicked()
{
    ui->lineEdit_input->setText(ui->lineEdit_input->text() + "atan(");
}

void MainWindow::on_last_input_clicked()
{
    ui->lineEdit_input->setText(ui->last_input->text());
    ui->last_input->setText("");
}

void MainWindow::on_pushButton_smart_calc_clicked()
{
    QString str = ui->lineEdit_input->text();
    ui->last_input->setText(str);
    std::string result;
    result = controller->DoCalculationOnModel(str.toLocal8Bit().data());
    QString resultAsString = QString::fromStdString(result);
    ui->lineEdit_input->setText(resultAsString);

}

void MainWindow::ask_additional_input(std::string input) {
    x_input_widget* x_input = new x_input_widget(this, input, ui->lineEdit_input, controller);
    x_input->show();
}


void MainWindow::on_pushButton_graph_clicked()
{
    plot_widget* plot = new plot_widget(this, &(this->qv_x), &(this->qv_y), ui->lineEdit_input->text(), controller);
    plot->show();
}


void MainWindow::on_pushButton_credit_calculation_clicked()
{
//    double credit_amount = ui->doubleSpinBox_credit_amount->value();
//    int loan_period = ui->spinBox_moths->value();
//    double rate = ui->doubleSpinBox_rate->value();
//    int annuity = ui->radioButton_annuity->isChecked();
//    char monthly_payment[999];
//    char overpay[999];
//    char total_payments[999];
//    int result = credit(credit_amount, loan_period, rate, annuity, monthly_payment, overpay, total_payments);
//    if (result) {
//        ui->lineEdit_overpayment->setText(QString(overpay));
//        ui->lineEdit_monthly_payment->setText(QString(monthly_payment));
//        ui->lineEdit_total_payment->setText(QString(total_payments));
//        ui->label_monthly_payment->show();
//        ui->label_overpayment->show();
//        ui->label_total_payment->show();
//        ui->lineEdit_overpayment->show();
//        ui->lineEdit_total_payment->show();
//        ui->lineEdit_monthly_payment->show();
//    } else {
//        ui->label_monthly_payment->hide();
//        ui->label_overpayment->hide();
//        ui->label_total_payment->hide();
//        ui->lineEdit_overpayment->hide();
//        ui->lineEdit_total_payment->hide();
//        ui->lineEdit_monthly_payment->hide();
//    }

}

QDate MainWindow::getNextDate(/*QDate *startDate, int n, int comboBox*/) {
//    QDate paymentDate;
//    switch (comboBox) {
//    case 0:
//        paymentDate = startDate->addDays(n);
//        break;
//    case 1:
//        paymentDate = startDate->addDays(n * 7);
//        break;
//    case 2:
//        paymentDate = startDate->addMonths(n);
//        break;
//    case 3:
//        paymentDate = startDate->addMonths(n * 3);
//        break;
//    case 4:
//        paymentDate = startDate->addMonths(n * 6);
//        break;
//    case 5:
//        paymentDate = startDate->addYears(n);
//        break;
//    case 6:
//        paymentDate = startDate->addYears(99999);
//        break;
//    }
//    return paymentDate;
return QDate::currentDate();
}

void MainWindow::on_pushButton_deposit_calculation_clicked()
{
//    int amount = ui->spinBox_deposit->value(), n = ui->spinBox_termDeposit->value();
//    int nPayment = 1, daysPayment = 0, nReplenishments = 1, nWithdrawals = 1;
//    if ((amount > 0) && (n > 0)) {
//        int pymentsTerm = ui->comboBox_payments->currentIndex(),
//                replenishmentsTerm = ui->comboBox_replenishments->currentIndex(),
//                withdrawalsTerm = ui->comboBox_withdrawals->currentIndex();
//        QDate startDate = ui->dateEdit_start->date();
//        QDate finishDate = getNextDate(&startDate, n, pymentsTerm), currentDate = startDate;
//        QDate paymentDate = getNextDate(&startDate, nPayment, pymentsTerm),
//                replenishmentsDate = getNextDate(&startDate, nReplenishments, replenishmentsTerm),
//                withdrawalsDate = getNextDate(&startDate, nWithdrawals, withdrawalsTerm);
//        double deposit = amount, minDeposit = amount, interest = 0, interestAll = 0;
//        double interestPerDay = ui->doubleSpinBox_deposit_rate->value() / 100 / startDate.daysInYear();
//        double  withdraw = ui->spinBox_withdrawals->value(), repleishment = ui->spinBox_replenishments->value();
//        do {
//            currentDate = currentDate.addDays(1);
//            if (currentDate > paymentDate) {
//                double interestCurrent;
//                if (ui->checkBox_capitalization->isChecked()) {
//                    interestCurrent = floor((minDeposit + interest) * interestPerDay * daysPayment * 100) / 100;
//                } else {
//                    interestCurrent = floor(minDeposit * interestPerDay * daysPayment * 100) / 100;
//                }
//                interest += interestCurrent, interestAll += interestCurrent, daysPayment = 0, minDeposit = deposit;
//                paymentDate = getNextDate(&startDate, ++nPayment, pymentsTerm);
//            }
//            if (withdraw > 0 && currentDate > withdrawalsDate) {
//                double withdrawTmp = withdraw;
//                if (interest > withdrawTmp) {
//                    interest -= withdrawTmp;
//                } else {
//                    withdrawTmp -= interest, interest = 0;
//                    if (withdrawTmp >= deposit) {
//                        deposit = 0;
//                    } else {
//                        deposit -= withdrawTmp;
//                    }
//                    minDeposit = deposit;
//                }
//                withdrawalsDate = getNextDate(&startDate, ++nWithdrawals, withdrawalsTerm);
//            }
//            if (repleishment > 0 && currentDate > replenishmentsDate) {
//                deposit += repleishment;
//                replenishmentsDate = getNextDate(&startDate, ++nReplenishments, replenishmentsTerm);
//            }
//            daysPayment++;
//        } while (currentDate <= finishDate);
//        ui->label_interest->setText("Accrued interest: " + QString::number(interestAll, 'f', 2));
//        ui->label_deposit->setText("Deposit amount by the end of the term: " + QString::number(interest + deposit, 'f', 2));

//        setVisibleDepositLabel(true);
//    } else {
//        setVisibleDepositLabel(false);
//    }
}

void MainWindow::setVisibleDepositLabel(const bool visible) {
    ui->groupBox_result->setVisible(visible);
}

