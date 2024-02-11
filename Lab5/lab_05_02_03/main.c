#include <stdio.h>
#include "calculate.h"
#include "io.h"

int main(int argc, char **argv)
{
    int rc = OK, res;
    FILE *fin = NULL;
    double expected_value, deviation;
    if (argc != 2)
        rc = NOT_CORRECT_ARGS;

    if (rc == OK)
        rc = open_read_file(argv[1], &fin);

    if (rc == OK)
    {
        rc = calc_expected_value(fin, &expected_value);
        rewind(fin);
    }

    if (rc == OK)
    {
        rc = calc_standard_deviation(fin, &deviation, expected_value);
        rewind(fin);
    }

    if (rc == OK)
    {
        rc = check_three_sigma_rule(fin, &res, expected_value, deviation);
        rewind(fin);
    }

    fclose(fin);

    switch (rc)
    {
        case FILE_NOT_FOUND_ERROR:
            printf("Can't reach file.\n");
            break;
        case NOT_CORRECT_ARGS:
            printf("app.exe <file-name>\n");
            break;
        case NO_ELEMENTS_ERROR:
            printf("No numbers in file.\n");
            break;
        case FIO_ERROR:
            printf("Not correct file content.\n");
            break;
        case OK:
            printf("%d\n", res);
            break;
        default:
            printf("Unknown error.\n");
            break;
    }
    return rc;
}
