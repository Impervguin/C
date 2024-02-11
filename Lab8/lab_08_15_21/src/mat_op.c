#include <math.h>
#include "errs.h"
#include "mat_op.h"
#include "mat.h"

double **add_matrix(double **mat1, double **mat2, size_t row, size_t col)
{
    double **res = create_null_matrix(row, col);
    if (res != NULL)
        for (size_t i = 0; i < row; i++)
            for (size_t j = 0; j < col; j++)
                res[i][j] = mat1[i][j] + mat2[i][j];
    return res;
}

double **mult_matrix(double **mat1, size_t row1, size_t col1, double **mat2, size_t row2, size_t col2, size_t *res_row, size_t *res_col)
{
    if (col1 != row2)
        return NULL;
    double **res = create_matrix(row1, col2);
    double sum;
    if (res != NULL)
    {
        *res_row = row1;
        *res_col = col2;
        for (size_t i = 0; i < *res_row; i++)
        {
            for (size_t j = 0; j < *res_col; j++)
            {
                sum = 0;
                for (size_t k = 0; k < col1; k++)
                {
                    sum += mat1[i][k] * mat2[k][j];
                }
                res[i][j] = sum;
            }
        }
    }
    return res;
}

void sub_matrix_rows(double **mat, size_t row_src, size_t row_dst, size_t cols, double mult)
{
    for (size_t i = 0; i < cols; i++)
        mat[row_dst][i] -= mat[row_src][i] * mult; 
}

void mult_row(double **mat, size_t row, size_t cols, double mult)
{
    for (size_t i = 0; i < cols; i++)
        mat[row][i] *= mult;
}

void swap_rows(double **mat, size_t row1, size_t row2)
{
    double *tmp = mat[row1];
    mat[row1] = mat[row2];
    mat[row2] = tmp;
}

void swap_cols(double **mat, size_t rows, size_t col1, size_t col2)
{
    double tmp;
    for (size_t i = 0; i < rows; i++)
    {
        tmp = mat[i][col1];
        mat[i][col1] = mat[i][col2];
        mat[i][col2] = tmp;
    }
}

int check_double_null(double a)
{
    return (a < EPS && a > -EPS) ? 1 : 0;
}

int inv_matrix(double **mat, double ***res, size_t size)
{
    /// Создаем результирующую матрицу
    double **tres = create_null_matrix(size, size);
    if (tres == NULL)
        return ERR_MEMORY;

    // Создаем допольнительную матрицу, чтобы не испортить исходную
    double **tmp = create_null_matrix(size, size);
    if (tmp == NULL)
    {
        free_matrix(tres, size);
        return ERR_MEMORY;
    }
        
    
    int rc = ERR_OK;
    /// Делаем результирующую единичкной
    for (size_t i = 0; i < size; i++)
        tres[i][i] = 1;
    /// Копируем элементы из исходной в дополнительную
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < size; j++)
            tmp[i][j] = mat[i][j];
    
    // Прямой ход
    for (size_t i = 0; i < size; i++)
    {
        if (check_double_null(tmp[i][i]))
        {
            size_t max_i = i;
            /// Если i-й элемент на диагонали нулевой, то ищем столбец правее данного с ненулевым элементом в i-ой строке
            for (size_t j = i + 1; j < size; j++)
                if (fabs(tmp[i][j]) > fabs(tmp[i][max_i]))
                    max_i = j;
            
            if (!check_double_null(tmp[i][max_i]))
            {
                swap_cols(tmp, size, i, max_i);
                swap_cols(tres, size, i, max_i);
            }
            /// Если не нашли столбец, то имеем, что i-я строка - нулевая, а значит определитель матрицы равен нулю и у нее не существует обратный
            if (check_double_null(tmp[i][i]))
            {
                rc = ERR_NO_INV_MATRIX;
                break;
            }
        }
        
        /// Умножаем i-ю строку матриц на элемент обратный i-ному диагональному, при этом приводя его к 1
        mult_row(tres, i, size, (1 / tmp[i][i]));
        mult_row(tmp, i, size, (1 / tmp[i][i]));
        tmp[i][i] = 1;

        /// Вычитая из j-ных строк нынешнюю зануляем i-ный столбец после i-ной строки
        for (size_t j = i + 1; j < size; j++)
        {
            /// Из j-ной строки вычитаем i-ную умноженную на элемент i-ного столбца в j-ной строке, чтобы занулить tmp[j][i] 
            sub_matrix_rows(tres, i, j, size, tmp[j][i]);
            sub_matrix_rows(tmp, i, j, size, tmp[j][i]);
            tmp[j][i] = 0;
        }
    }
    /// После этих преобразований в tmp получилась верхняя диагональная матрица

    /// Вычитанием строк приведем её к единичной 
    // Обратный ход
    if (!rc)
    {
        for (int i = size - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                sub_matrix_rows(tres, i, j, size, tmp[j][i]);
                sub_matrix_rows(tmp, i, j, size, tmp[j][i]);
                tmp[j][i] = 0;
            }
        }
    }

    /// Допольнительная матрица является единичной и больше не нужна.
    free_matrix(tmp, size);
    if (rc)
        free_matrix(tres, size);
    /// В результате в tres получилась матрица обратная данной
    if (!rc)
        *res = tres;
    return rc;
}
