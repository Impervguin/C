#include <stdio.h>
#include "io.h"
#include "mat_op.h"
#include "sizes.h"
#include "errors.h"



int main(void)
{
    int mat[MAX_SIZE][MAX_SIZE];
    size_t row_count, col_count;
    int arr[MAX_ELEMS_COUNT];
    size_t arr_size;
    int rc;

    rc = mat_input(mat, &row_count, &col_count);

    if (rc == OK)
    {
        get_elems_with_sum_ten(mat, row_count, col_count, arr, &arr_size);
        if (arr_size == 0)
            rc = NO_ELEMENTS;
        if (rc == OK)
        {
            left_shift_n(arr, arr_size, 3);
            put_elems_in_mat(mat, row_count, col_count, arr, arr_size);
            output_matrix(mat, row_count, col_count);
        }
    }

    switch (rc)
    {
        case OK:
            break;
        case IO_ERROR:
            printf("Wrong input.");
            break;
        case SIZE_ERROR:
            printf("Matrix size cannot be that high.");
            break;
        case EMPTY_MATRIX_ERROR:
            printf("Empty array.");
            break;
        case NO_ELEMENTS:
            printf("No elements with digit sum ten");
            break;
        default:
            printf("Unknown error");
            break;
    }
    return rc;
}
