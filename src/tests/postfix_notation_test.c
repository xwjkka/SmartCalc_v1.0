#include "unit.h"

START_TEST(basic1) {
  char ans[255] = "10 ~ x 20 + * \0";
  char input[255] = "-10 * (x + 20) \0";
  // char *input = calloc(sizeof(char) * 100);
  // strcpy(input, "-10 * (x + 20) \0");
  char *res = malloc(sizeof(char) * 255);
  ck_assert_int_eq(s21_to_polish(input, res), 0);
  ck_assert_str_eq(res, ans);
  ck_assert_double_eq(-200.0, s21_calc_notation(res, 0));
  // free(input);
  free(res);
}
END_TEST

START_TEST(basic2) {
  char ans[] = "30 42 12 * + 33 + \0";
  char *input = malloc(sizeof(char) * 100);
  strcpy(input, "30 + 42 * 12 + 33 \0");
  char *res = malloc(sizeof(char) * 100);
  ck_assert_int_eq(s21_to_polish(input, res), 0);
  ck_assert_str_eq(res, ans);
  ck_assert_double_eq(567.0, s21_calc_notation(res, 0));
  free(input);
  free(res);
}
END_TEST

START_TEST(basic3) {
  char ans[] = "1 2 + 3 4 + * \0";
  char *input = calloc(sizeof(char), 100);
  strcpy(input, "(1 + 2) * (3 + 4) \0");
  char *res = calloc(sizeof(char), 100);
  ck_assert_int_eq(s21_to_polish(input, res), 0);
  ck_assert_str_eq(res, ans);
  ck_assert_double_eq(21, s21_calc_notation(res, 0));
  free(input);
  free(res);
}
END_TEST

START_TEST(basic4) {
  char ans[] = "1 2 * 3 4 * + \0";
  char *input = calloc(sizeof(char), 100);
  strcpy(input, "1 * 2 + 3 * 4 \0");
  char *res = calloc(sizeof(char), 100);
  ck_assert_int_eq(s21_to_polish(input, res), 0);
  ck_assert_str_eq(res, ans);
  ck_assert_double_eq(14.0, s21_calc_notation(res, 0));
  free(input);
  free(res);
}
END_TEST

START_TEST(basic5) {
  char ans[] = "1 2 + 3 + 4 + \0";
  char *input = calloc(sizeof(char), 100);
  strcpy(input, "1 + 2 + 3 + 4 \0");
  char *res = calloc(sizeof(char), 100);
  ck_assert_int_eq(s21_to_polish(input, res), 0);
  ck_assert_str_eq(res, ans);
  ck_assert_double_eq(10.0, s21_calc_notation(res, 0));
  free(input);
  free(res);
}
END_TEST

START_TEST(basic6) {
  char ans[] = "x 2 + x 3 + * x 2 / * \0";
  char *input = calloc(sizeof(char), 100);
  strcpy(input, "(x+2)*(x+3)*(x/2) \0");
  char *res = calloc(sizeof(char), 100);
  ck_assert_int_eq(s21_to_polish(input, res), 0);
  ck_assert_str_eq(res, ans);
  free(input);
  free(res);
}
END_TEST

START_TEST(basic7) {
  char ans[] = "9 1 + n 1.5 1 m + \0";
  char *input = calloc(sizeof(char), 100);
  strcpy(input, "ln(9 + 1) + 1.5 mod 1\0");
  char *res = calloc(sizeof(char), 100);
  ck_assert_int_eq(s21_to_polish(input, res), 0);
  ck_assert_str_eq(res, ans);
  ck_assert_double_eq_tol(s21_calc_notation(res, 0), 2.802585, 1e-7);
  free(input);
  free(res);
}
END_TEST

START_TEST(basic8) {
  char ans[] = "40 4 + ~ \0";
  char *input = calloc(sizeof(char), 100);
  strcpy(input, "-(40 + 4)\0");
  char *res = calloc(sizeof(char), 100);
  ck_assert_int_eq(s21_to_polish(input, res), 0);
  ck_assert_str_eq(res, ans);
  ck_assert_double_eq_tol(s21_calc_notation(res, 0), -44, 1e-7);
  free(input);
  free(res);
}
END_TEST

START_TEST(basic9) {
  char ans[255] = "30 o 5 2 ^ 33 10 m + / 6 t * \0";
  char input[255] = "cos(30) / (5 ^ 2 + 33 mod 10) * atan(6)\0";
  char *res = calloc(sizeof(char), 255);
  ck_assert_int_eq(s21_to_polish(input, res), 0);
  ck_assert_str_eq(res, ans);
  ck_assert_double_eq_tol(s21_calc_notation(res, 0), 0, 007743);
  free(res);
}
END_TEST

