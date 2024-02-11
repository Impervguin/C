#include "str_func.h"
char *sym_in_str(const char *str, const char sym)
{
    size_t i = 0;
    for (; str[i] != '\0'; i++)
    {
        if (str[i] == sym)
            return (char *) &str[i];
    }
    if (str[i] == sym)
        return (char *) &str[i];
    return NULL;
}
