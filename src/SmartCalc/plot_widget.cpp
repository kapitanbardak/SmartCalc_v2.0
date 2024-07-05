#include "plot_widget.h"
#include "ui_plot_widget.h"
#include <QDoubleValidator>
#include <QCloseEvent>

plot_widget::plot_widget(QWidget *parent, QVector<double>* v_x, QVector<double>* v_y, QString s, s21::Controller* controller) :
    QDialog(parent),
    qv_x(v_x),
    qv_y(v_y),
    str(s),
    ui(new Ui::plot_widget),
    controller(controller)
{
    ui->setupUi(this);
    ui->plot->hide();
    ui->lineEdit_x_min->setValidator(new QDoubleValidator(this));
    ui->lineEdit_x_max->setValidator(new QDoubleValidator(this));
    ui->lineEdit_y_min->setValidator(new QDoubleValidator(this));
    ui->lineEdit_y_max->setValidator(new QDoubleValidator(this));

    ui->plot->addGraph();
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsNone);
}

plot_widget::~plot_widget()
{
    delete ui;
}

void plot_widget::reject()
{
    this->qv_x->clear();
    this->qv_y->clear();
    QDialog::reject();
}

void plot_widget::add_point(double x, double y)
{
    qv_x->append(x);
    qv_y->append(y);
}

void plot_widget::clear_data()
{
    qv_x->clear();
    qv_y->clear();
}

void plot_widget::plot()
{
    ui->plot->show();
    ui->plot->graph(0)->setData(*qv_x, *qv_y);
    ui->plot->replot();
    ui->plot->update();
}

void plot_widget::on_pushButton_plot_creater_clicked()
{
    double step_x;
    double x_min, x_max, y_min, y_max;
    if (ui->lineEdit_x_min->text().isEmpty())
        x_min = std::numeric_limits<double>::quiet_NaN();
    else
        x_min = ui->lineEdit_x_min->text().toDouble();
    if (ui->lineEdit_x_max->text().isEmpty())
        x_max = std::numeric_limits<double>::quiet_NaN();
    else
        x_max = ui->lineEdit_x_max->text().toDouble();
    if (ui->lineEdit_y_min->text().isEmpty())
        y_min = std::numeric_limits<double>::quiet_NaN();
    else
        y_min = ui->lineEdit_y_min->text().toDouble();
    if (ui->lineEdit_y_max->text().isEmpty())
        y_max = std::numeric_limits<double>::quiet_NaN();
    else
        y_max = ui->lineEdit_x_max->text().toDouble();

    if (x_min > -1000000 && x_min < 1000000 &&
    y_min > -1000000 && y_min < 1000000 &&
    y_max > -1000000 && y_max < 1000000 &&
    x_max > -1000000 && x_max < 1000000 &&
    x_min < x_max && y_min < y_max) {
        step_x = (fabs(x_max - x_min)) / 9999;
        ui->plot->xAxis->setRange(x_min, x_max);
        ui->plot->yAxis->setRange(y_min, y_max);

        while (x_min < x_max) {
            double y = controller->DoubleCalculateVariableExpression(str.toLocal8Bit().data(), x_min);
            if (!isnan(y))
                this->add_point(x_min, y);
            x_min += step_x;
        }
        this->plot();
        ui->plot->setInteraction(QCP::iRangeZoom, true);
        ui->plot->setInteraction(QCP::iRangeDrag, true);
    }
}

