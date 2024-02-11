#include "process_bin_files.h"


int create_bfile_with_rand_nums(const char *fname, size_t count)
{
    int rc;
    FILE *bfout = NULL;
    rc = open_bin_write_file(fname, &bfout);
    if (rc == OK)
    {
        for (size_t i = 0; i < count; i++)
        {
            int r = rand();
            fwrite(&r, sizeof(int), 1, bfout);
        }
    }
    fclose(bfout);
    return OK;
}

int read_bfile_nums(const char *fname, int *arr, size_t *size)
{
    int rc;
    FILE *bfin = NULL;
    rc = open_bin_read_file(fname, &bfin);
    if (rc == OK)
    {
        size_t now = 0;
        while (fread(&(arr[now]), sizeof(int), 1, bfin) == 1 && now < MAXNUM - 1)
        {
            now++;
        }
        if (!feof(bfin))
            rc = FIO_ERROR;
        else
            *size = now;
        fclose(bfin);
    }

    return rc;
}

int get_number_by_pos(FILE *f, size_t index, int *res)
{
    if (fseek(f, index * sizeof(int), SEEK_SET))
        return FSEEK_ERROR;
    if (fread(res, sizeof(int), 1, f) != 1)
        return FIO_ERROR;
    return OK;
}

int put_number_by_pos(FILE *f, size_t index, int num)
{
    int rc = OK;
    if (fseek(f, index * sizeof(int), SEEK_SET))
        return FSEEK_ERROR;
    if (fwrite(&num, sizeof(int), 1, f) != 1)
        return FIO_ERROR;
    return rc;
}

int get_bfile_nums_count(FILE *f, size_t *count)
{
    if (fseek(f, 0, SEEK_END))
        return FSEEK_ERROR;
    long size = ftell(f);
    if (size % sizeof(int) != 0)
        return FIO_ERROR;
    *count = size / sizeof(int);
    return OK;
}

int sort_bfile_nums(const char *fname)
{
    FILE *f = NULL;
    int rc = OK;
    rc = open_bin_read_append_file(fname, &f);
    if (rc == OK)
    {
        size_t count;
        rc = get_bfile_nums_count(f, &count);
        if (rc == OK)
        {
            if (count == 0)
                rc = NO_ELEMENTS_ERROR;
            for (size_t i = 0; i < count && rc == OK; i++)
            {
                size_t best_index = i;
                int best_val;
                rc = get_number_by_pos(f, i, &best_val);
                for (size_t j = i + 1; j < count && rc == OK; j++)
                {
                    int val;
                    rc = get_number_by_pos(f, j, &val);
                    if (rc == OK && val < best_val)
                    {
                        best_val = val;
                        best_index = j;
                    }
                }
                if (rc == OK && best_index != i)
                {
                    int tmp;
                    rc = get_number_by_pos(f, i, &tmp);
                    if (rc == OK)
                        rc = put_number_by_pos(f, i, best_val);
                    if (rc == OK)
                        rc = put_number_by_pos(f, best_index, tmp);
                }
            }
        }
        fclose(f);
    }
    return rc;
}
