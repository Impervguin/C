#ifndef C_LABS_NUMBERS_H
#define C_LABS_NUMBERS_H
#include <stdbool.h>
#include "errors.h"
#include "sizes.h"
#include <stddef.h>

/*
 * Фукнция для проверки на то, что в заданном числе есть заданная цифра
 * Число и цифра заданы корректно
 *
 * \param num [in] - Число
 * \param digit [in] - Цифра
 *
 * \return true, если в числе есть цифра, иначе false
 */
bool check_digit_in_num(int num, int digit);
#endif //C_LABS_NUMBERS_H
