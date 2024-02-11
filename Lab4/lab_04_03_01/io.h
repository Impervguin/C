#ifndef C_LABS_IO_H
#define C_LABS_IO_H

#include <stdio.h>
#include <string.h>
#include "sizes.h"
#include "errors.h"

/**
 * Функция для ввода строки
 * @param[out] string - Указатель на строку
 * @return Код ошибки(успеха)
 */
int string_input(char *string);

/**
 * Функция для вывода строки. Строка выводится после "Result: "
 * @param[in] str - Строка
 */
void string_output(const char *str);
#endif //C_LABS_IO_H
