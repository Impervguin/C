#include <stdio.h>
#include <stdbool.h>
#include "io.h"
#include "delete.h"
#include "numbers.h"
#include "errors.h"
#include "sizes.h"


int main(void)
{
    int mat[MAX_SIZE][MAX_SIZE];
    size_t row_count, col_count;
    int rc, digit;

    rc = mat_input(mat, &row_count, &col_count);
    if (rc == OK)
    {
        rc = input_digit(&digit);
        if (rc == OK)
        {
            rc = delete_cols_with_digit_in_num(mat, row_count, &col_count, digit);
            if (col_count == 0)
                rc = EMPTY_RESULT_ERROR;
            if (rc == OK)
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
        case EMPTY_RESULT_ERROR:
            printf("Empty matrix.");
            break;
        default:
            printf("Unknown error");
            break;
    }
    return rc;
}
