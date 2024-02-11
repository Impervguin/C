#include <stdbool.h>
#include "mono.h"



int check_array_monotonic(const int *arr, size_t arr_size)
{
    bool incr = false;
    bool defined_mono = false;
    if (arr_size == 1)
        return NOT_MONO;
    for (size_t i = 0; i < arr_size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            if (!defined_mono)
            {
                defined_mono = true;
                incr = false;
            }
            else if (incr)
                return NOT_MONO;
        }
        else if (arr[i] < arr[i + 1])
        {
            if (!defined_mono)
            {
                defined_mono = true;
                incr = true;
            }
            else if (!incr)
                return NOT_MONO;
        }
    }
    return MONO;
}



int check_monotonic(int (*mat)[MAX_SIZE], size_t row_count, size_t col_count, int *res)
{
    for (size_t i = 0; i < row_count; i++)
    {
        res[i] = check_array_monotonic(mat[i], col_count);
    }
    return OK;
}

