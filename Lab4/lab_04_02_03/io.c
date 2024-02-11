#include "io.h"

int string_input(char *string)
{
    int rc = OK;
    printf("Enter a string: ");
    if (fgets(string, STRING_LENGTH, stdin) == NULL)
        return IO_ERROR;
    if (string[0] == '\n')
    {
        string[0] = '\0';
        return EMPTY_STRING_ERROR;
    }
    size_t size = strlen(string);
    if (string[size - 1] != '\n')
        return TOO_BIG_STRING_ERROR;

    string[size - 1] = '\0';
    return rc;
}
int string_2_input(char *string1, char *string2)
{
    int rc1, rc2;
    rc1 = string_input(string1);
    if (rc1 == EMPTY_STRING_ERROR || rc1 == OK)
    {
        rc2 = string_input(string2);
        if (rc2 == OK)
            return rc2;
        else if (rc1 == OK && rc2 == EMPTY_STRING_ERROR)
            return OK;
        else
            return rc2;
    }
    else
        return rc1;
}


void words_output(char (*w)[WORD_LENGTH], size_t w_count)
{
    printf("Result:");
    for (size_t i = 0; i < w_count; i++)
    {
        printf(" %s", w[i]);
    }
}
