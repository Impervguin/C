#include <stddef.h>
#include <assert.h>
#include "arr.h"


/**
 * @brief Функция для поиска числа в массиве.
 * 
 * @param [in] arr - Массив.
 * @param [in] asize - Размер массива.
 * @param [in] elem - Искомый элемент.
 * @return int - 1 если найден, иначе - 0.
 */
static int find_elem(int *arr, size_t asize, int elem)
{
    if (!arr || asize <= 0)
        return 0;
    for (size_t j = 0; j < asize; j++)
        if (elem == arr[j])
            return 1;
    return 0;
}

/**
 * @brief Функция для подсчета кол-ва уникальных элементов в массиве.
 * 
 * @param [in] arr - Массив.
 * @param [in] asize - Размер массива.
 * @return size_t - Кол-во уникальных элементов массива.
 */
static size_t count_uniq_elems(int *arr, size_t asize) 
{
    if (asize == 0)
        return 0;
    int res = 0;
    for (size_t i = 0; i < asize; i++)
        if (!find_elem(arr, i, arr[i])) 
            res += 1;
    return res;
}

int extend_w_uniq(int *dst, size_t dst_size, size_t max_dst_size, int *src, size_t src_size, size_t *res_size)
{
    if (!src || src_size == 0 || res_size == NULL)
        return ERR_ARGS_ARR;
    *res_size = dst_size + count_uniq_elems(src, src_size);
    if (!dst || max_dst_size < *res_size)
        return ERR_SIZES_ARR;
    
    for (size_t i = 0; i < src_size; i++)
    {
        if (!find_elem(src, i, src[i]))
            dst[dst_size++] = src[i];
    }
    return OK;
}
