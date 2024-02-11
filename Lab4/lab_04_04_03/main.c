#include "io.h"
#include "sizes.h"
#include "errors.h"
#include "str_op.h"

int main(void)
{
    char str[STRING_LENGTH];
    int rc;

    rc = string_input(str);

    if (rc == OK || rc == EMPTY_STRING_ERROR)
    {
        rc = OK;
        int res = is_number(str);
        if (res == OK)
            string_output("YES");
        else
            string_output("NO");
    }
    return rc;
}
