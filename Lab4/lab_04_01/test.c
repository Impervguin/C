#include "test.h"



int test_strchr(void)
{
    int err_count = 0;
    size_t test_str_count = 5;
    size_t test_sym_count = 5;

    char strings[][WORD_LENGTH] = {
        "test",
        "Hello",
        "world",
        "1232s",
        ""
    };

    char syms[] = {
        'e',
        'a',
        'l',
        '3',
        '\0'
    };
    for (size_t i = 0; i < test_str_count; i++)
    {
        for (size_t j = 0; j < test_sym_count; j++)
        {
            err_count += (strchr(strings[i], syms[j]) != my_strchr(strings[i], syms[j]));
        }
    }
    return err_count;
}

int test_strcspn(void)
{
    int err_count = 0;
    size_t test_str_count = 5;
    size_t test_sym_count = 5;

    char strings[][WORD_LENGTH] = {
        "testtest",
        "Hello",
        "world",
        "1232s",
        ""
    };

    char syms[][WORD_LENGTH] = {
        "tst",
        "sad",
        "",
        "23",
        "helo"
    };
    for (size_t i = 0; i < test_str_count; i++)
    {
        for (size_t j = 0; j < test_sym_count; j++)
        {
            err_count += (strcspn(strings[i], syms[j]) != my_strcspn(strings[i], syms[j]));
        }
    }
    return err_count;
}
int test_strrchr(void)
{
    int err_count = 0;
    size_t test_str_count = 5;
    size_t test_sym_count = 5;

    char strings[][WORD_LENGTH] = {
        "test",
        "Hello",
        "world",
        "1232s",
        ""
    };

    char syms[] = {
        'e',
        'a',
        'l',
        '3',
        '\0'
    };
    for (size_t i = 0; i < test_str_count; i++)
    {
        for (size_t j = 0; j < test_sym_count; j++)
        {
            err_count += (strrchr(strings[i], syms[j]) != my_strrchr(strings[i], syms[j]));
        }
    }
    return err_count;
}
int test_strpbrk(void)
{
    int err_count = 0;
    size_t test_str_count = 5;
    size_t test_sym_count = 5;

    char strings[][WORD_LENGTH] = {
        "testtest",
        "Hello",
        "world",
        "1232s",
        ""
    };

    char syms[][WORD_LENGTH] = {
        "tst",
        "sad",
        "",
        "23",
        "helo"
    };
    for (size_t i = 0; i < test_str_count; i++)
    {
        for (size_t j = 0; j < test_sym_count; j++)
        {
            err_count += (strpbrk(strings[i], syms[j]) != my_strpbrk(strings[i], syms[j]));
        }
    }
    return err_count;
}
int test_strspn(void)
{
    int err_count = 0;
    size_t test_str_count = 5;
    size_t test_sym_count = 5;

    char strings[][WORD_LENGTH] = {
        "testtest",
        "Hello",
        "world",
        "1232s",
        ""
    };

    char syms[][WORD_LENGTH] = {
        "tst",
        "sad",
        "",
        "23",
        "helo"
    };
    for (size_t i = 0; i < test_str_count; i++)
    {
        for (size_t j = 0; j < test_sym_count; j++)
        {
            if (strspn(strings[i], syms[j]) != my_strspn(strings[i], syms[j]))
            {
                printf("%s\n", strings[i]);
                printf("%s\n", syms[j]);
                printf("%lu\n", strspn(strings[i], syms[j]));
                printf("%lu\n", my_strspn(strings[i], syms[j]));
            }
            err_count += (strspn(strings[i], syms[j]) != my_strspn(strings[i], syms[j]));
        }
    }
    return err_count;
}
