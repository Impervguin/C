#include <stdio.h>
#include <stdlib.h>
#include "errs.h"
#include "fio.h"

/**
 * @brief Функция для подсчета количество чисел в файле
 * 
 * @param [in] f - Файл
 * @param [out] nums - Указатель на количество
 * @return int Код возврата
 */
static int count_nums_in_file(FILE *f, size_t *nums)
{
    int tmp;
    *nums = 0;
    while (fscanf(f, "%d", &tmp) == 1)
        (*nums)++;
    if (!feof(f))
        return ERR_FORMAT;
    return ERR_OK;
}

/**
 * @brief Функция для динамического создания массива целых
 * 
 * @param [out] arr - Указатель на массив
 * @param [in] nums - Количество элементов массива
 * @return int Код возврата
 */
static int create_int_arr(int **arr, size_t nums)
{
    *arr = malloc(sizeof(int) * nums);
    if (*arr == NULL)
        return ERR_MEMORY;
    return ERR_OK;
}

/**
 * @brief Функция для ввода массива целых чисел из файла
 * 
 * @param [in] f - Файл
 * @param [in] arr_b - Указатель на начало массива
 * @param [out] arr_e - Указатель на конец массива
 * @param [in] nums - Количество чисел для ввода
 * @return int - Код возврата
 */
static int read_file_array(FILE *f, int *arr_b, int *arr_e)
{
    for (int *arr_now = arr_b; arr_now < arr_e; arr_now++)
        if (fscanf(f, "%d", arr_now) != 1)
            return ERR_IO;
    return ERR_OK;
}

int read_int_array(FILE *f, int **arr_b, int **arr_e)
{
    size_t nums;
    int rc = count_nums_in_file(f, &nums);
    
    if (!rc && nums == 0)
        rc = ERR_FILE_EMPTY;
    
    if (!rc)
    {
        rc = create_int_arr(arr_b, nums);
        
        if (!rc)
        {
            rewind(f);
            *arr_e = *arr_b + nums;
            rc = read_file_array(f, *arr_b, *arr_e);    
            if (rc)
                free(*arr_b);
        }        
    }
    return rc;
}


int print_int_array(FILE *f, const int *arr_b, const int *arr_e)
{
    int rc = ERR_OK;

    for (const int *pa = arr_b; pa < arr_e - 1 && !rc; pa++)
    {
        if (fprintf(f, "%d ", *pa) < 0)
            rc = ERR_IO;
    }
    if (arr_b != arr_e)
        if (fprintf(f, "%d\n", *(arr_e - 1)) < 0)
            rc = ERR_IO;
    return rc;
}
