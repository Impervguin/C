#include "mat_op.h"



//int get_elems_with_sum_ten(int (*mat)[MAX_SIZE], size_t row_count, size_t col_count, size_t *arr_pos, int *arr, size_t *size)
//{
//    size_t cnt = 0;
//    for (size_t i = 0; i < row_count * col_count; i++)
//    {
//        if (digit_sum(mat[i / col_count][i % col_count]) > 10)
//        {
//            arr[cnt] = mat[i / col_count][i % col_count];
//            arr_pos[cnt] = i;
//            cnt++;
//        }
//    }
//    *size = cnt;
//    return OK;
//}

int get_elems_with_sum_ten(int (*mat)[MAX_SIZE], size_t row_count, size_t col_count, int *arr, size_t *size)
{
    size_t cnt = 0;
    for (size_t i = 0; i < row_count; i++)
    {
        for (size_t j = 0; j < col_count; j++)
        {
            if (digit_sum(mat[i][j]) > 10)
            {
                arr[cnt] = mat[i][j];
                cnt++;
            }
        }
    }
    *size = cnt;
    return OK;
}
int left_shift(int *arr, size_t size)
{
    if (size == 0)
    {
        return SIZE_ERROR;
    }

    int tmp = arr[0];
    for (size_t i = 1; i < size; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[size - 1] = tmp;
    return OK;
}

int left_shift_n(int *arr, size_t size, int n)
{
    if (size == 0)
    {
        return SIZE_ERROR;
    }
    for (int i = 0; i < n; i++)
    {
        left_shift(arr, size);
    }
    return OK;
}

int put_elems_in_mat(int (*mat)[MAX_SIZE], size_t row_count, size_t col_count, const int *arr, size_t size)
{
    size_t arr_index = 0;
    for (size_t i = 0; i < row_count; i++)
    {
        for (size_t j = 0; j < col_count; j++)
        {
            if (digit_sum(mat[i][j]) > 10)
            {
                mat[i][j] = arr[arr_index];
                arr_index++;
                if (arr_index == size)
                    break;
            }
        }
    }
    return OK;
}


//int put_elems_in_mat(int (*mat)[MAX_SIZE], size_t col_count, const size_t *arr_pos, const int *arr, size_t size)
//{
//    for (size_t i = 0; i < size; i++)
//    {
//        mat[arr_pos[i] / col_count][arr_pos[i] % col_count] = arr[i];
//    }
//    return OK;
//}
