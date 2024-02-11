#ifndef SORT_H__
#define SORT_H__

#include <stddef.h>

/**
 * @brief - Функция сортировки вставками с бинарным поиском
 * 
 * @param base - Указатель на начало массива
 * @param nmemb - Размер элемента массива в байтах
 * @param size - Количество элементов массива
 * @param compar - Функция сравнения элементов массива
 */
void mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));

/**
 * \brief Функция фильтрует и копирует элементы из исходного массива в новый массив. Функция фильтрует элементы в диапазоне и копирует те, которые больше суммы суммы последующих элементов,
 * в новый массив.
 *
 * \param [in] pb_src - указатель на начало исходного массива
 * \param [in] pe_src - указатель на конец исходного массива
 * \param [out] pb_dst - указатель на начало нового массива
 * \param [out] pe_dst - указатель на конец нового массива
 * 
 * \return - Код возврата
 */
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

/**
 * @brief Функция для сравнения целых чисел
 * 
 * @param a - Указатель на первое число
 * @param b - Указатель на второе число
 * @return int 1 - если первое > второго, 0 - Если равны иначе - -1
 */
int compare_int(const void *a, const void *b);

#endif // SORT_H__
