#include "io.h"

int open_read_file(char *fname, FILE **f)
{
    *f = fopen(fname, "r");
    if (*f == NULL)
        return FILE_NOT_FOUND_ERROR;
    return OK;
}
