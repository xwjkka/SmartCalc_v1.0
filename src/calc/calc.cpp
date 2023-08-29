#include "calc.h"
#include "./ui_calc.h"
extern "C" {
    #include "../s21_calc.h"
}
extern "C" {
    #include "../s21_credit.h"
}


calc::calc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calc)

{
    ui->setupUi(this);
    ui->lineEdit->setMaxLength(256);
    memset(buff, 0, 256);
    index = 0;
    memset(output, 0, 256);
    res = 0;
    memset(count_len, 0, 256);
    ann = 0;
    dif = 0;
}

calc::~calc()
{
    delete ui;
}

void calc::countLen()
{
    if (index <= 255) {
        sprintf(count_len, "%d/255", index);
        ui->lineEdit_2->setText(count_len);
    } else {
        sprintf(count_len, "%d/255", 255);
        ui->lineEdit_2->setText(count_len);
    }
}

// numbers
void calc::on_pushButton_0_clicked()
{
    no_error();
    buff[index++] = '0';
    ui->lineEdit->setText(buff);
    countLen();
}


void calc::on_pushButton_1_clicked()
{
    no_error();
    buff[index++] = '1';
    ui->lineEdit->setText(buff);
    countLen();
}

void calc::on_pushButton_2_clicked()
{
    no_error();
    buff[index++] = '2';
    ui->lineEdit->setText(buff);
    countLen();
}

void calc::on_pushButton_3_clicked()
{
    no_error();
    buff[index++] = '3';
    ui->lineEdit->setText(buff);
    countLen();
}

void calc::on_pushButton_4_clicked()
{
    no_error();
    buff[index++] = '4';
    ui->lineEdit->setText(buff);
    countLen();
}

void calc::on_pushButton_5_clicked()
{
    no_error();
    buff[index++] = '5';
    ui->lineEdit->setText(buff);
    countLen();
}

void calc::on_pushButton_6_clicked()
{
    no_error();
    buff[index++] = '6';
    ui->lineEdit->setText(buff);
   countLen();
}
void calc::on_pushButton_7_clicked()
{
    no_error();
    buff[index++] = '7';
    ui->lineEdit->setText(buff);
    countLen();
 }

void calc::on_pushButton_8_clicked()
{
    no_error();
    buff[index++] = '8';
    ui->lineEdit->setText(buff);
    countLen();
 }

void calc::on_pushButton_9_clicked()
{
    no_error();
    buff[index++] = '9';
    ui->lineEdit->setText(buff);
    countLen();
 }

// operators
void calc::on_pushButton_div_clicked()
{
    no_error();
    buff[index++] = '/';
    ui->lineEdit->setText(buff);
    countLen();
 }

void calc::on_pushButton_mul_clicked()
{
    no_error();
    buff[index++] = '*';
    ui->lineEdit->setText(buff);
    countLen();
 }

void calc::on_pushButton_plus_clicked()
{
    no_error();
    buff[index++] = '+';
    ui->lineEdit->setText(buff);
    countLen();
 }


void calc::on_pushButton_minus_clicked()
{
    no_error();
    buff[index++] = '-';
    ui->lineEdit->setText(buff);
    countLen();
 }

//func

void calc::on_pushButton_open_bracket_clicked()
{
    no_error();
    buff[index++] = '(';
    ui->lineEdit->setText(buff);
    countLen();
 }


void calc::on_pushButton_close_bracket_clicked()
{
    no_error();
    buff[index++] = ')';
    ui->lineEdit->setText(buff);
    countLen();
 }


void calc::on_pushButton_point_clicked()
{
    no_error();
    buff[index++] = '.';
    ui->lineEdit->setText(buff);
    countLen();
 }


void calc::on_pushButton_x_clicked()
{
    no_error();
    buff[index++] = 'x';
    ui->lineEdit->setText(buff);
    countLen();
 }


void calc::on_pushButton_pow_clicked()
{
    no_error();
    buff[index++] = '^';
    ui->lineEdit->setText(buff);
    countLen();
 }


void calc::on_pushButton_clear_clicked()
{
    no_error();
    ui->lineEdit->clear();
    memset(buff, 0, index);
    index = 0;
//    if (index > 0) {
//        buff[--index] = 0;
//        ui->lineEdit->setText(buff);
//    }
    countLen();
 }


void calc::on_pushButton_cos_clicked()
{
    no_error();
    buff[index++] = 'c';
    buff[index++] = 'o';
    buff[index++] = 's';
    buff[index++] = '(';
    ui->lineEdit->setText(buff);
    countLen();
 }


void calc::on_pushButton_sin_clicked()
{
    no_error();
    buff[index++] = 's';
    buff[index++] = 'i';
    buff[index++] = 'n';
    buff[index++] = '(';
    ui->lineEdit->setText(buff);
    countLen();
 }


void calc::on_pushButton_sqrt_clicked()
{
    no_error();
    buff[index++] = 's';
    buff[index++] = 'q';
    buff[index++] = 'r';
    buff[index++] = 't';
    buff[index++] = '(';
    ui->lineEdit->setText(buff);
    countLen();
 }


