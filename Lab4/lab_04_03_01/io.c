#include "io.h"

int string_input(char *string)
{
    int rc = OK;
    printf("Enter a string: ");
    if (fgets(string, STRING_LENGTH, stdin) == NULL)
        return IO_ERROR;
    if (string[0] == '\n')
    {
        return EMPTY_STRING_ERROR;
    }
    size_t size = strlen(string);
    if (string[size - 1] != '\n')
        return TOO_BIG_STRING_ERROR;

    string[size - 1] = '\0';
    return rc;
}

void string_output(const char *str)
{
    printf("Result: %s", str);
}
