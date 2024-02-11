#ifndef C_LABS_IO_H
#define C_LABS_IO_H
#include "sizes.h"
#include "errors.h"
#include <stdio.h>


/*
 * Фукнция для ввода размеров матрицы
 *
 * \param row_count [out] - Указатель, на количество строк в матрице
 * \param col_count [out] - Указатель, на количество столбцов в матрице
 *
 * \return Код возврата
 */
int size_input(size_t *row_count, size_t *col_count);

/*
 * Фукнция для вывода матрицы
 *
 * \param mat [in] - Вводимая матрица
 * \param row_count [in] - Количество строк в матрице
 * \param col_count [in] - Количество столбцов в матрице
 *
 * \return Код возврата
 */
int output_matrix(int (*mat)[MAX_SIZE], size_t row_count, size_t col_count);
#endif
