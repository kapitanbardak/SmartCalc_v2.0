#ifndef PLOT_WIDGET_H
#define PLOT_WIDGET_H

#include <QVector>
#include <QDialog>
#include "../controller.h"

namespace Ui {
class plot_widget;
}

class plot_widget : public QDialog
{
    Q_OBJECT

public:
    plot_widget(QWidget *parent, QVector<double> *v_x, QVector<double> *v_y,
                         QString s, s21::Controller* controller);

    ~plot_widget();

    QVector<double> *qv_x;
    QVector<double> *qv_y;
    QString str;

private slots:
    void on_pushButton_plot_creater_clicked();

private:
    Ui::plot_widget *ui;
    void reject();

private:
    void add_point(double x, double y);
    void clear_data();
    void plot();
    s21::Controller* controller;
};

#endif // PLOT_WIDGET_H
