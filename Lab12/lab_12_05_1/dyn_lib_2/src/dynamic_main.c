#include "errs.h"
#include "arr.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef int (*count_nums_in_file_t)(FILE *, size_t *);
typedef int (*read_file_array_t)(FILE *f, int *arr_b, int **arr_e);
typedef int (*print_int_array_t)(FILE *f, const int *arr_b, const int *arr_e);
typedef int (*key_t)(const int *pb_src, const int *pe_src, int *pb_dst, int **pe_dst, size_t *nums);
typedef void (*mysort_t)(void *base, size_t size, size_t nmemb, int (*compar)(const void*, const void*));
typedef int (*compare_int_t)(const void *a, const void *b);

int main(int argc, char **argv)
{
    int rc = ERR_OK;
    count_nums_in_file_t count_nums_in_file = NULL;
    read_file_array_t read_file_array = NULL;
    print_int_array_t print_int_array = NULL;
    key_t key  = NULL;
    mysort_t mysort = NULL;
    compare_int_t compare_int = NULL;

    void *sortlib = NULL, *fiolib = NULL;

    sortlib = dlopen("libsort.so", RTLD_NOW);
    fiolib = dlopen("libfio.so", RTLD_NOW);
    if (!sortlib || !fiolib)
        rc = ERR_DYNAMIC_LIBRARY;
    
    if (!rc)
    {
        count_nums_in_file = (count_nums_in_file_t) dlsym(fiolib, "count_nums_in_file");
        read_file_array = (read_file_array_t) dlsym(fiolib, "read_file_array");
        print_int_array = (print_int_array_t) dlsym(fiolib, "print_int_array");
        key = (key_t) dlsym(sortlib, "key");
        mysort = (mysort_t) dlsym(sortlib, "mysort");
        compare_int = (compare_int_t) dlsym(sortlib, "compare_int");
        if (!count_nums_in_file || !read_file_array || !print_int_array || !key || !mysort || !compare_int)
            rc = ERR_DYNAMIC_LIBRARY;
    }

    int *arr_b = NULL, *arr_e = NULL;
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

    size_t arr_size = 0;
    if (!rc)
        rc = count_nums_in_file(fin, &arr_size);
    
    if (!rc && arr_size == 0)
        rc = ERR_ARR_EMPTY;

    if (!rc)
        rc = create_int_arr(&arr_b, arr_size);

    // Чтение массива из файла
    if (!rc)
    {
        rewind(fin);
        read_file_array(fin, arr_b, &arr_e);
    }
    
    // Фильтрация массива, если подано f в аргументах
    if (!rc && filter)
    {
        int *tmp_b = NULL, *tmp_e = NULL;
        size_t filter_size = 0;
        rc = key(arr_b, arr_e, NULL, NULL, &filter_size);
        if (!rc)
            rc = create_int_arr(&tmp_b, filter_size);
        if (!rc)
            rc = key(arr_b, arr_e, tmp_b, &tmp_e, &filter_size);
        if (!rc)
        {
            free(arr_b);
            arr_b = tmp_b, arr_e = tmp_e;
        }
        else
        {
            free(tmp_b);
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

    if (sortlib)
        dlclose(sortlib);
    
    if (fiolib)
        dlclose(fiolib);
    
    return rc;
}
