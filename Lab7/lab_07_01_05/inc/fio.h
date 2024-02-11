#ifndef FIO_H__
#define FIO_H__

#include <stdio.h>
#include <stddef.h>
/**
 * @brief Функция для ввода чисел в массив из файла
 * 
 * @param [in] f - Файл
 * @param [out] arr_b - Указатель на начало введенного массива
 * @param [out] arr_e  - Указатель нга конец введенного массива
 * @return int - Код возврата
 */
int read_int_array(FILE *f, int **arr_b, int **arr_e);

/**
 * @brief Функция для вывода массива в файл
 * 
 * @param [in] f - Файл
 * @param [in] arr_b - Указатель на начало введенного массива
 * @param [in] arr_e  - Указатель нга конец введенного массива 
 * @return int - Код возврата
 */
int print_int_array(FILE *f, const int *arr_b, const int *arr_e);

#endif
