#include <stdio.h>
#include "errors.h"
#include "io.h"
#include "product.h"

int main(int argc, char **argv)
{
    int rc = OK;
    if (argc != 4)
        rc = NOT_CORRECT_ARGS;
    if (rc == OK)
    {
        if (strcmp(argv[1], "ft") == 0)
        {
            FILE *f = fopen(argv[2], "r");
            if (f == NULL)
                rc = FILE_NOT_FOUND_ERROR;
            if (rc == OK)
            {
                struct product_t products[MAXNUM];
                struct product_t new_products[MAXNUM];
                size_t n_prods, new_n_prods;
                if (strlen(argv[3]) == 0)
                    rc = NOT_CORRECT_ARGS;
                if (rc == OK)
                    rc = read_products_text(f, products, &n_prods);
                if (rc == OK)
                    rc = find_end_substr_product(argv[3], products, n_prods, new_products, &new_n_prods);
                if (rc == OK)
                {
                    if (new_n_prods == 0)
                        rc = NO_ELEMENTS_ERROR;
                    for (size_t i = 0; i < new_n_prods && rc == OK; i++)
                        print_product(&new_products[i]);
                }
            }
        }
        else if (strcmp(argv[1], "sb") == 0)
        {
            FILE *fin = fopen(argv[2], "rb");
            FILE *fout = fopen(argv[3], "wb");
            if (fin == NULL || fout == NULL)
                rc = FILE_NOT_FOUND_ERROR;

            if (rc == OK)
            {
                rc = fb_sort_product(fin, fout);
            }
        }
        else
            rc = NOT_CORRECT_ARGS;
    }
//    switch (rc)
//    {
//        case FILE_NOT_FOUND_ERROR:
//            printf("Can't reach file.\n");
//            break;
//        case NOT_CORRECT_ARGS:
//            printf("app.exe <ft file_name substr | sb src_file dst_file>\n");
//            break;
//        case NO_ELEMENTS_ERROR:
//            printf("No products in file.\n");
//            break;
//        case FIO_ERROR:
//            printf("Not correct file content.\n");
//            break;
//        case STRING_SIZE_ERROR:
//            printf("Not correct name size\n");
//            break;
//        case FILE_SIZE_ERROR:
//            printf("Not correct file error.");
//            break;
//        case OK:
//            break;
//        default:
//            printf("Unknown error.\n");
//            break;
//    }
    return rc;
}
