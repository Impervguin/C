#include "mat_op.h"


int swap_arrs(int *arr1, int *arr2, size_t arr_size)
{
    for (size_t i = 0; i < arr_size; i++)
    {
        int tmp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = tmp;
    }
    return OK;
}

int find_min(const int *arr, size_t size)
{
    int m = arr[0];
    for (size_t i = 1; i < size; i++)
    {
        if (arr[i] < m)
            m = arr[i];
    }
    return m;
}

int sort_mat_rows(int (*mat)[MAX_SIZE], size_t row_count, size_t col_count)
{
    for (size_t i = 0; i < row_count - 1; i++)
    {
        size_t best_index = i;
        int mbest = find_min(mat[i], col_count);
        for (size_t j = i + 1; j < row_count; j++)
        {
            int mnow = find_min(mat[j], col_count);
            if (mnow > mbest)
            {
                best_index = j;
                mbest = mnow;
            }
        }
        swap_arrs(mat[i], mat[best_index], col_count);
    }
    return OK;
}
