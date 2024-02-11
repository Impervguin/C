#ifndef C_LABS_MONO_H
#define C_LABS_MONO_H

#include "sizes.h"
#include "errors.h"
#include <stddef.h>

#define MONO 1 /// Значение, когда строка монотонная
#define NOT_MONO 0 /// Значение, когда строка не монотонная

/*
 * Фукнция для проверки монотонности каждой строки матрицы
 * Все входные данные должны быть корректны
 * \param mat [in] - Матрица
 * \param row_count [in] - Количество строк в матрице
 * \param col_count [in] - Количество столбцов в матрице
 * \param res [out] - Массив, размера col_count,
 * где k-й элемент соотвествует k-ой строке: равен 1 если строка монотонная, 0 - если нет
 * \return код ошибки
 */
int check_monotonic(int (*mat)[MAX_SIZE], size_t row_count, size_t col_count, int *res);

/*
 * Фукнция для проверки массив на монотонность
 * Все входные данные должны быть корректны
 * \param arr [in] - Массив чисел
 * \param arr_size [in] - размер массива
 *
 * \return 1 - если массив монотонный, иначе 0
 */
int check_array_monotonic(const int *arr, size_t arr_size);
#endif
