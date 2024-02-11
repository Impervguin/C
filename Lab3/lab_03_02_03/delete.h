#ifndef C_LABS_DELETE_H
#define C_LABS_DELETE_H

#include "errors.h"
#include "sizes.h"
#include <stddef.h>

/*
 * Фукнция для удаления стобца мастрицы по индексу
 * Матрица существует, ее размеры корректны
 *
 * \param mat [in, out] - Матрица
 * \param row_count [in] - Количество строк в матрице
 * \param col_count [in, out] - Количество столбцов в матрице
 * \param index [in] - Индекс удаляемого столбца
 *
 * \return код ошибки
 */
int delete_column(int (*mat)[MAX_SIZE], size_t row_count, size_t *col_count, size_t index);

/*
 * Фукнция для удаления элемента массива по индексу
 * Массив существует, его размеры корректны
 *
 * \param arr [in, out] - Массив
 * \param arr [in, out] - Размер массива
 * \param index [in] - Индекц удаляемого элемента
 *
 * \return код ошибки
 */
int delete_element(int *arr, size_t *arr_size, size_t index);

/*
 * Фукнция для столбцов матрицы, в которых в хотя бы одном из чисел есть вводимая цифра
 * Массив существует, его размеры корректны, Цифра задана корректна ([0, 9])
 *
 * \param mat [in, out] - Матрица
 * \param row_count [in] - Количество строк в матрице
 * \param col_count [in, out] - Количество столбцов в матрице
 * \param digit [in] - Цифра
 *
 * \return код ошибки
 */
int delete_cols_with_digit_in_num(int (*mat)[MAX_SIZE], size_t row_count, size_t *col_count, int digit);
#endif //C_LABS_DELETE_H
