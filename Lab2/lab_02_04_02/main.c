#include <stdio.h>
#include <stdbool.h>

#define OK 0
#define MAX_SIZE_CODE 100
#define IO_ERROR 1
#define SIZE_ERROR 2
#define EMPTY_ARRAY_ERROR 3
#define MAX_SIZE 10


int input(int *array, size_t *array_size);
void output(const int *array, size_t array_size);

/**
* Функция для ввода массива по концевому признаку
*/
int input(int *array, size_t *array_size)
{
    int rc;
    int tmp;
    *array_size = 0;
    printf("Enter array element: ");
    rc = scanf("%d", &tmp);
    while (rc == 1)
    {
        if ((*array_size) >= MAX_SIZE)
        {
            return MAX_SIZE_CODE;
        }
        array[*array_size] = tmp;
        (*array_size)++;
        printf("Enter array element: ");
        rc = scanf("%d", &tmp);
    }
    if (*array_size == 0)
    {
        return EMPTY_ARRAY_ERROR;
    }
    return OK;
}

/**
* Функция для вывода массива
*/
void output(const int *a, size_t n)
{
    if (n == 0)
    {
        printf("Empty array");
    }
    else
    {
        printf("Array:\n");
        for (size_t i = 0; i < n; ++i)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}

/**
* Сортировка выбором
*/
int choice_sort(int *array, int array_size)
{
    for (int i = 0; i < array_size - 1; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < array_size; j++)
        {
            if (array[min_ind] > array[j])
            {
                min_ind = j;
            }
        }
        if (min_ind != i)
        {
            int tmp = array[min_ind];
            array[min_ind] = array[i];
            array[i] = tmp;
        }
    }
    return OK;
}

int main(void)
{
    int rc;
    int array[MAX_SIZE];

    size_t size;
    rc = input(array, &size);

    if (rc == EMPTY_ARRAY_ERROR)
    {
        printf("Empty array.");
        return rc;
    }

    choice_sort(array, size);
    output(array, size);
    return rc;
}
