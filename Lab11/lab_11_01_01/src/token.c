#include <stddef.h>
#include <stdarg.h>
#include "my_string.h"
#include "hex.h"
#include "token.h"

size_t read_token(const char *str, token_num_t *token)
{
    if (my_strncmp("%llx", str, my_strlen("%llx")) == 0)
    {
        *token = LLX;
        return my_strlen("%llx");
    }
    else if (my_strncmp("%s", str, my_strlen("%s")) == 0)
    {
        *token = S;
        return my_strlen("%s");
    }
    // else if (my_strncmp("%%", str, my_strlen("%%")) == 0)
    // {
    //     *token = PERCENT;
    //     return my_strlen("%%");
    // }
    *token = UNKNOWN;
    return 0;
}

