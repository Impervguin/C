#ifndef C_LABS_MAT_OP_H
#define C_LABS_MAT_OP_H

#include <stdbool.h>
#include "sizes.h"
#include <stddef.h>
#include "errors.h"

/*
 * Функция, которая меняет местами все элементы в массивах с одинаковым размером
 *
 * /param arr1 [in, out] - Массив 1
 * /param arr2 [in, out] - Массив 1
 * /param arr_size [in] - Размер массивов
 *
 * /return Код возврата
 */
int swap_arrs(int *arr1, int *arr2, size_t arr_size);

/*
 * Функция, которая находит минимальный элемент в массиве
 *
 * /param arr [in] - Массив
 * /param size [in] - Размер массива
 *
 * /return Код возврата
 */
int find_min(const int *arr, size_t size);

/*
 * Функция, которая меняет местами строки матрицы
 *
 * /param mat [in, out] - Матрица
 * /param row_count [in] - Количество строк
 * /param col_count [in] - Количество столбцов
 * /param key [in] - Функция, по которой происходит сравнение строк - для каждой строки вызывается эта функция и
 * затем по полученным значениям они сортируются
 * /param reverse - Ключ направления сортировки - true - по убыванию, false - по возрастанию
 *
 * /return Код возврата
 */
int sort_mat_rows(int (*mat)[MAX_SIZE], size_t row_count, size_t col_count);
#endif //C_LABS_MAT_OP_H
