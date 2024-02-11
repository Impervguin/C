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

void *bin_find_ind(void *start, void *end, void *elem, size_t nmemb, int (*compar)(const void*, const void*))
{
    char *st = start, *ed = end;
    while (st != ed - nmemb)
    {
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

void mysort(void *base, size_t size, size_t nmemb, int (*compar)(const void*, const void*))
{
    char *end = ((char *)base) + nmemb * size;
    for (char *now = ((char *)base) + nmemb; now < end; now += nmemb)
    {
        char *place = bin_find_ind(base, now, now, nmemb, compar);
        for (char *tmp = now; tmp > place; tmp -= nmemb)
            swap(tmp, tmp - nmemb, nmemb);
    }
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
    mysort(arr, size, nmemb, compare_int);
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
