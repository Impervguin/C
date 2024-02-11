#ifndef C_LABS_STRINGS_H
#define C_LABS_STRINGS_H
#include <stddef.h>
#include <stdbool.h>
#include "str_func.h"

/**
 * Функция, для определения наибольшей длины начальногго участка строки, состоящей только из заданных символов
 * @param[in] str - строка
 * @param[in] sym - символы
 * @return Длина начального участка
 */
size_t my_strspn(const char *str, const char *sym);

/**
 * Функция, для поиска последнего вхождения символа с кодом sym
 * @param[in] str - строка
 * @param[in] sym - код символа
 * @return Указатель на искомый символ, если символ не найден, то возвращается NULL
 */
char *my_strrchr(const char *str, int ch);

/**
 * Функция, для поиска первого вхождения одного из символов строки sym
 * @param[in] str - строка
 * @param[in] sym -  строка с символами
 * @return Указатель на искомый символ, если символ не найден, то возвращается NULL
 */
char *my_strpbrk(const char *str, const char *sym);

/**
 * Функция, для определения наибольшей длины начальногго участка строки, состоящей не из заданных символов
 * @param[in] str - строка
 * @param[in] sym - символы
 * @return Длина начального участка
 */
size_t my_strcspn(const char *str, const char *sym);

/**
 * Функция, для поиска первого вхождения символа с кодом sym
 * @param[in] str - строка
 * @param[in] sym - код символа
 * @return Указатель на искомый символ, если символ не найден, то возвращается NULL
 */
char *my_strchr(const char *str, int sym);

#endif //C_LABS_STRINGS_H
