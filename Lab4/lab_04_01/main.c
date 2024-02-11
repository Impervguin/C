#include <stdio.h>
#include "test.h"

int main(void)
{
    int failed_tests = 0;
    printf("%d\n", failed_tests += test_strchr());
    printf("%d\n", failed_tests += test_strcspn());
    printf("%d\n", failed_tests += test_strrchr());
    printf("%d\n", failed_tests += test_strspn());
    printf("%d\n", failed_tests += test_strpbrk());
    return failed_tests;
}
