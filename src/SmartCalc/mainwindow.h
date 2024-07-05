#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include "../controller.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void ask_additional_input(std::string);
    QVector<double> qv_x, qv_y;
    s21::Controller *controller;

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_x_clicked();

    void on_pushButton_dot_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_sub_clicked();

    void on_pushButton_mul_clicked();

    void on_pushButton_div_clicked();

    void on_pushButton_close_bracket_clicked();

    void on_pushButton_open_bracket_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_backspace_clicked();

    void on_pushButton_mod_clicked();

    void on_pushButton_pi_clicked();

    void on_pushButton_exp_clicked();

    void on_pushButton_pow_clicked();

    void on_pushButton_sqrt_clicked();

    void on_pushButton_ln_clicked();

    void on_pushButton_log_clicked();

    void on_pushButton_sin_clicked();

    void on_pushButton_cos_clicked();

    void on_pushButton_tan_clicked();

    void on_pushButton_asin_clicked();

    void on_pushButton_acos_clicked();

    void on_pushButton_atan_clicked();

    void on_last_input_clicked();

    void on_pushButton_smart_calc_clicked();

    void on_pushButton_graph_clicked();

    void on_pushButton_credit_calculation_clicked();

    void on_pushButton_deposit_calculation_clicked();

private:
    Ui::MainWindow *ui;
    QDate getNextDate(/*QDate *startDate, int n, int comboBox*/);
    void setVisibleDepositLabel(const bool visible);

signals:
  void signal(QString);
};
#endif // MAINWINDOW_H
