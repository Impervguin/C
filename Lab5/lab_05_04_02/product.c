#include "product.h"

void print_product(struct product_t *product)
{
    printf("%s\n", product->name);
    printf("%s\n", product->manufacturer);
    printf("%u\n", product->price);
    printf("%u\n", product->count);
}

int read_product_text(FILE *f, struct product_t *product)
{
    int rc = OK;
    char tmp[2];
    rc = f_read_str(f, product->name, NAME_LEN);
    if (rc == OK)
    {
        rc = f_read_str(f, product->manufacturer, MANUFACTURER_LEN);
    }
    if (rc == OK)
    {
        rc = f_read_uint(f, &(product->price));
    }
    if (rc == OK)
    {
        rc = f_read_uint(f, &(product->count));
    }
    f_read_str(f, tmp, 2);
    return rc;
}

int read_products_text(FILE *f, struct product_t *arr, size_t *arr_size)
{
    int rc = OK;
    *arr_size = 0;
    while ((rc = read_product_text(f, &(arr[*arr_size]))) == OK)
        (*arr_size)++;
    return OK;
}

int find_end_substr_product(const char *substr, const struct product_t *arr, size_t arr_size, struct product_t *n_arr, size_t *n_arr_size)
{
    *n_arr_size = 0;
    size_t sub_len = strlen(substr);
    for (size_t i = 0; i < arr_size; i++)
    {
        size_t len = strlen(arr[i].name);
        if (len > sub_len)
        {
            size_t start = len - sub_len;
            if (strcmp(substr, &arr[i].name[start]) == 0)
            {
                n_arr[(*n_arr_size)++] = arr[i];
            }
        }
    }
    return OK;
}

int fb_get_struct_by_pos(FILE *f, struct product_t *product, long index)
{
    if (fseek(f, index * sizeof(*product), SEEK_SET) == 0)
    {
        if (fread(product, sizeof(*product), 1, f) == 1)
        {
            return OK;
        }
    }
    return FIO_ERROR;
}

int fb_add_struct(FILE *f, struct product_t *product)
{
    if (fseek(f, 0, SEEK_END) == 0)
    {
        if (fwrite(product, sizeof(*product), 1, f) == 1)
        {
            return OK;
        }
    }
    return FIO_ERROR;
}

int fb_struct_count(FILE *f, long *count)
{
    if (fseek(f, 0, SEEK_END) == 0)
    {
        long size = ftell(f);
        if (size % sizeof(struct product_t) != 0)
            return FILE_SIZE_ERROR;
        *count = size / sizeof(struct product_t);
        return OK;
    }
    return FIO_ERROR;
}
int struct_cmp(struct product_t *prod1, struct product_t *prod2)
{
    if (prod1->price == prod2->price)
    {
        if (prod1->count == prod2->count)
            return 0;
        else if (prod1->count > prod2->count)
            return 1;
        else
            return -1;
    }
    else if (prod1->price > prod2->price)
        return 1;
    else
        return -1;
}

int fb_sort_product(FILE *fin, FILE *fout)
{
    long count;
    int rc;
    struct product_t best;
    long best_ind;
    int was_arr[MAXNUM];
    rc = fb_struct_count(fin, &count);
    if (count <= 0)
        rc = FILE_SIZE_ERROR;
    if (rc == OK)
    {
        for (long i = 0; i < count; i++)
            was_arr[i] = 0;
        for (long i = 0; i < count && rc == OK; i++)
        {
            struct product_t now;
            best_ind = 0;
            for (;was_arr[best_ind];best_ind++);
            rc = fb_get_struct_by_pos(fin, &best, best_ind);
            for (long j = 1; j < count && rc == OK; j++)
            {
                rc = fb_get_struct_by_pos(fin, &now, j);
                if (rc == OK)
                {
                    if (struct_cmp(&now, &best) > 0 && ! was_arr[j])
                    {
                        best = now;
                        best_ind = j;
                    }
                }
            }
            if (rc == OK)
            {
                rc = fb_add_struct(fout, &best);
                was_arr[best_ind] = 1;
            }
        }
    }
    return rc;
}
