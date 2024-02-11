#include "sort.h"
#include "fio.h"
#include "errs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    int *arr_b = NULL, *arr_e = NULL;
    int rc = ERR_OK;
    int filter = 0;
    FILE *fin = NULL, *fout = NULL;

    // Проверка введенных аргументов
    if (argc < 3 || argc > 4)
        rc = ERR_ARGS;
    else if (argc == 4)
    {
        if (strncmp(argv[3], "f", 2) != 0)
            rc = ERR_ARGS;
        else
            filter = 1;
    }

    // Открытие файлов
    if (!rc)
    {
        fin = fopen(argv[1], "r");
        if (fin != NULL)
        {
            fout = fopen(argv[2], "w");
            if (fout == NULL)
            {
                fclose(fin);
                fin = NULL;
                rc = ERR_FILE;
            }
        }
        else
            rc = ERR_FILE;   
    }

    // Чтение массива из файла
    if (!rc)
        rc = read_int_array(fin, &arr_b, &arr_e);
    
    // Фильтрация массива, если подано f в аргументах
    if (!rc && filter)
    {
        int *tmp_b = NULL, *tmp_e = NULL;
        rc = key(arr_b, arr_e, &tmp_b, &tmp_e);
        if (!rc)
        {
            free(arr_b);
            arr_b = tmp_b, arr_e = tmp_e;
        }
    }

    // Сортировка и вывод массива
    if (!rc)
    {
        mysort(arr_b, arr_e - arr_b, sizeof(arr_b[0]),  compare_int);
        rc = print_int_array(fout, arr_b, arr_e);
    }
    
    // Освобождение массива, если он был считан.
    if (arr_b != NULL)
        free(arr_b);
    
    // Закрытие файлов
    if (fin != NULL)
    {
        fclose(fin);
        fclose(fout);
    }
    
    return rc;
}
