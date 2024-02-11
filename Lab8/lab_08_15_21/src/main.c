#include "mat.h"
#include "mat_op.h"
#include "errs.h"
#include <stdio.h>
#include <string.h>

typedef enum 
{
    ADD,
    MULT,
    INV
} action_t;

int main(int argc, char **argv)
{
    int rc = ERR_OK;
    action_t act;
    double **res = NULL;
    size_t row = 0, col;
    FILE *fin1 = NULL, *fin2 = NULL, *fout = NULL;
    if (argc > 5 || argc < 4)
        rc = ERR_ARGS;
    
    if (!rc)
    {
        if (strlen(argv[1]) != 1)
            rc = ERR_ARGS;
        else
        {
            switch (argv[1][0])
            {
                case 'a':
                    act = ADD;
                    break;
                case 'm':
                    act = MULT;
                    break;
                case 'o':
                    act = INV;
                    break;
                default:
                    rc = ERR_ACTION;
                    break;
            }
        }
    }

    if (!rc && (act == ADD || act == MULT) && argc != 5)
        rc = ERR_ARGS;
    if (!rc && act == INV && argc != 4)
        rc = ERR_ARGS;
    
    if (!rc)
    {
        fin1 = fopen(argv[2], "r");
        if (fin1 == NULL)
            rc = ERR_FILE;
        if (!rc && act == INV)
        {
            fout = fopen(argv[3], "w");
            if (fout == NULL)
                rc = ERR_FILE;
        }
        else if (!rc)
        {
            fin2 = fopen(argv[3], "r");
            fout = fopen(argv[4], "w");
            if (fout == NULL || fin2 == NULL)
                rc = ERR_FILE;
        } 
    }

    if (!rc)
    {
        double **mat1 = NULL, **mat2 = NULL;
        size_t row1 = 0, col1, row2 = 0, col2;
        switch (act)
        {
            case ADD:
                rc = read_matrix_file(fin1, &mat1, &row1, &col1);
                if (!rc)
                    rc = read_matrix_file(fin2, &mat2, &row2, &col2);
                if (!rc && (row1 != row2 || col1 != col2))
                    rc = ERR_MATRIX_SIZE;
                if (!rc)
                {
                    res = add_matrix(mat1, mat2, row1, col1);
                    row = row1;
                    col = col1;
                    if (res == NULL)
                        rc = ERR_MEMORY;
                }
                break;
            case MULT:
                rc = read_matrix_file(fin1, &mat1, &row1, &col1);
                if (!rc)
                    rc = read_matrix_file(fin2, &mat2, &row2, &col2);
                if (!rc && (row2 != col1))
                    rc = ERR_MATRIX_SIZE;
                if (!rc)
                {
                    res = mult_matrix(mat1, row1, col1, mat2, row2, col2, &row, &col);
                    if (res == NULL)
                        rc = ERR_MEMORY;
                }
                break;
            case INV:
                rc = read_matrix_file(fin1, &mat1, &row1, &col1);
                if (!rc && (row1 != col1))
                    rc = ERR_MATRIX_SIZE;
                if (!rc)
                {
                    rc = inv_matrix(mat1, &res, row1);
                    row = row1;
                    col = row1;
                }
                break;
        }
        free_matrix(mat1, row1);
        free_matrix(mat2, row2);
    }
    
    if (!rc)
        rc = write_matrix_file(fout, res, row, col);
    free_matrix(res, row);
    if (fin1 != NULL)
        fclose(fin1);
    if (fin2 != NULL)
        fclose(fin2);
    if (fout != NULL)
        fclose(fout);
    
    return rc;
}