START_TEST(basic10) {
  char ans[] = "7 # 98.4 g 4 q * - \0";
  char *input = calloc(sizeof(char), 100);
  strcpy(input, "+7 - log(98.4) * sqrt(4) \0");
  char *res = calloc(sizeof(char), 100);
  ck_assert_int_eq(s21_to_polish(input, res), 0);
  ck_assert_str_eq(res, ans);
  ck_assert_double_eq_tol(s21_calc_notation(res, 0), 0, 007743);
  free(input);
  free(res);
}
END_TEST

START_TEST(basic11) {
  char ans[] = "9 6 - \0";
  char *input = calloc(sizeof(char), 100);
  strcpy(input, "9 - 6\0");
  char *res = calloc(sizeof(char), 100);
  ck_assert_int_eq(s21_to_polish(input, res), 0);
  ck_assert_str_eq(res, ans);
  ck_assert_double_eq(s21_calc_notation(res, 0), 3);
  free(input);
  free(res);
}
END_TEST

START_TEST(basic12) {
  char ans[] = "9 6 ~ - \0";
  char *input = calloc(sizeof(char), 100);
  strcpy(input, "9 - -6\0");
  char *res = calloc(sizeof(char), 100);
  ck_assert_int_eq(s21_to_polish(input, res), 0);
  ck_assert_str_eq(res, ans);
  ck_assert_double_eq(s21_calc_notation(res, 0), 15);
  free(input);
  free(res);
}
END_TEST

START_TEST(bracket_error1) {
  char *input = calloc(sizeof(char), 100);
  strcpy(input, "1 + (2 + 3)) + 4 \0");
  char *res = calloc(sizeof(char), 100);
  ck_assert_int_eq(s21_to_polish(input, res), 1);
  free(input);
  free(res);
}
END_TEST

START_TEST(bracket_error2) {
  char *input = calloc(sizeof(char), 100);
  strcpy(input, "1 + ((2 + 3) + 4 \0");
  char *res = calloc(sizeof(char), 100);
  ck_assert_int_eq(s21_to_polish(input, res), 1);
  free(input);
  free(res);
}
END_TEST

START_TEST(double_operator_error1) {
  char *input = calloc(sizeof(char), 100);
  strcpy(input, "1 + 2 - (2 ** 2) \0");
  char *res = calloc(sizeof(char), 100);
  ck_assert_int_eq(s21_to_polish(input, res), 1);
  free(input);
  free(res);
}
END_TEST

START_TEST(double_operator_error2) {
  char *input = calloc(sizeof(char), 100);
  strcpy(input, "2 // 2 \0");
  char *res = calloc(sizeof(char), 100);
  ck_assert_int_eq(s21_to_polish(input, res), 1);
  free(input);
  free(res);
}
END_TEST

// START_TEST(function0) {
//   char *input = calloc(sizeof(char) * 100);
//   strcpy(input, "si2 \0");
//   char *res = calloc(sizeof(char) * 100);
//   ck_assert_int_eq(s21_to_polish(input, res), 1);
//   free(input);
//   free(res);
// }
// END_TEST

// START_TEST(function1) {
//   char *input = calloc(sizeof(char) * 100);
//   strcpy(input, "sin2) \0");
//   char *res = calloc(sizeof(char) * 100);
//   ck_assert_int_eq(s21_to_polish(input, res), 1);
//   free(input);
//   free(res);
// }
// END_TEST

// START_TEST(function2) {
//   char *input = calloc(sizeof(char) * 100);
//   strcpy(input, "lol(2) \0");
//   char *res = calloc(sizeof(char) * 100);
//   ck_assert_int_eq(s21_to_polish(input, res), 1);
//   free(input);
//   free(res);
// }
// END_TEST

Suite *suite_s21_to_polish(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_to_polish");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, basic1);
  tcase_add_test(tc_core, basic2);
  tcase_add_test(tc_core, basic3);
  tcase_add_test(tc_core, basic4);
  tcase_add_test(tc_core, basic5);
  tcase_add_test(tc_core, basic6);
  tcase_add_test(tc_core, basic7);
  tcase_add_test(tc_core, basic8);
  tcase_add_test(tc_core, basic9);
  tcase_add_test(tc_core, basic10);
  tcase_add_test(tc_core, basic11);
  tcase_add_test(tc_core, basic12);
  tcase_add_test(tc_core, bracket_error1);
  tcase_add_test(tc_core, bracket_error2);
  tcase_add_test(tc_core, double_operator_error1);
  tcase_add_test(tc_core, double_operator_error2);
  // tcase_add_test(tc_core, function0);
  // tcase_add_test(tc_core, function1);
  // tcase_add_test(tc_core, function2);
  suite_add_tcase(s, tc_core);
  return s;
}
