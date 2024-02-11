#include <stdio.h>
#include <stdbool.h>

#define OK 0
#define IO_ERROR 1
#define SIZE_ERROR 2
#define EMPTY_ARRAY_ERROR 3
#define NO_ARMSTRONG 4
#define MAX_SIZE 10

int input(int *array, size_t *array_size);
void output(const int *array, size_t array_size);
bool is_armstrong(int num);
int number_length(int num);
int int_pow(int num, int degree);
int form_without_armstrong(const int *array, size_t array_size, int *new_array, size_t *new_size);


/**
* Функция для ввода массива
*/
int input(int *array, size_t *array_size)
{
    int rc;
    printf("Enter array size: ");
    rc = scanf("%zu", array_size);
    if (rc != 1)
    {
        return IO_ERROR;
    }
    if (*array_size == 0)
    {
        return EMPTY_ARRAY_ERROR;
    }
    if (*array_size > MAX_SIZE)
    {
        return SIZE_ERROR;
    }
    for (size_t i = 0; i < *array_size; ++i)
    {
        printf("Enter array element: ");
        rc = scanf("%d", &array[i]);
        if (rc != 1)
        {
            return IO_ERROR;
        }
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
* Функция для вычисления длины целого, положительного числа
*/
int number_length(int num)
{
    int len = 0;
    if (num == 0)
    {
        len = 1;
    }
    while (num > 0)
    {
        len++;
        num /= 10;
    }
    return len;
}


/**
* Функция для вычисления целого числа в натуральной степени degree
*/
int int_pow(int num, int degree)
{
    int p = 1;
    while (degree != 1)
    {
        if (degree % 2 == 0)
        {
            num *= num;
            degree /= 2;
        }
        else
        {
            p *= num;
            degree -= 1;
        }
    }
    return num * p;
}


/**
* Функция для проверки числа на то, что оно является числом армстронга
*/
bool is_armstrong(int num)
{
    int len = number_length(num);
    int s = 0, tmp = num;
    
    while (tmp > 0)
    {
        s += int_pow(tmp % 10, len);
        tmp /= 10;
    }
    if (s == num)
    {
        return true;
    }
    return false;
}

/**
* Функция для формирования массива только из чисел армстронга
*/
int form_armstrong(const int *array, size_t array_size, int *new_array, size_t *new_size)
{
    size_t j = 0;
    for (size_t i = 0; i < array_size; i++)
    {
        if (array[i] >= 0 && is_armstrong(array[i]))
        {
            new_array[j] = array[i];
            j += 1;
        }
    }
    if (j == 0)
    {
        return NO_ARMSTRONG;
    }
    *new_size = j;
    return OK;
}

int main(void)
{
    int rc;
    int array[MAX_SIZE], new_array[MAX_SIZE];

    size_t size, new_size;
    rc = input(array, &size);
    
    if (rc == IO_ERROR)
    {
        printf("Wrong input.");
        return rc;
    }
    
    if (rc == SIZE_ERROR)
    {
        printf("Array size cannot be that high.");
        return rc;
    }
    
    if (rc == EMPTY_ARRAY_ERROR)
    {
        printf("Empty array.");
        return rc;
    }

    rc = form_armstrong(array, size, new_array, &new_size);
    if (rc == NO_ARMSTRONG)
    {
        printf("No armstrong numbers.");
        return rc;
    }
    output(new_array, new_size);
    return OK;
}
