#include <stdio.h>
#include <stdbool.h>
#include "io.h"
#include "mat_op.h"
#include "sizes.h"
#include "errors.h"


int main(void)
{
    int mat[MAX_SIZE][MAX_SIZE], num;
    size_t col_count, row_count;
    int rc;

    rc = mat_input(mat, &row_count, &col_count);
    if (rc == OK)
        if (col_count != row_count)
            rc = NOT_SQUARE_MATRIX;

    if (rc == OK)
    {
        rc = find_max_under_secondary_diag(mat, row_count, &num);
        if (rc == OK)
            num_output(num);
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
        case NOT_SQUARE_MATRIX:
            printf("Not square matrix.");
            break;
        case NOT_FOUND:
            printf("Can't find num with last digit five under secondary diagonal");
            break;
        default:
            printf("Unknown error");
            break;
    }
    return rc;
}
