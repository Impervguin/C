#include <stdio.h>

#define OK 0
#define IO_ERROR 1
#define SIZE_ERROR 2
#define EMPTY_ARRAY_ERROR 3
#define MIN_SIZE 2
#define MAX_SIZE 10

int input(int *const *arr_start, int **arr_end);

/**
* Функция для ввода массива задающегося указателями на начало и конец
*/
int input(int *const *arr_start, int **arr_end)
{
    int rc;
    size_t arr_size;
    printf("Enter array size: ");
    rc = scanf("%zu", &arr_size);
    if (rc != 1)
    {
        return IO_ERROR;
    }
    if (arr_size > MAX_SIZE)
    {
        return SIZE_ERROR;
    }

    *arr_end = *arr_start + arr_size;

    for (int *pa = *arr_start; pa != *arr_end; pa++)
    {
        printf("Enter array element: ");
        rc = scanf("%d", pa);
        if (rc != 1)
        {
            return IO_ERROR;
        }
    }
    return OK;
}

/**
 * Нахождение min(a[0] * a[1], ..., a[n - 2] * a[n - 1]),
 * где a[i] - i-ный элемент массива, а n - длина массива
*/
int func(const int *const arr_start, const int *const arr_end, int *res)
{
    *res = (*arr_start) * (*(arr_start + 1));

    if ((arr_end - arr_start) < MIN_SIZE)
    {
        return EMPTY_ARRAY_ERROR;
    }
    for (const int *pa = (arr_start + 1); pa != arr_end - 1; pa++)
    {
        int now = (*pa) * (*(pa + 1));
        if (now < *res)
        {
            *res = now;
        }
    }
    return OK;
}

int main(void)
{
    int rc, res;
    int a[MAX_SIZE];
    int *arr_start = a, *arr_end = a;
    rc = input(&arr_start, &arr_end);

    if (rc == IO_ERROR)
    {
        printf("Wrong input.");
        return rc;
    }
    if (rc == SIZE_ERROR)
    {
        printf("Array size cannot be that high.");
        return SIZE_ERROR;
    }

    if ((arr_end - arr_start) < MIN_SIZE)
    {
        printf("Wrong input.");
        return EMPTY_ARRAY_ERROR;
    }

    rc = func(arr_start, arr_end, &res);
    if (rc == EMPTY_ARRAY_ERROR)
    {
        printf("Wrong input.");
        return EMPTY_ARRAY_ERROR;
    }
    printf("Minimal composition: %d\n", res);
    return OK;
}
