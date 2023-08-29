#ifndef SRC_S21_CALC_H_
#define SRC_S21_CALC_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Список возможных типов аргументов в выражении
 */
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

/**
 * @brief Структура для перевода в польскую нотацию
 * @param value Значение, если структура хранит числа
 * @param priority Приоритеты функция
 * @param next Указатель на следующую ноду
 * @param type Тип переменной
 */
typedef struct stack_struct {
  double value;
  int priority;
  struct stack_struct *next;
  enum type_t type;
} stack_struct_t;

/**
 * @brief Кладет новое значение в стэк
 */
void s21_push(stack_struct_t **head, double value, int priority,
              enum type_t type);
/**
 * @brief Берет значение сверху
 * @return Полносью верхнюю ноду
 */
stack_struct_t *s21_pop(stack_struct_t **head);
/**
 * @brief Печатает весь стэк
 */
void s21_printStack(const stack_struct_t *head);
/**
 * @brief Удаляет стэк
 */
void s21_delete(stack_struct_t **head);
/**
 * @brief Берет значение сверху
 * @return Значение value верхней ноды
 */
double s21_pop_value(stack_struct_t **head);

/**
 * @brief Переводит выражение в польскую нотацию
 * @param str Входная строка с выражением
 * @param output Выходная строка
 * @return 0 - ОК, 1 - ошибка
 */
int s21_to_polish(char *str, char *output);
/**
 * @brief Проверяет является ли символом числом
 * @return 0 - нет, 1 - да
 */
int s21_is_number(char symbol);
/**
 * @brief Проверяет является ли символом функцией или ее первой буквой
 * @return Порядковый номер в некоторой строке
 */
int s21_is_operation(char symbol);
/**
 * @brief Проверяет является ли операция унарной
 * @return 0 - нет, 1 - да
 */
int s21_is_unary(int was_number, int symbol);
/**
 * @brief Определяет приоритет операций
 */
int s21_check_priority(int operation_index);
/**
 * @brief Определяет какая функция введена
 * @return букву, которую я обозначила за опреденную функцию
 */
char s21_check_func(char **str, int index, stack_struct_t **operations);
/**
 * @brief Переводит из enum type в char
 */
void s21_from_type_to_char(int *type, char *op, int var);
/**
 * @brief Добавляет весь стэк сверху к строке результата
 * @return 0 - ОК, 1 - ошибка
 */
int s21_add_to_output(char **output, stack_struct_t **operations, char current);
/**
 * @brief Добавляет в стэк функцию
 */
void s21_add_to_stack(char *str, stack_struct_t **operations, int priority,
                      int type, int *count_open);
/**
 * @brief Вычисляет из char необходимые параменты и записывает в разные
 * перемнные. Например, унарный ли оператор и какой у него приоритет.
 * @return 0 - ОК, 1 - ошибка
 */
int s21_parse_values(char **str, stack_struct_t **operations, int *was_number,
                     int *count_open, int *priority, int *type);
/**
 * @brief Считает польскую нотацию
 * @param str Польская нотация
 * @param x Если нужно подставить x, по дефолту 0
 * @return Посчитанный ответ
 */
double s21_calc_notation(char *str, double x);

#endif // SRC_S21_CALC_H_
