#include <stddef.h>
#include <stdlib.h>
#include "errs.h"


int create_int_arr(int **arr, size_t nums)
{
    *arr = malloc(sizeof(int) * nums);
    if (*arr == NULL)
        return ERR_MEMORY;
    return ERR_OK;
}
