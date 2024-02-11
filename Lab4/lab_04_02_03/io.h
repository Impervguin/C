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
 * Функция для вывода массива слов через пробел. Слова выводятся после "Result: "
 * @param[in] w - Массив слов
 * @param[in] w_count - Количество слов
 */
void words_output(char (*w)[WORD_LENGTH], size_t w_count);

/**
 * Функция для ввода двух строк подряд
 * @param[out] string1 - Указатель на первую строку
 * @param[out] string2 - Указатель на вторую строку
 * @return Код ошибки(успеха)
 */
int string_2_input(char *string1, char *string2);

#endif //C_LABS_IO_H
