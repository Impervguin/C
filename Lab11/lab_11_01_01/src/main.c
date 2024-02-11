#include <stdio.h>
#include "my_string.h"
#include <limits.h>

int cmp_strings(const char *s1, const char *s2, size_t size)
{
    size_t now = 0;
    for (; *s1 == *s2 && *s1 != '\0' && now < size; now++, s1++, s2++);
    return *s1 - *s2;
}

int main()
{
    // char arr[40];
    // char arr2[40];
    // int a = snprintf(arr, 40, "My favourite hex number is %llx", 100000);
    // printf("%d\n", a);
    // printf("%s\n", arr);
    // int a2 = my_snprintf(arr2, 40, "My favourite hex number is %llx", 100000);
    // printf("%d\n", a2);
    // printf("%s\n", arr2);

    #define BUF_SIZE 40
    #define IM_SIZE 40

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = "My favourite hex number is %llx";

    int my_written = my_snprintf(my_str, IM_SIZE, format_str, 100000);
    int std_written = snprintf(std_str, IM_SIZE, format_str, 100000);

    printf("%d\n", my_written);
    printf("%s\n", my_str);
    printf("%d\n", std_written);
    printf("%s\n", std_str);

    // cmp_strings(my_str, std_str, IM_SIZE);
    // return cmp_strings(my_str, std_str, IM_SIZE);
}
