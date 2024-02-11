#ifndef C_LABS_MAT_OP_H
#define C_LABS_MAT_OP_H
#include "errors.h"
#include "sizes.h"
#include <stddef.h>


/*
 * Функция, которая заполняет матрицу нулями
 *
 * /param mat [in, out] - Матрица
 * /param row_count [in] - Количество строк
 * /param col_count [in] - Количество столбцов
 *
 * /return Код возврата
 */
int fill_zeros_mat(int (*mat)[MAX_SIZE], size_t row_count, size_t col_count);

/*
 * Функция, которая заполняет матрицу по спирали против часовой стрелки
 *
 * /param mat [in, out] - Матрица
 * /param row_count [in] - Количество строк
 * /param col_count [in] - Количество столбцов
 *
 * /return Код возврата
 */
int fill_spiral_matrix(int (*mat)[MAX_SIZE], size_t row_count, size_t col_count);
#endif //C_LABS_MAT_OP_H
