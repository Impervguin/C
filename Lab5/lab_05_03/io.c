#include "io.h"

int open_bin_read_file(const char *fname, FILE **f)
{
    *f = fopen(fname, "rb");
    if (*f == NULL)
        return FILE_NOT_FOUND_ERROR;
    return OK;
}

int open_bin_write_file(const char *fname, FILE **f)
{
    *f = fopen(fname, "wb");
    if (*f == NULL)
        return FILE_NOT_FOUND_ERROR;
    return OK;
}

int open_bin_read_append_file(const char *fname, FILE **f)
{
    *f = fopen(fname, "r+b");
    if (*f == NULL)
        return FILE_NOT_FOUND_ERROR;
    return OK;
}

void output_array(const int *arr, size_t size)
{
    printf("Array: ");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
