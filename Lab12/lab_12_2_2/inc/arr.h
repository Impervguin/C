#ifndef ARR_H__
#define ARR_H__

#include <stddef.h>

#define OK 0
#define ERR_ARGS_ARR 2
#define ERR_SIZES_ARR 1

/**
 * @brief Функция для объединения массивов, при этом в первый массив помещатся первые вхождения элементов второго массива.
 * В случае, если не хватает места в первом массиве, или вместо него подан NULL, просто возвращает необходимый размер первого для объединения.
 * @param [in/out] dst - Первый массив.
 * @param [in] dst_size - Количество элементов в первом массиве.
 * @param [in] max_dst_size - Размер первого массива.
 * @param [in] src - Второй массив.
 * @param [in] src_size - Количество элементов во втором массиве.
 * @param [out] res_size - Указатель на количество элементов в объеденённом массиве, или необходимый размер, если в первом массиве не хватает места
 * @return OK - успешное объединение, ERR_SIZES - недостаточно места в массиве или вызов для определения размера, ERR_ARGS - неккоректные аргументы.
 */
int extend_w_uniq(int *dst, size_t dst_size, size_t max_dst_size, int *src, size_t src_size, size_t *res_size);

#endif // ARR_H__
