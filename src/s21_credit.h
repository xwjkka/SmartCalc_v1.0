#ifndef SRC_S21_CREDIT_H_
#define SRC_S21_CREDIT_H_

#include <math.h>

#define Annuity 1
#define Differentiated 2

// #include "s21_calc.h"

int s21_calc_credit(double amount, int years, double rate, int type,
                    int k_days);

typedef struct credit {
  double payment[10000];
  double charges;
  double total;
} credit_t;

int s21_credit_annuity(double amount, int years, double rate, credit_t *credit);
int s21_credit_differentiated(double amount, int years, double rate,
                              credit_t *credit);


#endif // SRC_S21_CREDIT_H_
