#ifndef C_LABS_TEST_H
#define C_LABS_TEST_H
#include "strings.h"
#include <string.h>
#include "stdio.h"
#define WORD_LENGTH 16

/**
 * Функция для сравнения вывода(тестирования) функций my_strchr и strchr
 * @return Количество несовпадений выводов
 */
int test_strchr(void);

/**
 * Функция для сравнения вывода(тестирования) функций my_strcspn и strcspn
 * @return Количество несовпадений выводов
 */
int test_strcspn(void);

/**
 * Функция для сравнения вывода(тестирования) функций my_strrchr и strrchr
 * @return Количество несовпадений выводов
 */
int test_strrchr(void);

/**
 * Функция для сравнения вывода(тестирования) функций my_strpbrk и strpbrk
 * @return Количество несовпадений выводов
 */
int test_strpbrk(void);

/**
 * Функция для сравнения вывода(тестирования) функций my_strspn и strpspn
 * @return Количество несовпадений выводов
 */
int test_strspn(void);

#endif //C_LABS_TEST_H
