#ifndef LIBFIO_H__
#define LIBFIO_H__

#define ERR_OK 0
#define ERR_IO 1
#define ERR_FORMAT 6

#include <stdio.h>
#include <stddef.h>

/**
 * @brief Функция для подсчета количество чисел в файле
 * 
 * @param [in\out] f - Файл
 * @param [out] nums - Указатель на количество
 * @return int Код возврата
 */
int count_nums_in_file(FILE *f, size_t *nums);

/**
 * @brief Функция для ввода массива целых чисел из файла
 * 
 * @param [in\out] f - Файл.
 * @param [in] arr_b - Указатель на начало массива, выделенного заранее под количество символов в файле.
 * @param [out] arr_e - Будущий указатель на конец массива.
 * @return int - Код возврата
 */
int read_file_array(FILE *f, int *arr_b, int **arr_e);

/**
 * @brief Функция для вывода массива в файл
 * 
 * @param [in\out] f - Файл
 * @param [in] arr_b - Указатель на начало введенного массива
 * @param [in] arr_e  - Указатель нга конец введенного массива 
 * @return int - Код возврата
 */
int print_int_array(FILE *f, const int *arr_b, const int *arr_e);

#endif // LIBFIO_H__
