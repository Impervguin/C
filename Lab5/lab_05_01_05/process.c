#include "process.h"

int process(FILE *f, size_t *res)
{
    int now_elem, prev_elem;
    size_t now_count = 0, max_count = 0;

    if (fscanf(f, "%d", &prev_elem) != 1)
        return NO_DATA;
    now_count = 1;
    while (fscanf(f, "%d", &now_elem) == 1)
    {
        if (now_elem == prev_elem)
            now_count++;
        else
        {
            max_count = (max_count > now_count) ? max_count : now_count;
            now_count = 1;
        }

        prev_elem = now_elem;
    }
    *res = (max_count > now_count) ? max_count : now_count;
    return OK;
}
