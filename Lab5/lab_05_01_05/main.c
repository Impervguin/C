#include "process.h"
#include <stdio.h>

int main(void)
{
    int rc;
    size_t res;
    rc = process(stdin, &res);

    switch (rc)
    {
        case NO_DATA:
            printf("No data found.\n");
            break;
        case OK:
            printf("Result: %zu\n", res);
            break;
        default:
            printf("Unknown error.\n");
            break;
    }
    return rc;
}
