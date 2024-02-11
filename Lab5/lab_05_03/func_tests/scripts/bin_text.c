#include <stdio.h>
#include <string.h>

#define OK 0
#define WRONG_ARRS 1
#define FILE_ERR 2

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

int text_to_bin(FILE *fin, FILE *fbout)
{
    int tmp, rc = OK;
    while (fscanf(fin, "%d", &tmp) == 1 && rc == OK)
        if (! (fwrite(&tmp, sizeof(tmp), 1, fbout) == 1))
            rc = FILE_ERR;
    return rc;
}

int bin_to_text(FILE *fbin, FILE *fout)
{
    int tmp;
    while (fread(&tmp, sizeof(tmp), 1, fbin) == 1)
        fprintf(fout, "%d\n", tmp);
    return OK;
}
