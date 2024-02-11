#include "delete.h"
#include "numbers.h"



int delete_element(int *arr, size_t *arr_size, size_t index)
{
    if (index >= *arr_size)
        return SIZE_ERROR;
    for (size_t i = index; i < *arr_size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    *arr_size -= 1;
    return OK;
}

int delete_column(int (*mat)[MAX_SIZE], size_t row_count, size_t *col_count, size_t index)
{
    if (index > *col_count)
        return SIZE_ERROR;

    for (size_t i = 0; i < row_count; i++)
    {
        size_t tmp_size = *col_count;
        delete_element(mat[i], &tmp_size, index);
    }

    *col_count -= 1;
    return OK;
}

int delete_cols_with_digit_in_num(int (*mat)[MAX_SIZE], size_t row_count, size_t *col_count, int digit)
{
    for (size_t i = 0; i < row_count; i++)
    {
        for (size_t j = 0; j < *col_count; j++)
        {
            if (check_digit_in_num(mat[i][j], digit))
            {
                delete_column(mat, row_count, col_count, j);
                j--;
            }
        }
    }
//    size_t j = 0
//    while (j < *col_count)
//    {
//        for (size_t i = 0; i < row_count; i++)
//        {
//            if (check_digit_in_num(mat[i][j], digit))
//            {
//                delete_column(mat, row_count, col_count, j);
//                i = 0
//            }
//        }
//        j++;
//    }
    return OK;
}
