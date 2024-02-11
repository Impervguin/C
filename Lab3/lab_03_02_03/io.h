#ifndef C_LABS_IO_H
#define C_LABS_IO_H

#include "errors.h"
#include "sizes.h"
#include <stdio.h>

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
 * Фукнция для вывода матрицы
 *
 * \param mat [in] - Вводимая матрица
 * \param row_count [in] - Количество строк в матрице
 * \param col_count [in] - Количество столбцов в матрице
 *
 * \return код ошибки
 */
int output_matrix(int (*mat)[MAX_SIZE], size_t row_count, size_t col_count);

/*
 * Фукнция для ввода цифры
 *
 *
 * \param digit [out] - Вводимая цифра
 *
 * \return Код ошибки
 */
int input_digit(int *digit);
#endif
