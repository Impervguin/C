#include <stdio.h>
#include <string.h>
#include "process_bin_files.h"
#include "consts.h"
#include "errors.h"
#include "io.h"

int main(int argc, char **argv)
{
    int rc = OK;
    if (argc < 3)
        rc = NOT_CORRECT_ARGS;

    if (rc == OK)
    {
        char *op = argv[1];
        if (strcmp(op, "c") == 0)
        {
            if (argc != 4)
                rc = NOT_CORRECT_ARGS;
            if (rc == OK)
            {
                rc = create_bfile_with_rand_nums(argv[2], atoi(argv[3]));
            }
        }
        else if (strcmp(op, "p") == 0)
        {
            int arr[MAXNUM];
            size_t arr_size;
            rc = read_bfile_nums(argv[2], arr, &arr_size);
            if (rc == OK)
            {
                if (arr_size != 0)
                    output_array(arr, arr_size);
                else
                    rc = NO_ELEMENTS_ERROR;
            }
        }
        else if (strcmp(op, "s") == 0)
        {
            rc = sort_bfile_nums(argv[2]);
        }
        else
            rc = NOT_CORRECT_ARGS;
    }

//    switch (rc) {
//        case FILE_NOT_FOUND_ERROR:
//            printf("Can't reach file.\n");
//            break;
//        case NOT_CORRECT_ARGS:
//            printf("app.exe <s file_name | p file_name | c file_name number>\n");
//            break;
//        case NO_ELEMENTS_ERROR:
//            printf("No numbers in file.\n");
//            break;
//        case FIO_ERROR:
//            printf("Not correct file content.\n");
//            break;
//        case OK:
//            break;
//        default:
//            printf("Unknown error.");
//            break;
//    }
    return rc;
}
