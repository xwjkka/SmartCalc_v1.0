#include "s21_credit.h"
#include "s21_calc.h"

int s21_credit_annuity(double amount, int years, double rate,
                       credit_t *credit) {
  int res = 0;
  years *= 12;
  rate = rate / (12 * 100.0);
  if (years <= 0 || amount <= 0 || rate <= 0) {
    res = 1;
  } else {
    credit->payment[0] = round((amount * rate * pow((1 + rate), years) /
                                (pow((1 + rate), years) - 1)) *
                               100.0) /
                         100.0;
    credit->total = credit->payment[0] * years;
    credit->charges = credit->total - amount;
  }
  return res;
}

int s21_credit_differentiated(double amount, int years, double rate,
                              credit_t *credit) {
  int res = 0;
  years *= 12;
  rate /= 100.0;
  if (years <= 0 || amount <= 0 || rate <= 0) {
    res = 1;
  } else {
    double k = round((amount / years) * 100.0) / 100.0;
    double temp = amount;
    int days = 31;
    for (int i = 0; i < years; i++) {
      days = i % 2 == 0 ? 30 : 31;
      credit->payment[i] =
          k + round(((temp * rate * days) / 365) * 100.0) / 100.0;
      temp -= k;
      credit->charges += (temp * rate * 30) / 365;
    }
    credit->total = credit->charges + amount;
  }
  return res;
}
