#include "film.h"
#include "film_arr.h"
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    struct film_t *farr = NULL;
    size_t asize = 0;
    field_t ft;
    FILE *f = NULL;
    int (*cmp)(const struct film_t *, const struct film_t *) = NULL;
    int rc = ERR_OK;
    if (argc < 3)
        rc = ERR_ARGS;
    
    if (!rc)
    {
        f = fopen(argv[1], "r");
        if (f == NULL)
            rc = ERR_IO;
        if (!rc)
        {
            rc = gen_field_t(argv[2], &ft);
        }
    }

    if (!rc)
    {
        if (ft == TITLE)
            cmp = film_cmp_by_title;
        else if (ft == NAME)
            cmp = film_cmp_by_name;
        else 
            cmp = film_cmp_by_year;
    } 
    
    if (!rc)
    {
        rc = film_arr_read(f, &farr, &asize, cmp);
        if (!rc && asize == 0)
            rc = ERR_EMPTY;
    }

    if (!rc)
    {
        if (argc == 4)
        {
            struct film_t tmp;
            if (ft == TITLE)
                tmp.title = argv[3];
            else if (ft == NAME)
                tmp.name = argv[3];
            else 
            {
                if (strspn(argv[3], "0123456789") != strlen(argv[3]))
                    rc = ERR_ARGS;
                if (!rc)
                    tmp.year = atoi(argv[3]); 
            }
            if (!rc)
                rc = film_arr_find_by_field_print(stdout, farr, asize, &tmp, cmp);
        } 
        else
            rc = film_arr_print(stdout, farr, asize);
    }
    if (f != NULL)
        fclose(f);
    if (farr != NULL)
        free_film_arr(farr, asize);
    return rc;
}
