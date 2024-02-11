#include "io.h"

int string_input(char *string)
{
    int rc = OK;
    if (fgets(string, STRING_LENGTH, stdin) == NULL)
        return IO_ERROR;
    if (string[0] == '\n')
    {
        rc = EMPTY_STRING_ERROR;
    }
    size_t size = strlen(string);
    if (string[size - 1] != '\n')
        return TOO_BIG_STRING_ERROR;

    string[size - 1] = '\0';
    return rc;
}

void string_output(char *str)
{
    printf("%s", str);
}
