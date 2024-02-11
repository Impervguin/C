#ifndef C_LABS_CALCULATE_H
#define C_LABS_CALCULATE_H
#include <stdio.h>
#include <math.h>
#include "errors.h"
#include "consts.h"
/**
 * Функция, которая проверяет выполняется ли для файла с числами правило трех сигм
 * @param [in] f - Файл
 * @param [out] res - Результат: 1 - выполняется, 0 - нет
 * @param [in] expected_value - Математическое ожидание для файла
 * @param [in] deviation - дисперся для файла
 * @return Код возврата
 */
int check_three_sigma_rule(FILE *f, int *res, double expected_value, double deviation);

/**
 * Функция, которая считает дисперсию для файла с числами
 * @param [in] f - Файл
 * @param [out] res - Указатель на дисперсию
 * @param [in] expected_value - Математическое ожидание
 * @return  Код возврата
 */
int calc_standard_deviation(FILE *f, double *res, double expected_value);
/**
 * Функция, которая считает математическое ожидание для файла
 * @param [in] f - Файл
 * @param [out] res - Указатель на мат. ожидание
 * @return Код возврата
 */
int calc_expected_value(FILE *f, double *res);

#endif //C_LABS_CALCULATE_H
