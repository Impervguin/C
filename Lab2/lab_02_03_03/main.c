#include <stdio.h>

#define OK 0
#define IO_ERROR 1
#define SIZE_ERROR 2
#define EMPTY_ARRAY_ERROR 3
#define MAX_SIZE 10
#define AFTER_MAX_SIZE 20

int input(int *array, size_t *array_size);
void output(const int *array, size_t array_size);
int reverse_num(int num);
int add_reverse_pos(int *array, size_t *array_size);
int pos_num(const int *array, size_t array_size);

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
* Функция для реверса числа
*/
int reverse_num(int num)
{
    int rev = 0;
    while (num != 0)
    {
        rev *= 10;
        rev += num % 10;
        num /= 10;
    }
    return rev;
}

/**
* Функция для подсчета числа положительных чисел в массиве
*/
int pos_num(const int *array, size_t array_size)
{
    int num = 0;
    for (size_t i = 0; i < array_size; i++)
    {
        if (array[i] > 0)
        {
            num++;
        }
    }
    return num;
}

/**
* Функция для подстановки в массив после каждого полодительного числа его реверса
*/
int add_reverse_pos(int *array, size_t *array_size)
{
    int positive = pos_num(array, *array_size);
    if (positive == 0)
    {
        return OK;
    }

    *array_size += positive;
    // В цикле начиная с конца сдвигаем все элементы вправо на количество положительных элементов,
    // стоящих до нынешнего элемента,
    // при этом, правее каждого положительного числа оставляем место под его реверс.
    // Делаем это для освобождения места для реверсов после положительныъ чисел.
    for (int i = *array_size - positive - 1; i >= 0; i--)
    {
        if (array[i] > 0)
        {
            // Если число положительное, то следующее за ним место будет заменяно его реверсом,
            // Поэтому не заполняем его значением из массива
            positive--;
        }
        // сдвигаем нынешний элемент на positive вправо.
        array[i + positive] = array[i]; //
    }
    // После каждого положителного числа в освобожденные ячейки помещаем реверс этого числа.
    for (size_t i = 0; i < *array_size; i++)
    {
        if (array[i] > 0)
        {
            array[i + 1] = reverse_num(array[i]);
            i++;
        }
    }
     return OK;
}

/**
* Функция для добавления элемента value на позицию index
*/
int add_element(int *arr, size_t *arr_s, size_t index, int value)
{
    if (index > *arr_s)
    {
        return SIZE_ERROR;
    }
    *arr_s += 1;
    for (size_t i = *arr_s - 1; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    return OK;
}

/**
* Функция для подстановки в массив после каждого полодительного числа его реверса
 * реализованная классиеским методом, после каждого положительного элемента
 * вставляем его реверс и сразу сдвигаем все элементы.
*/
int add_reverse_pos_classic(int *array, size_t *array_size)
{
    for (size_t i = 0; i < *array_size; i++)
    {
        if (array[i] > 0)
        {
            add_element(array, array_size, i + 1, reverse_num(array[i]));
            i++;
        }
    }
    return OK;
}
int main(void)
{
    int rc;
    int array[AFTER_MAX_SIZE];

    size_t size;
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

    add_reverse_pos_classic(array, &size);
    output(array, size);
    return OK;
}
