#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include "errors.h"


#ifndef maxnum
#error No maxnum
#endif

#ifndef best
#error No BEST
#endif

int compare_int(const void *a, const void *b)
{
    const int *ia = a;
    const int *ib = b;
    return (*ia > *ib) ? 1 : ((*ia == *ib) ? 0 : -1);
}

/**
 * Заполняет матрицу случайными числами
 * @param[out] arr - массив
 * @param[in] size - Количество элементов массива
 * @return Код возврата
 */
int gen_rand_arr(int *arr, size_t size);

/**
 * Вычисляет промежуток времени в микросекундах
 * @param[in] time_s - Начальный момент времени
 * @param[in] time_e - Конечный момент времени
 * @return Промежуток времени в микросекундах
 */
long int get_time(struct timeval *time_s, struct timeval *time_e)
{
    return (time_e->tv_sec * 1000000 + time_e->tv_usec) - (time_s->tv_sec * 1000000 + time_s->tv_usec);
}

int gen_best_arr(int *arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
        arr[i] = i;
    return OK;
}

int gen_worst_arr(int *arr, size_t size)
{
    for (size_t i = size; i > 0; i--)
        arr[i] = i - 1;
    return OK;
}

int arr[maxnum];
int main(int argc, char **argv)
{
    if (argc != 2)
        return IO_ERROR;
    long int res;
    struct timeval time_s, time_e;

    size_t size = atoi(argv[1]);
    if (best >= 1)
        gen_best_arr(arr, size);
    else if (best == 0)
        gen_rand_arr(arr, size);
    else
        gen_worst_arr(arr, size);

    size_t nmemb = sizeof(arr[0]);
    gettimeofday(&time_s, NULL);
    qsort(arr, size, nmemb, compare_int);
    gettimeofday(&time_e, NULL);

    res = get_time(&time_s, &time_e);
    printf("%ld\n", res);
    return OK;
}

int gen_rand_arr(int *arr, size_t size)
{
    srand(maxnum);
    for (size_t i = 0; i < size; i++)
        arr[i] = rand();
    return OK;
}
