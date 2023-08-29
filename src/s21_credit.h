#ifndef SRC_S21_CREDIT_H_
#define SRC_S21_CREDIT_H_

#include <math.h>

#define Annuity 1
#define Differentiated 2

/**
 * @brief Структура для записи результатов расчета кредита
 */
typedef struct credit {
  double payment[10000];
  double charges;
  double total;
} credit_t;

/**
 * @brief Считает выплаты по кредиту с аннуитентными платежами
 * @param amount Сумма кредита
 * @param years Количество лет
 * @param rate Процентная ставка
 * @param credit Структура куда записать ответ
 * @return 0 - ОК; 1 - ошибка
 */
int s21_credit_annuity(double amount, int years, double rate, credit_t *credit);
/**
 * @brief Считает выплаты по кредиту с дифференцированными платежами
 * @param amount Сумма кредита
 * @param years Количество лет
 * @param rate Процентная ставка
 * @param credit Структура куда записать ответ
 * @return 0 - ОК; 1 - ошибка
 */
int s21_credit_differentiated(double amount, int years, double rate,
                              credit_t *credit);

#endif // SRC_S21_CREDIT_H_