void calc::on_pushButton_tan_clicked()
{
    no_error();
    buff[index++] = 't';
    buff[index++] = 'a';
    buff[index++] = 'n';
    buff[index++] = '(';
    ui->lineEdit->setText(buff);
    countLen();
 }


void calc::on_pushButton_ln_clicked()
{
    no_error();
    buff[index++] = 'l';
    buff[index++] = 'n';
    buff[index++] = '(';
    ui->lineEdit->setText(buff);
    countLen();
 }


void calc::on_pushButton_acos_clicked()
{
    no_error();
    buff[index++] = 'a';
    buff[index++] = 'c';
    buff[index++] = 'o';
    buff[index++] = 's';
    buff[index++] = '(';
    ui->lineEdit->setText(buff);
    countLen();
 }


void calc::on_pushButton_log_clicked()
{
    no_error();
    buff[index++] = 'l';
    buff[index++] = 'o';
    buff[index++] = 'g';
    buff[index++] = '(';
    ui->lineEdit->setText(buff);
    countLen();
 }


void calc::on_pushButton_asin_clicked()
{
    no_error();
    buff[index++] = 'a';
    buff[index++] = 's';
    buff[index++] = 'i';
    buff[index++] = 'n';
    buff[index++] = '(';
    ui->lineEdit->setText(buff);
    countLen();
 }


void calc::on_pushButton_atan_clicked()
{
    no_error();
    buff[index++] = 'a';
    buff[index++] = 't';
    buff[index++] = 'a';
    buff[index++] = 'n';
    buff[index++] = '(';
    ui->lineEdit->setText(buff);
    countLen();
 }

void calc::no_error()
{
    ui->lineEdit_3->setText("");
}

void calc::on_pushButton_equal_clicked()
{
    if (!s21_to_polish(buff, output)) {
        double x = ui->doubleSpinBox->value();
        res = s21_calc_notation(output, x);
        on_pushButton_clear_clicked();
        sprintf(buff, "%lf", res);
        QString s = QString::number(res, 'f', 6);
        index += s.length();
        ui->lineEdit->setText(buff);
        countLen();
        memset(output, 0, 255);
    } else {
        ui->lineEdit_3->setText("Error");
    }
}


void calc::on_tabWidget_tabBarClicked(int index)
{
    double a = -10;
    double b =  10;
    double h = 0.001;
    int N = (b - a) / h -1;
    QVector<double> x(N), y(N);

    int i=0;
    memset(output, 0, 255);
    if (!s21_to_polish(buff, output)) {
        double X = a;
        for (int i = 0; i < N; i++) {
          x[i] = X;
          char cpy[260];
          strcpy(cpy, output);
          y[i] = s21_calc_notation(cpy, X);
          X += h;
        }
    }
    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    ui->widget->xAxis->setRange(a, b);ui->widget->yAxis->setRange(-10, 10);
    ui->widget->replot();
}


void calc::on_pushButton_equal_2_clicked()
{
    ui->lineEdit_7->setText("");
    double amount = ui->doubleSpinBox_5->value();
    int years = ui->spinBox->value();
    double rate = ui->doubleSpinBox_7->value();
    int flag = 1;
    credit_t cr = {0};
    if (ann == 1) {
        if (!s21_credit_annuity(amount, years, rate, &cr)) {
            QString s = QString::number(cr.payment[0], 'f', 2);
            ui->lineEdit_4->setText(s);
            s = QString::number(cr.charges, 'f', 2);
            ui->lineEdit_5->setText(s);
            s = QString::number(cr.total, 'f', 2);
            ui->lineEdit_6->setText(s);
        } else {
            flag = 0;
        }
    } else if (dif == 1) {
        if (!s21_credit_differentiated(amount, years, rate, &cr)) {
            QString s = QString::number(cr.payment[0], 'f', 2);
            QString e = QString::number(cr.payment[years * 12 - 1], 'f', 2);
            ui->lineEdit_4->setText(s + "..." + e);
            s = QString::number(cr.charges, 'f', 2);
            ui->lineEdit_5->setText(s);
            s = QString::number(cr.total, 'f', 2);
            ui->lineEdit_6->setText(s);
        } else {
            flag = 0;
        }
    } else {
        flag = 0;
    }

    if (!flag) {
        ui->lineEdit_7->setText("Error");
    }
}


void calc::on_radioButton_3_toggled(bool checked)
{
    ann = 1;
    dif = 0;
}


void calc::on_radioButton_toggled(bool checked)
{
    ann = 0;
    dif = 1;
}


void calc::on_pushButton_div_2_clicked()
{
    no_error();
    buff[index++] = ' ';
    buff[index++] = 'm';
    buff[index++] = 'o';
    buff[index++] = 'd';
    buff[index++] = ' ';
    ui->lineEdit->setText(buff);
    countLen();
}


void calc::on_pushButton_clear_2_clicked()
{
    no_error();
    if (index > 0) {
        index -= 1;
    //    temp = buff;
        memset(temp, 0, 256);
        for (int i = 0; i < index; i++) {
            temp[i] = buff[i];
        }
        memset(buff, 0, 256);
        strcpy(buff, temp);
        ui->lineEdit->setText(buff);
        countLen();
    }
}

