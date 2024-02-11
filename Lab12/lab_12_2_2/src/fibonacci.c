#include <stddef.h>
#include "fibonacci.h"


int fill_fibonacci_arr(int *arr, size_t count)
{
    if (count <= 0 || !arr)
        return ERR_ARGS_FIB;
    arr[0] = 0;
    if (count <= 1)
        return OK;
    arr[1] = 1;
    size_t asize = 2;
    for (; asize < count; asize++)
        arr[asize] = arr[asize - 1] + arr[asize - 2];
    return OK;
}