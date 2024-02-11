#include "switch.h"


int switch_cols(int (*mat)[MAX_SIZE], size_t size)
{
    for (size_t j = 0; j < size / 2; j++)
    {
        for (size_t i = j; i < (size - j); i++)
        {
            int tmp = mat[i][j];
            mat[i][j] = mat[i][size - j - 1];
            mat[i][size - j - 1] = tmp;
        }
    }
    return OK;
}
