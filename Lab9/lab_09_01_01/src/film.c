#define _GNU_SOURCE

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "film.h"

void free_film(struct film_t *film)
{
    free(film->name);
    free(film->title);
}

/**
 * @brief Функция, которая динамически считывает строку из файла. Размер подаваемой строки
 * должен быть равен или больше max_size
 * @param [in] f - Файл
 * @param [out] string - Строка
 * @param [in] max_size - Максимальный размер строки
 * @return int Код возврата
 */
static int str_read(FILE *f, char **string)
{
    size_t bts = 0;
    char *tmp_buf = NULL;
    if (getline(&tmp_buf, &bts, f) < 0)
    {
        free(tmp_buf);
        return ERR_IO;
    }  
        
    size_t len = strlen(tmp_buf);
    if (len && tmp_buf[len - 1] == '\n')
    {
        len--;
        tmp_buf[len] = '\0';
    }

    if (!len)
    {
        free(tmp_buf);
        return ERR_RANGE;
    }

    *string = tmp_buf;
    return ERR_OK;
}

int film_read(FILE *f, struct film_t *pf, int *sr)
{
    char *title_buf = NULL;
    char *name_buf = NULL;
    int year;
    // char tmp[2];
    int rc = ERR_OK;
    *sr = 0;
    if (!(rc = str_read(f, &title_buf)))
        *sr = 1;

    if (!rc)
        rc = str_read(f, &name_buf);
    if (!rc)
        if (fscanf(f, "%d\n", &year) != 1)
            rc = ERR_IO;

    if (!rc && year < 0)
        rc = ERR_RANGE;    

    // if (fgets(tmp, 2, f) != NULL && tmp[0] != '\n')
    //     rc = ERR_IO;
    
    if (!rc)
    {
        pf->title = title_buf;
        pf->name = name_buf;
        pf->year = year;
    }
    else
    {
        if (title_buf != NULL)
            free(title_buf);
        if (name_buf != NULL)
            free(name_buf);
    }

    return rc;
}

int film_print(FILE *f, const struct film_t *pf)
{
    if (fprintf(f, "%s\n", pf->title) < 0)
        return ERR_IO;
    if (fprintf(f, "%s\n", pf->name) < 0)
        return ERR_IO;
    if (fprintf(f, "%d\n", pf->year) < 0)
        return ERR_IO;

    return ERR_OK;
}

int film_cmp_by_title(const struct film_t *pf1, const struct film_t *pf2)
{
    return strcmp(pf1->title, pf2->title);
}
    

int film_cmp_by_name(const struct film_t *pf1, const struct film_t *pf2)
{
    return strcmp(pf1->name, pf2->name);
}
    

int film_cmp_by_year(const struct film_t *pf1, const struct film_t *pf2)
{
    if ((pf1->year > pf2->year))
        return 1;
    else if (pf1->year == pf2->year)
    {
        return 0;
    }
    return -1;
}
    

// int film_cmp(const struct film_t *pf1, const struct film_t *pf2, field_t field)
// {
//     if (field == TITLE)
//         return film_cmp_by_title(pf1, pf2);
//     else if (field == NAME)
//         return film_cmp_by_name(pf1, pf2);
//     else
//         return film_cmp_by_year(pf1, pf2);
// }

// int film_cmp(const struct film_t *pf1, const struct film_t *pf2)
// {
//     if (pf2->name[0] != '\0')
//         return film_cmp_by_name(pf1, pf2);
//     if (pf2->year != 0)
//         return film_cmp_by_year(pf1, pf2);
//     else
//         return film_cmp_by_title(pf1, pf2);
// }


