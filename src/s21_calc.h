#ifndef SRC_S21_CALC_H_
#define SRC_S21_CALC_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum type_t { // -
  Number,
  X,
  Plus,
  Minus,
  Open_bracket,
  Mult,
  Div,
  Exp,
  Mod,
  Cos,
  Sin,
  Tan,
  Acos,
  Asin,
  Atan,
  Sqrt,
  Ln,
  Log,
  Close_bracket,
  Uplus,
  Uminus,
};

typedef struct stack_struct {
  double value;
  int priority;
  struct stack_struct *next;
  enum type_t type;
} stack_struct_t;

void s21_push(stack_struct_t **head, double value, int priority,
              enum type_t type);
stack_struct_t *s21_pop(stack_struct_t **head);
void s21_printStack(const stack_struct_t *head);
void s21_delete(stack_struct_t **head);
double s21_pop_value(stack_struct_t **head);

int s21_to_polish(char *str, char *output);
int s21_is_number(char symbol);
int s21_is_operation(char symbol);
int s21_is_unary(int was_number, int symbol);
int s21_check_priority(int operation_index);
char s21_check_func(char **str, int index, stack_struct_t **operations);
void s21_from_type_to_char(int *type, char *op, int var);
int s21_add_to_output(char **output, stack_struct_t **operations, char current);
void s21_add_to_stack(char *str, stack_struct_t **operations, int priority,
                      int type, int *count_open);
int s21_parse_values(char **str, stack_struct_t **operations, int *was_number,
                     int *count_open, int *priority, int *type);

double s21_calc_notation(char *str, double x);
void s21_grafic(char *str);

#endif // SRC_S21_CALC_H_
