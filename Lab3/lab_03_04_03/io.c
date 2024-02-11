#include "io.h"


int mat_input(int (*mat)[MAX_SIZE], size_t *row_count, size_t *col_count)
{
    int rc;
    printf("Enter row count: ");
    rc = scanf("%zu", row_count);
    if (rc != 1)
        return IO_ERROR;

    if (*row_count > MAX_SIZE)
        return SIZE_ERROR;

    printf("Enter columns count: ");
    rc = scanf("%zu", col_count);
    if (rc != 1)
        return IO_ERROR;

    if (*col_count > MAX_SIZE)
        return SIZE_ERROR;

    if (*col_count == 0 || *row_count == 0)
        return EMPTY_MATRIX_ERROR;

    for (size_t i = 0; i < *row_count; i++)
    {
        for (int *pa = mat[i]; pa < mat[i] + *col_count; pa++)
        {
            printf("Enter next element: ");
            rc = scanf("%d", pa);
            if (rc != 1)
            {
                return IO_ERROR;
            }
        }
    }
    return OK;
}

int output_matrix(int (*mat)[MAX_SIZE], size_t row_count, size_t col_count)
{
    printf("Matrix:\n");
    for (size_t j = 0; j < row_count; j++)
    {
        for (size_t i = 0; i < col_count; i++)
        {
            printf("%d ", mat[j][i]);
        }
        printf("\n");
    }
    return OK;
}

