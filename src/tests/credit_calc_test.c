#include "unit.h"

START_TEST(ann1) {
    credit_t cr = {0};
    int res = s21_credit_annuity(100000, 2, 15, &cr);
    ck_assert_int_eq(0, res);
    ck_assert_double_eq_tol(cr.payment[0], 4848.66 , 1e-2);
    ck_assert_double_eq_tol(cr.charges, 16367.84, 1e-2);
    ck_assert_double_eq_tol(cr.total, 116367.84, 1e-2);
}
END_TEST

START_TEST(ann2) {
    credit_t cr = {0};
    int res = s21_credit_annuity(100000, 3, 12, &cr);
    ck_assert_int_eq(0, res);
    ck_assert_double_eq_tol(cr.payment[0], 3321.43 , 1e-2);
    ck_assert_double_eq_tol(cr.charges, 19571.48, 1e-2);
    ck_assert_double_eq_tol(cr.total, 119571.48, 1e-2);
}
END_TEST

START_TEST(ann3) {
    credit_t cr = {0};
    int res = s21_credit_annuity(20000, 3, 12, &cr);
    ck_assert_int_eq(0, res);
    ck_assert_double_eq_tol(cr.payment[0], 664.29, 1e-2);
    ck_assert_double_eq_tol(cr.charges, 3914.44, 1e-2);
    ck_assert_double_eq_tol(cr.total, 23914.44, 1e-2);
}
END_TEST

START_TEST(ann4) {
    credit_t cr = {0};
    int res = s21_credit_annuity(3000000, 12, 4.6, &cr);
    ck_assert_int_eq(0, res);
    ck_assert_double_eq_tol(cr.payment[0], 27148.58, 1e-2);
    ck_assert_double_eq_tol(cr.charges, 909395.52, 1e-2);
    ck_assert_double_eq_tol(cr.total, 3909395.52, 1e-2);
}
END_TEST

START_TEST(ann5) {
    credit_t cr = {0};
    int res = s21_credit_annuity(128934, 4, 9, &cr);
    ck_assert_int_eq(0, res);
    ck_assert_double_eq_tol(cr.payment[0], 3208.53, 1e-2);
    ck_assert_double_eq_tol(cr.charges, 25075.44, 1e-2);
    ck_assert_double_eq_tol(cr.total, 154009.44, 1e-2);
}
END_TEST

Suite *suite_s21_credit(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_credit");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, ann1);
  tcase_add_test(tc_core, ann2);
  tcase_add_test(tc_core, ann3);
  tcase_add_test(tc_core, ann4);
  tcase_add_test(tc_core, ann5);

  suite_add_tcase(s, tc_core);
  return s;
}
