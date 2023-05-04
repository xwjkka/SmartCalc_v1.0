#include "s21_calc.h"

// int main() {
//   // char str[10] = "3+8.4*2";
//   // char str[20] = "2 / (3 + 2) * 5";
//   // char str[255] = "3 + sin(sin(x))";
//   // char str[255] = "cos(30) / (5 ^ 2 + 33 mod 10) * atan(6) "; // есть leak
//   // // char *output = calloc(2 * strlen(str), sizeof(char));
//   // char output[255] = {0};
//   // int res = s21_to_polish(str, output);
//   // printf("%d\n", res);
//   // printf("%s\n", output);
// //   printf("res - %lf", s21_calc_notation(output, 5));
//   char ans[255] = "2 ^ 2 ^ 3\0";
//   // char input[255] = "2 2 3 ^ ^\0";
//   char *res = malloc(sizeof(char) * 255);
//   s21_to_polish(ans, res);
//   double x = 0;
//   printf("%s\n", res);
//   x = s21_calc_notation(res, 0);
//   printf("%s %lf", res, x);
//   free(res);
//   return 0;
// }

// ------------------- parse str --------------------------

int s21_to_polish(char *str, char *output) {
  stack_struct_t *operations = NULL;
  int res = 0, was_number = 0, count_open = 0;
  if ((!str && !output) || (strlen(str) == 0)) {
    res = 1;
  }
  while (*str && !res) {
    if (*str == ' ') {
      str++;
    } else if (s21_is_number(*str) && *str != '.') {
      was_number = 1;
      while (s21_is_number(*str)) {
        *output++ = *str++;
      }
      *output++ = ' ';
    } else if (s21_is_operation(*str) >= 0 &&
               s21_is_unary(was_number, s21_is_operation(*str))) {
      int priority = 0, type = 0;
      if (s21_parse_values(&str, &operations, &was_number, &count_open,
                           &priority, &type)) {
        res = 1;
        break;
      }
      while (operations && ((priority <= operations->priority && *str != '(') ||
                            *str == ')')) {
        if (s21_add_to_output(&output, &operations, *str)) {
          break;
        }
      }
      s21_add_to_stack(str, &operations, priority, type, &count_open);
      str++;
    } else {
      res = 1;
    }
  }
  if (!was_number) {
    res = 1;
  }
  while (operations && !res) {
    s21_add_to_output(&output, &operations, *str);
  }
  *output++ = '\0';
  if (count_open != 0) {
    res = 1;
  }
  if (res) {
    s21_delete(&operations);
  }
  return res;
}

// ------------------- calc polish --------------------------

double s21_calc_notation(char *str, double x) {
  stack_struct_t *numbers = NULL;
  char *lexeme = strtok(str, " ");
  while (lexeme) {
    if (*lexeme == 'x') {
      s21_push(&numbers, x, 0, X);
    } else if (s21_is_number(*lexeme)) {
      s21_push(&numbers, atof(lexeme), 0, Number);
    } else {
      double first = s21_pop_value(&numbers);
      double second = 0;
      int index = s21_is_operation(*lexeme);
      if (index <= 6) {
        second = s21_pop_value(&numbers);
      }
      if (*lexeme == '+') {
        s21_push(&numbers, first + second, 0, Number);
      } else if (*lexeme == '#') {
        s21_push(&numbers, first, 0, Number);
      } else if (*lexeme == '-') {
        // s21_push(&numbers, first - second, 0, Number);
        s21_push(&numbers, second - first, 0, Number);
      } else if (*lexeme == '~') {
        s21_push(&numbers, -first, 0, Number);
      } else if (*lexeme == '*') {
        s21_push(&numbers, first * second, 0, Number);
      } else if (*lexeme == '/') {
        s21_push(&numbers, second / first, 0, Number);
      } else if (*lexeme == '^') {
        s21_push(&numbers, pow(first, second), 0, Number);
      } else if (*lexeme == 'm') {
        s21_push(&numbers, fmod(second, first), 0, Number);
      } else if (*lexeme == 'o') {
        s21_push(&numbers, cos(first), 0, Number);
      } else if (*lexeme == 'i') {
        s21_push(&numbers, sin(first), 0, Number);
      } else if (*lexeme == 'a') {
        s21_push(&numbers, tan(first), 0, Number);
      } else if (*lexeme == 'c') {
        s21_push(&numbers, acos(first), 0, Number);
      } else if (*lexeme == 's') {
        s21_push(&numbers, asin(first), 0, Number);
      } else if (*lexeme == 't') {
        s21_push(&numbers, atan(first), 0, Number);
      } else if (*lexeme == 'q') {
        s21_push(&numbers, sqrt(first), 0, Number);
      } else if (*lexeme == 'n') {
        s21_push(&numbers, log(first), 0, Number);
      } else if (*lexeme == 'g') {
        s21_push(&numbers, log10(first), 0, Number);
      }
    }
    lexeme = strtok(NULL, " ");
  }
  double res = s21_pop_value(&numbers);
  return res;
}

