#include "io.h"

int f_read_str(FILE *f, char *str, size_t read_len)
{
    if (fgets(str, read_len, f) == NULL)
    {
        return FIO_ERROR;
    }
    size_t len = strlen(str);
    if (str[len - 1] != '\n')
        return STRING_SIZE_ERROR;

    str[--len] = '\0';
    if (len == 0)
        return STRING_SIZE_ERROR;
    return OK;
}

int f_read_uint(FILE *f, uint32_t *num)
{
    if (fscanf(f, "%u", num) == 1)
        return OK;
    return FIO_ERROR;
}

void fb_print_struct(FILE *f)
{
    struct product_t tmp;
    while (fread(&tmp, sizeof(tmp), 1, f) == 1)
    {
        print_product(&tmp);
    }
}
