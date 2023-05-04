#include "s21_calc.h"
#include <stdbool.h>


typedef struct change {
    char date[8];
    int sum;
    int period;
} change_t;

typedef struct deposit {
    double amount;
    int years;
    double rate;
    // char date[8];
    char *date;
    bool capitalization;
    int type_of_capitalization;
    bool closing;
    char closing_date[8];
    change_t *list_replenishment;
    change_t *list_withdrawal;

    double charges;
    double income;
    double total;
} deposit_t;

int s21_deposit(deposit_t *deposit);

// int main() {
//     deposit_t deposit = {0};
//     deposit.amount = 1000000;
//     deposit.years = 1;
//     deposit.rate = 5;
//     deposit.date = "31.03.2023";
//     deposit.capitalization = false;
//     deposit.closing = false;
//     // deposit.list_replenishment = 
//     s21_deposit(&deposit);
//     return 0;
// }

int s21_deposit(deposit_t *deposit) {
    int res = 0;
    deposit->charges = (deposit->amount * deposit->rate * /*(years * 12 * days) / days_of_year*/ deposit->years * 12) / 100;
    printf("%f ", deposit->charges);
    return res;
}