#ifndef ARR_H__
#define ARR_H__

#include <stddef.h>

/**
 * @brief Функция для динамического создания массива целых
 * 
 * @param [out] arr - Указатель на массив
 * @param [in] nums - Количество элементов массива
 * @return int Код возврата
 */
int create_int_arr(int **arr, size_t nums);

#endif // ARR_H__
