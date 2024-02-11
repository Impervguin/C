#ifndef C_LABS_SWITCH_H
#define C_LABS_SWITCH_H
#include "sizes.h"
#include "errors.h"
#include <stddef.h>


/*
 * Функция для перестановки столбцов в квадратной матрице, при этом чем ближе к центру, тем меньше берется столбец
 *
 * \param mat [in, out] - Матрица
 * \param size [in] - Размер матрицы
 *
 * \return Код ошибки
 */
int switch_cols(int (*mat)[MAX_SIZE], size_t size);
#endif //C_LABS_SWITCH_H
