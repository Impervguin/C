#ifndef C_LABS_IO_H
#define C_LABS_IO_H

#include "sizes.h"
#include "errors.h"
#include <stddef.h>


/*
 * Фукнция для ввода матрицы ввиде двумерного массива
 *
 * \param mat [out] - Вводимая матрица
 * \param row_count [out] - Указатель, на количество строк в матрице
 * \param col_count [out] - Указатель, на количество столбцов в матрице
 *
 * \return код ошибки
 */
int mat_input(int (*mat)[MAX_SIZE], size_t *row_count, size_t *col_count);

/*
 * Фукнция для вывода массива
 * Размер и сам массив корректны
 * \param arr [in] - Массив
 * \param arr_size [in] - Размер массива
 */
int output_arr(const int *arr, size_t arr_size);
#endif
