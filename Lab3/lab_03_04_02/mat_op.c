#include "mat_op.h"


int find_max_under_secondary_diag(int (*mat)[MAX_SIZE], size_t size, int *num)
{
    if (size < 2)
    {
        return NOT_FOUND;
    }
    bool found_any = false;
    int now_max;
    for (size_t i = 1; i < size; i++)
    {
        for (size_t j = size - i; j < size; j++)
        {
            int now_num = mat[i][j];
            if (now_num < 0)
                now_num = -now_num;
            if (now_num % 10 == 5)
            {
                if (!found_any)
                {
                    found_any = true;
                    now_max = mat[i][j];
                }
                if (now_max < mat[i][j])
                    now_max = mat[i][j];
            }
        }
    }
    *num = now_max;
    if (!found_any)
        return NOT_FOUND;
    return OK;
}
