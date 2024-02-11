#include <stdio.h>
#include <stdbool.h>
#include "sizes.h"
#include "errors.h"
#include "io.h"
#include "mono.h"


int main(void)
{
    int mat[MAX_SIZE][MAX_SIZE];
    size_t row_count, col_count;
    int res[MAX_SIZE];
    int rc;

    rc = mat_input(mat, &row_count, &col_count);
    if (rc == OK)
    {
        check_monotonic(mat, row_count, col_count, res);
        output_arr(res, row_count);
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
        default:
            printf("Unknown error");
            break;
    }
    return rc;
}
