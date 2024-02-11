#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "product.h"

#define OK 0
#define WRONG_ARRS 1
#define FILE_ERR 2

#define NAME_LEN (30 + 1)
#define MANUFACTURER_LEN (15 + 1)

//struct product_t
//{
//    char name[NAME_LEN];
//    char manufacturer[MANUFACTURER_LEN];
//    uint32_t price;
//    uint32_t count;
//};

/**
 * Функция которая переводит текстовый файл в бинарный. Как будет переведено зависит от задачи
 * @param [in] fin - Текстовый файл
 * @param [out] fbout - Бинарный файл
 * @return Код возврата
 */
int text_to_bin(FILE *fin, FILE *fbout);
/**
 * Функция которая переводит бинарный файл в текстовый. Как будет переведено зависит от задачи
 * @param [in] fbin - Бинарный файл
 * @param [out] fout - Текстовый файл
 * @return Код возврата
 */
int bin_to_text(FILE *fbin, FILE *fout);


int main(int argc, char **argv)
{
    if (argc != 4)
        return WRONG_ARRS;
    if (strcmp(argv[1], "t2b") == 0)
    {
        FILE *fin = fopen(argv[2], "r");
        FILE *fbout = fopen(argv[3], "wb");
        if (fin == NULL || fbout == NULL)
        {
            return FILE_ERR;
        }
        int rc = text_to_bin(fin, fbout);
        fclose(fin);
        fclose(fbout);
        if (rc != OK)
            return rc;
    }
    else if (strcmp(argv[1], "b2t") == 0)
    {
        FILE *fbin = fopen(argv[2], "rb");
        FILE *fout = fopen(argv[3], "w");
        if (fbin == NULL || fout == NULL)
        {
            return FILE_ERR;
        }
        int rc = bin_to_text(fbin, fout);
        fclose(fbin);
        fclose(fout);
        if (rc != OK)
            return rc;
    }
    else
        return WRONG_ARRS;
    return OK;
}

int f_read_str(FILE *f, char *str, size_t read_len)
{
    if (fgets(str, read_len, f) == NULL)
    {
        return FILE_ERR;
    }
    size_t len = strlen(str);
    if (str[len - 1] != '\n')
        return FILE_ERR;

    str[len - 1] = '\0';
    return OK;
}

int f_read_uint(FILE *f, uint32_t *num)
{
    if (fscanf(f, "%u", num) == 1)
        return OK;
    return FILE_ERR;
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

int text_to_bin(FILE *fin, FILE *fbout)
{
    struct product_t tmp;
    while (read_product_text(fin, &tmp) == OK)
        if (fwrite(&tmp, sizeof(tmp), 1, fbout) != 1)
            return FILE_ERR;
    return OK;
}

void write_struct(FILE *f, struct product_t *prod)
{
    fprintf(f, "%s\n%s\n%u\n%u\n", prod->name, prod->manufacturer, prod->price, prod->count);
}

int bin_to_text(FILE *fbin, FILE *fout)
{
    struct product_t tmp;
    while (fread(&tmp, sizeof(tmp), 1, fbin) == 1)
        write_struct(fout, &tmp);
    return OK;
}
