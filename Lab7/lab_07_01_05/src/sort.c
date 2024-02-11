#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "errs.h"

void *bin_find_ind(void *start, void *end, void *elem, size_t nmemb, int (*compar)(const void*, const void*))
{
    char *st = start, *ed = end;
    while (st != ed - nmemb)
    {
        /// Переманная содержит указатель на середину нынешнего отрезка.
        /// Конструкция / nmemb * nmemb нужна, так указатель на char после вычисления указывать на какой-то внутренний байт элемента
        /// а эта конструкция округляет указатель вниз до начала элемента.
        char *now = st + ((ed - st) / 2) / nmemb * nmemb;
        int res = compar(elem, now);
        if (res >= 0)
            st = now;
        else
            ed = now;
    }
    if (compar(elem, st) >= 0)
        return ed;
    return st;
}

int compare_int(const void *a, const void *b)
{
    const int *ia = a;
    const int *ib = b;
    return (*ia > *ib) ? 1 : ((*ia == *ib) ? 0 : -1);
}

/// @brief Меняет местами два элемента размера nmemb байт
/// @param [in/out] a - Первый элемент
/// @param [in/out] b - Второй элемент
/// @param [in] nmemb - Размер элементов в байтах
void swap(void *a, void *b, size_t nmemb)
{
    char *pa = a, *pb = b;
    char tmp;
    for (size_t i = 0; i < nmemb; i++, pa++, pb++)
    {
        tmp = *pa;
        *pa = *pb;
        *pb = tmp;
    }
}

// void mysort(void *base, size_t size, size_t nmemb, int (*compar)(const void*, const void*))
// {
//     char *end = ((char *)base) + nmemb * size;
//     for (char *now = ((char *)base) + nmemb; now < end; now += nmemb)
//     {
//         char *place = bin_find_ind(base, now, now, nmemb, compar);
//         for (char *tmp = now; tmp > place; tmp -= nmemb)
//             swap(tmp, tmp - nmemb, nmemb);
//     }
// }

/// @brief Функиция, которая в последовательности байтов производит циклический сдвиг на nmemb байт вправо
/// @param base - Начало последовательности
/// @param end - Конец последовательности
/// @param nmemb - Величина сдвига
void swap_shift(void *base, void *end, size_t nmemb)
{
    char tmp[nmemb];
    char *a = base;
    char *elem = (char *) end - nmemb; 
    memcpy(tmp, elem, nmemb);
    size_t bytes = ((char *) elem - a);
    memmove(a + nmemb, a, bytes);
    memcpy(a, tmp, nmemb);
}

// Второй вариант сортировки
// void mysort(void *base, size_t size, size_t nmemb, int (*compar)(const void*, const void*))
// {
//     char *end = ((char *)base) + nmemb * size;
    // for (char *now = ((char *)base) + nmemb; now < end; now += nmemb)
    // {
    //     char *place = bin_find_ind(base, now, now, nmemb, compar);
    //     swap_shift(place, now + nmemb, nmemb);
    // }
// }

/// Сортировка выбором
void mysort(void *base, size_t size, size_t nmemb, int (*compar)(const void*, const void*))
{
    char *end = ((char *)base) + nmemb * size;
    for (char *now_place = ((char *)base); now_place < end; now_place += nmemb)
    {
        char *now_best = now_place;
        for (char *now_elem = now_place + nmemb; now_elem < end; now_elem += nmemb)
        {
            if (compar(now_elem, now_best) < 0)
                now_best = now_elem;
        }
        swap(now_place, now_best, nmemb);
    }
}
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    size_t nums = 0;
    
    if (pe_src == NULL || pb_src == NULL || pe_src - pb_src < 1)
        return ERR_ARR_EMPTY;
    int now_sum = *(pe_src - 1);
    for (const int *pa = pe_src - 2; pa >= pb_src; pa--)
    {
        if (*pa > now_sum)
            nums++;
        now_sum += *pa;
    }
    if (nums == 0)
        return ERR_ARR_EMPTY;
    int *arr_s = malloc(sizeof(int) * nums);
    if (arr_s == NULL)
        return ERR_MEMORY;
    
    int *arr_e = arr_s;
    for (const int *pa = pb_src; pa < pe_src - 1; pa++)
    {
        now_sum -= *pa;
        if (*pa > now_sum)
        {
            *arr_e = *pa;
            arr_e++;
        }
    }

    *pb_dst = arr_s;
    *pe_dst = arr_e;
    return ERR_OK;
}
