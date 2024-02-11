#include "film.h"
#include <string.h>

/**
 * @brief Функция, которая считывает строку длиной max_size из файла. Размер подаваемой строки
 * должен быть равен или больше max_size
 * @param [in] f - Файл
 * @param [out] string - Строка
 * @param [in] max_size - Максимальный размер строки
 * @return int Код возврата
 */
static int str_read(FILE *f, char *string, size_t max_size)
{
    size_t len;

    if (fgets(string, max_size, f) == NULL)
        return ERR_IO;
    
    len = strlen(string);
    if (len && string[len - 1] == '\n')
    {
        len--;
        string[len] = '\0';
    }

    if (!len || len > max_size)
        return ERR_RANGE;
    
    return ERR_OK;
}

int film_read(FILE *f, struct film_t *pf, int *sr)
{
    char title_buf[TITLE_SIZE + 2];
    char name_buf[DIRNAME_SIZE + 2];
    int year;
    char tmp[2];
    int rc = ERR_OK;
    *sr = 0;
    if ((rc = str_read(f, title_buf, TITLE_SIZE + 2)))
        return rc;
    else 
        *sr = 1;
    
    if ((rc = str_read(f, name_buf, DIRNAME_SIZE + 2)))
        return rc;
    
    if (fscanf(f, "%d", &year) != 1)
        return ERR_IO;

    if (year < 0)
        return ERR_RANGE;    

    if (fgets(tmp, 2, f) != NULL && tmp[0] != '\n')
        return ERR_IO;
    
    strcpy(pf->title, title_buf);
    strcpy(pf->name, name_buf);
    pf->year = year;

    return ERR_OK;
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

void film_cpy(struct film_t *pf_dest, const struct film_t *pf_src)
{
    strcpy(pf_dest->title, pf_src->title);
    strcpy(pf_dest->name, pf_src->name);
    pf_dest->year = pf_src->year;
}
