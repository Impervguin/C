#include "strings.h"
char *my_strchr(const char *str, int sym)
{
    char *ps = sym_in_str(str, (char) sym);
//    const char *ps = str;
//    for (; *ps != '\0'; ps++)
//        if (*ps == sym)
//            return (char *) ps;
//    if (*ps == sym)
//        return (char *) ps;
    return ps;
}

size_t my_strcspn(const char *str, const char *sym)
{
    size_t i = 0;
    for (; str[i] != '\0'; i++)
        if (sym_in_str(sym, str[i]) != NULL)
            return i;
    return i;
}

char *my_strpbrk(const char *str, const char *sym)
{
    for (const char *ps = str; *ps != '\0'; ps++)
        if (sym_in_str(sym, *ps) != NULL)
            return (char *) ps;
    return NULL;
}

char *my_strrchr(const char *str, int ch)
{
    char *pa = NULL;
    char *ps = sym_in_str(str, (char) ch);
    while (ps != NULL && *ps != '\0')
    {
        pa = ps;
        ps = sym_in_str((++ps), (char) ch);
    }
    if (ps != NULL && *ps == (char) ch)
        pa = ps;

//    const char *p = NULL;
//    const char *pa = str;
//    for (; *pa != '\0'; pa++)
//    {
//        if (*pa == ch)
//            p = pa;
//    }
//    if (*pa == ch)
//        p = pa;
    return pa;
}

size_t my_strspn(const char *str, const char *sym)
{
    size_t i = 0;
    for (; str[i] != '\0'; i++)
        if (!sym_in_str(sym, str[i]))
            return i;
    return i;
}