// ------------------- work with str --------------------------

int s21_is_number(char symbol) {
  return ((symbol >= '0' && symbol <= '9') || symbol == '.' || symbol == 'x')
             ? 1
             : 0;
}

int s21_is_operation(char symbol) {
  char *operations = "+-(*/^mcstasl)#~";
  int res = -1;
  while (*operations) {
    res++;
    if (*operations++ == symbol) {
      break;
    }
  }
  return res;
}

int s21_is_unary(int was_number, int symbol) {
  return (was_number ||
          (!was_number && (symbol <= 2 || (symbol > 6 && symbol <= 12))));
}

int s21_check_priority(int operation_index) {
  return operation_index <= 2 ? 0 : (operation_index <= 4 ? 1 : 2);
}

char s21_check_func(char **str, int index, stack_struct_t **operations) {
  char f = 0;
  if (index >= 6 && index <= 12) {
    if (**str == 'c') {
      f = 'o';
    } else if (**str == 'm') {
      f = 'm';
      (*str)++;
      (*str)++;
    } else if (**str == 'l') {
      (*str)++;
      f = **str == 'o' ? 'g' : 'n';
    } else {
      (*str)++;
      f = **str;
    }
    // if (*(*str)++ == 'o') {
    //   f = **str == 'l' ? 'g' : **str == 'm' ? 'm' : 'o';
    // } else {
    //   f = **str;
    // }
    while (f != 'm' && **str != '(') {
      if (**str == '(') {
        break;
      } else if (!str) {
        f = 'r';
        break;
      }
      (*str)++;
    }
    if (f != 'm') {
      s21_push(operations, 0, 0, (enum type_t)(4));
    }
  } else {
    f = **str;
  }
  return f;
}

void s21_from_type_to_char(int *type, char *op, int var) {
  char *operations = "+-(*/^moiacstqng)#~";
  if (var) {
    *op = operations[*type - 2];
  } else {
    int i = -1;
    while (*operations) {
      i++;
      if (*op == *operations++) {
        break;
      }
    }
    *type = i + 2;
  }
}

int s21_add_to_output(char **output, stack_struct_t **operations,
                      char current) {
  int res = 0;
  stack_struct_t *tmp = s21_pop(operations);
  if (tmp) {
    char function = 0;
    int type = tmp->type;
    if (current == ')' && type == Open_bracket) {
      res = 1;
    } else {
      s21_from_type_to_char(&type, &function, 1);
      if (type != Open_bracket) {
        *(*output)++ = function;
        *(*output)++ = ' ';
      }
    }
    free(tmp);
  }

  return res;
}

void s21_add_to_stack(char *str, stack_struct_t **operations, int priority,
                      int type, int *count_open) {
  if (*str != ')') {
    s21_push(operations, 0, priority, (enum type_t)(type));
    if (type >= Cos && type <= Log && type != Mod) {
      (*count_open)++;
      s21_push(operations, 0, -1, (enum type_t)(Open_bracket));
    }
  }
}

int s21_parse_values(char **str, stack_struct_t **operations, int *was_number,
                     int *count_open, int *priority, int *type) {
  int res = 0;
  int index = s21_is_operation(**str);
  char func = s21_check_func(str, index, operations);
  if (func == 'r') {
    res = 1;
  } else {
    if (!*was_number && (s21_is_operation(**str) != 2)) {
      func = index == 1 ? '~' : '#';
      index += 17;
    }
    *priority = func == '(' ? -1 : s21_check_priority(index);
    *type = 0;
    *was_number = func != ')' ? 0 : 1;
    if (func == '(') {
      (*count_open)++;
    } else if (func == ')') {
      (*count_open)--;
    }
    s21_from_type_to_char(type, &func, 0);
  }
  return res;
}

// ------------------- work with stack --------------------------

void s21_push(stack_struct_t **head, double value, int priority,
              enum type_t type) {
  stack_struct_t *tmp = malloc(sizeof(stack_struct_t));
  // if (tmp == NULL) {}
  tmp->next = *head;
  tmp->value = value;
  tmp->priority = priority;
  tmp->type = type;
  *head = tmp;
}

stack_struct_t *s21_pop(stack_struct_t **head) {
  stack_struct_t *out = {0};
  if ((*head) == NULL) {
    exit(1);
  }
  out = *head;
  *head = (*head)->next;
  return out;
}

double s21_pop_value(stack_struct_t **head) {
  stack_struct_t *out = {0};
  double res = 0;
  if ((*head) == NULL) {
    exit(1);
  }
  out = *head;
  *head = (*head)->next;
  res = out->value;
  free(out);
  return res;
}

void s21_printStack(const stack_struct_t *head) {
  while (head) {
    printf("%lf %d %d\n", head->value, head->priority, head->type);
    head = head->next;
  }
  printf("\n");
}

void s21_delete(stack_struct_t **head) {
  stack_struct_t *tmp = {0};
  while (*head) {
    tmp = s21_pop(head);
    free(tmp);
  }
}
