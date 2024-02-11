#include "errs.h"
#include "mat.h"
#include <stdlib.h>

double **create_matrix(size_t rows, size_t cols)
{
    double **keys = calloc(rows, sizeof(double *));
    if (keys != NULL)
    {
        keys[0] = malloc(cols * rows * sizeof(double));
        if (keys[0] == NULL)
        {
            free_matrix(keys, rows);
            return NULL;
        }
        for (size_t i = 1; i < rows; i++)
        {
            keys[i] = keys[i - 1] + cols;
        }
    }
    return keys;
}

double **create_null_matrix(size_t rows, size_t cols)
{
    double **matrix = create_matrix(rows, cols);
    if (matrix != NULL)
        for (size_t i = 0; i < rows; i++)
            for (size_t j = 0; j < cols; j++)
                matrix[i][j] = 0;
    return matrix;
}

void free_matrix(double **matrix, size_t rows)
{
    if (matrix == NULL)
        return;
    double *mmin = matrix[0];
    for (size_t i = 1; i < rows; i++)
        if (matrix[i] < mmin)
            mmin = matrix[i];
    free(mmin);
    free(matrix);
}

int read_matrix_file(FILE *f, double ***matrix, size_t *rows, size_t *cols)
{
    if (f == NULL)
        return ERR_FILE;
    
    size_t elems;
    if (fscanf(f, "%zu%zu%zu", rows, cols, &elems) != 3)
        return ERR_FORMAT;

    if (*rows == 0 || *cols == 0)
        return ERR_MATRIX_SIZE;

    *matrix = create_null_matrix(*rows, *cols);
    if (*matrix == NULL)
        return ERR_MEMORY;
    
    for (size_t i = 0; i < elems; i++)
    {
        size_t row, col;
        double elem;
        if (fscanf(f, "%zu%zu%lf", &row, &col, &elem) != 3)
        {
            free_matrix(*matrix, *rows);
            *matrix = NULL;
            return ERR_FORMAT;
        }
        if (row > *rows || row == 0 || col > *cols || col == 0)
        {
            free_matrix(*matrix, *rows);
            *matrix = NULL;
            return ERR_FORMAT;
        }
        (*matrix)[row - 1][col - 1] = elem;   
    }
    return ERR_OK;
}

int write_matrix_file(FILE *f, double **matrix, size_t rows, size_t cols)
{
    if (fprintf(f, "%zu %zu\n", rows, cols) < 0)
        return ERR_FILE;
    
    if (rows == 0 || cols == 0)
        return ERR_OK;
    
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols - 1; j++)
            if (fprintf(f, "%lf ", matrix[i][j]) < 0)
                return ERR_FILE;
        if (fprintf(f, "%lf\n", matrix[i][cols - 1]) < 0)
            return ERR_FILE;
    }
    return ERR_OK;
}
