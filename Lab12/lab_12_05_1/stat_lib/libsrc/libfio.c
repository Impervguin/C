#include <stdio.h>
#include <stdlib.h>
#include "errs.h"
#include "fio.h"

int count_nums_in_file(FILE *f, size_t *nums)
{
    int tmp;
    *nums = 0;
    while (fscanf(f, "%d", &tmp) == 1)
        (*nums)++;
    if (!feof(f))
        return ERR_FORMAT;
    return ERR_OK;
}

int read_file_array(FILE *f, int *arr_b, int **arr_e)
{
    *arr_e = arr_b;
    for (; fscanf(f, "%d", *arr_e) == 1; (*arr_e)++);
    if (!feof(f))
        return ERR_FORMAT;
    return ERR_OK;
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
