#include "mat_op.h"


int fill_spiral_matrix(int (*mat)[MAX_SIZE], size_t row_count, size_t col_count)
{
    int i = 1;
    int x = 0, y = 0;
    fill_zeros_mat(mat, row_count, col_count); // Заполняем матрицу нулями
    while (i < (int)(row_count * col_count))
    {
        // Направление вниз
        // идет вниз и заполняет матрицу числами пока не доходит до границы или следующая ячейка уже заполнена
        while (y + 1 < (int)row_count && mat[y + 1][x] == 0)
        {
            mat[y][x] = i;
            // Увеличиваем число на один
            i++;
            // Идем ниже
            y++;
        }
        // Направление вправо
        // идет вправо и заполняет матрицу числами пока не доходит до границы или следующая ячейка уже заполнена
        while (x + 1 < (int)col_count && mat[y][x + 1] == 0)
        {
            mat[y][x] = i;
            // Увеличиваем число на один
            i++;
            // Идем правее
            x++;
        }
        // Направление вверх
        // идет вверх и заполняет матрицу числами пока не доходит до границы или следующая ячейка уже заполнена
        while (y - 1 >= 0 && mat[y - 1][x] == 0)
        {
            mat[y][x] = i;
            // Увеличиваем число на один
            i++;
            // Идем выше
            y--;
        }
        // Направление влево
        // идет влево и заполняет матрицу числами пока не доходит до границы или следующая ячейка уже заполнена
        while (x - 1 >= 0 && mat[y][x - 1] == 0)
        {
            mat[y][x] = i;
            // Увеличиваем число на один
            i++;
            // Идем левее
            x--;
        }
    }
    mat[y][x] = i; // Заполняем последнюю ячейку "центр"
    return OK;
}

int fill_zeros_mat(int (*mat)[MAX_SIZE], size_t row_count, size_t col_count)
{
    for (size_t i = 0; i < row_count; i++)
        for (size_t j = 0; j < col_count; j++)
            mat[i][j] = 0;
    return OK;
}
