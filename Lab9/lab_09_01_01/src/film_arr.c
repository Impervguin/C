#include "film_arr.h"
#include <string.h>
#include <stdlib.h>

struct film_t *create_film_arr(size_t asize)
{
    struct film_t *arr = malloc(sizeof(struct film_t) * asize);
    return arr;
}

void free_film_arr(struct film_t *arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
        free_film(arr + i);
    free(arr);
}

int gen_field_t(const char *field_str, field_t *ft)
{
    if (strcmp(field_str, "title") == 0)
        *ft = TITLE;
    else if (strcmp(field_str, "name") == 0)
        *ft = NAME;
    else if (strcmp(field_str, "year") == 0)
        *ft = YEAR;
    else
        return ERR_NOT_FOUND;
    return ERR_OK;
}

void film_insert(struct film_t *farr, size_t *asize, const struct film_t *film, size_t ind)
{
    for (size_t i = *asize; i > ind; i--)
        *(farr + i) = *(farr + i - 1);
    *(farr + ind) = *(film);
    (*asize)++;
}

int film_find_place_by_field(const struct film_t *farr, size_t asize, const struct film_t *film, size_t *ind, int (*cmp)(const struct film_t *, const struct film_t *))
{
    *ind = 0;
    while (*ind < asize && cmp(farr + *ind, film) <= 0)
        (*ind)++;
    return ERR_OK; 
}

int film_arr_print(FILE *f, const struct film_t *farr, size_t asize)
{
    int rc;
    for (size_t i = 0; i < asize; i++)
    {
        if ((rc = film_print(f, farr + i)))
            return rc;   
    }
    return ERR_OK;  
}

int count_films_file(FILE *f, size_t *count)
{
    int rc = ERR_OK;
    struct film_t tmp = {
        0, 
        0, 
        0
    };
    size_t cnt = 0;
    int sr;
    while (!(rc = film_read(f, &tmp, &sr)))
    {   
        cnt++;
        free_film(&tmp);
        tmp.name = NULL, tmp.title = NULL;
    }
        
    
    if (feof(f) && !sr)
        rc = ERR_OK;
    else if (!feof(f) && !sr)
    {
        char tmp[2];
        while (fgets(tmp, 2, f) != NULL && tmp[0] == '\n');
        if (feof(f))
            rc = ERR_OK;
    }
    if (!rc)
        *count = cnt;
    return rc;
}

int film_arr_read(FILE *f, struct film_t **farr, size_t *asize, int (*cmp)(const struct film_t *, const struct film_t *))
{
    int rc;
    struct film_t *tmp_arr = NULL;
    struct film_t tmp;
    size_t cnt = 0;
    int sr;
    rc = count_films_file(f, &cnt);
    if (!rc)
    {
        rewind(f);
        if (cnt > 0)
        {
            tmp_arr = create_film_arr(cnt);
            if (tmp_arr == NULL)
                rc = ERR_MEMORY;
        }
        else
            tmp_arr = NULL;
    }

    for (size_t i = 0; !rc && i < cnt; i++)
    {  
        rc = film_read(f, &tmp, &sr);
        if (!rc)
        {
            size_t ind, now_size = i;
            film_find_place_by_field(tmp_arr, now_size, &tmp, &ind, cmp);
            film_insert(tmp_arr, &now_size, &tmp, ind);
        }
    }
    
    if (rc && tmp_arr != NULL)
        free_film_arr(tmp_arr, cnt);
    if (!rc)
    {
        *farr = tmp_arr;
        *asize = cnt;
    }
        
    return rc;    
}

// /**
//  * @brief Фунция для поиска фильма в массиве по названию
//  * 
//  * @param farr - Массив фильмов
//  * @param asize - Размер массива
//  * @param key - Название
//  * @return int - Если найден - индекс фильма, иначе -1
//  */
// static int film_arr_find_by_title(const struct film_t *farr, size_t asize, const char *key)
// {
//     int ind = -1;
//     size_t start = 0, end = asize;
//     while (start < end - 1)
//     {
//         size_t now = (start + end) / 2;
//         int res = strcmp(key, farr[now].title);
//         if (res >= 0)
//             start = now;
//         else
//             end = now;  
//     }
//     if (strcmp(farr[start].title, key) == 0)
//         ind = start;
//     return ind;
// }

// /**
//  * @brief Фунция для поиска фильма в массиве по имени режиссера
//  * 
//  * @param [in] farr - Массив фильмов
//  * @param[in] asize - Размер массива
//  * @param [in] key - Имя режиссера
//  * @return int - Если найден - индекс фильма, иначе -1
//  */
// static int film_arr_find_by_name(const struct film_t *farr, size_t asize, const char *key)
// {
//     int ind = -1;
//     size_t start = 0, end = asize;
//     while (start < end - 1)
//     {
//         size_t now = (start + end) / 2;
//         int res = strcmp(key, farr[now].name);
//         if (res >= 0)
//             start = now;
//         else
//             end = now;  
//     }
//     if (strcmp(farr[start].name, key) == 0)
//         ind = start;
//     return ind;
// }

// /**
//  * @brief Фунция для поиска фильма в массиве по году издания
//  * 
//  * @param [in] farr - Массив фильмов
//  * @param[in] asize - Размер массива
//  * @param [in] key - Год издания
//  * @return int - Если найден - индекс фильма, иначе -1
//  */
// static int film_arr_find_by_year(const struct film_t *farr, size_t asize, int key)
// {
//     int ind = -1;
//     size_t start = 0, end = asize;
//     while (start < end - 1)
//     {
//         size_t now = (start + end) / 2;
//         if (farr[now].year <= key)
//             start = now;
//         else
//             end = now;  
//     }
//     if (farr[start].year == key)
//         ind = start;
//     return ind;
// }


// int film_arr_find_by_field_print(FILE *f, const struct film_t *farr, size_t asize, field_t ft, const char *key)
// {
//     int ind;
//     if (ft == TITLE)
//         ind = film_arr_find_by_title(farr, asize, key);
//     else if (ft == NAME)
//         ind = film_arr_find_by_name(farr, asize, key);
//     else
//     {
//         if (strspn(key, "0123456789") != strlen(key))
//             return ERR_ARGS;
//         int year = atoi(key);
//         ind = film_arr_find_by_year(farr, asize, year);
//     }
//     if (ind == -1)
//     {
//         fprintf(f, "%s\n", "Not found");
//         return ERR_OK;
//     } 
//     else
//         return film_print(f, (farr + ind));
// }

int film_arr_find_by_field_print(FILE *f, const struct film_t *farr, size_t asize, const struct film_t *film, int (*cmp)(const struct film_t *, const struct film_t *))
{
    int ind = -1;
    size_t start = 0, end = asize;
    while (start < end - 1)
    {
        size_t now = (start + end) / 2;
        int res = cmp(film, &farr[now]);
        if (res >= 0)
            start = now;
        else
            end = now;  
    }
    if (cmp(&farr[start], film) == 0)
        ind = start;
    if (ind == -1)
    {
        fprintf(f, "%s\n", "Not found");
        return ERR_OK;
    } 
    else
        return film_print(f, (farr + ind));
}
