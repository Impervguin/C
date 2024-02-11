#include <stdio.h>
#include <stdbool.h>
#include "io.h"
#include "mat_op.h"
#include "sizes.h"
#include "errors.h"



int main(void)
{
    int mat[MAX_SIZE][MAX_SIZE];
    size_t row_count, col_count;
    int rc;

    rc = size_input(&row_count, &col_count);
    if (rc == OK)
        if (col_count != row_count)
            rc = NOT_SQUARE_MATRIX;

    if (rc == OK)
    {
        fill_spiral_matrix(mat, row_count, col_count);
        output_matrix(mat, row_count, col_count);
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
        default:
            printf("Unknown error");
            break;
    }
    return rc;
}
