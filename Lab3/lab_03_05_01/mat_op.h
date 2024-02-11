#ifndef C_LABS_MAT_OP_H
#define C_LABS_MAT_OP_H
#include "errors.h"
#include "sizes.h"
#include "stddef.h"
#include "numbers.h"

/*
 * Функция, которая в матрице находит все элементы с суммуой цифр > 10
 *
 *  /param mat [in] - Матрица
 *  /param row_count [in] - Количество строк
 *  /param col_count [in] - Количество столбцов
 *  /param arr_pos [out] - Массив, куда будут записаны все позиции, на которых стояли числа с суммой > 10. Номер позиции -
 *  Индекс в матрице, если представить ее как одномерный массив, записав строки друг за другом
 *  /param arr [out] - Массив со всеми числами с суммой цифр > 10
 *  /param size [out] - Размер массивов
 *
 *  /return Код ошибки
 */
int get_elems_with_sum_ten(int (*mat)[MAX_SIZE], size_t row_count, size_t col_count, int *arr, size_t *size);

/*
 * Функция, которая циклически смещает элементы в массиве на один влево
 *
 * /param arr [in, out] - Массив
 * /param size [in] - его размер
 *
 *  /return Код ошибки
 */
int left_shift(int *arr, size_t size);

/*
 * Функция, которая циклически смещает элементы в массиве на n влево
 *
 * /param arr [in, out] - Массив
 * /param size [in] - его размер
 * /param n [in] - сдвиг
 *
 *  /return Код ошибки
 */
int left_shift_n(int *arr, size_t size, int n);

/*
 * Функция, которая вставляет элементы по номерам нужных позиций в матрицу
 * Массивы заданы корректно, номера позиций не должны выходить за матрицу
 *
 *  /param mat [out] - Матрица
 *  /param col_count [in] - Количество столбцов матрицы
 *  /param arr_pos [int] - Массив, с номерами поизиций. Номер позиции -
 *  Индекс в матрице, если представить ее как одномерный массив, записав строки друг за другом
 *  /param arr [in] - Массив с элементами
 *  /param size [in] - Размер массивов
 *
 *  /return Код ошибки
 */
int put_elems_in_mat(int (*mat)[MAX_SIZE], size_t row_count, size_t col_count, const int *arr, size_t size);

#endif //C_LABS_MAT_OP_H
