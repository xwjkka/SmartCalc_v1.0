#ifndef CALC_H
#define CALC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class calc; }
QT_END_NAMESPACE

class calc : public QMainWindow
{
    Q_OBJECT

public:
    calc(QWidget *parent = nullptr);
    ~calc();

private slots:
    void countLen();
    void no_error();
    void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();

    //operators
    void on_pushButton_div_clicked();
    void on_pushButton_mul_clicked();
    void on_pushButton_plus_clicked();
    void on_pushButton_minus_clicked();

    //func
    void on_pushButton_open_bracket_clicked();
    void on_pushButton_close_bracket_clicked();
    void on_pushButton_point_clicked();
    void on_pushButton_x_clicked();
    void on_pushButton_pow_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_cos_clicked();
    void on_pushButton_sin_clicked();
    void on_pushButton_sqrt_clicked();
    void on_pushButton_tan_clicked();
    void on_pushButton_ln_clicked();
    void on_pushButton_acos_clicked();
    void on_pushButton_log_clicked();
    void on_pushButton_asin_clicked();
    void on_pushButton_atan_clicked();
    void on_pushButton_equal_clicked();
    void on_tabWidget_tabBarClicked(int index);
    void on_pushButton_equal_2_clicked();
    void on_radioButton_3_toggled(bool checked);
    void on_radioButton_toggled(bool checked);

    void on_pushButton_div_2_clicked();

    void on_pushButton_clear_2_clicked();

private:
    Ui::calc *ui;

private:
    char buff[256];
    char temp[256];
    int index = 0;

    char output[256];
    double res = 0;

    char count_len[256];
    int ann = 0;
    int dif = 0;
};

#endif // CALC_H
