#include "str_op.h"

const char *shift_spaces(const char *str)
{
    const char *pa = str;
    while (strchr(SPACE_SYMBOLS, (int) *pa) != NULL && *pa != '\0')
        pa++;
    return pa;
}

bool check_next_symbols(const char **str, size_t sym_count, const char *syms, bool until_not_correct)
{
    bool found_any = false;
    for (size_t i = 0; (until_not_correct) ? true : i < sym_count; i++)
    {
        if (**str == '\0')
            return MET_END_OF_STRING;
        if (strchr(syms, (int) **str) == NULL)
        {
            if (until_not_correct)
            {
                if (found_any)
                    return OK;
                else
                    return NOT_FOUND_ANY_SYMBOLS;
            }
            return NOT_CORRECT_SYMBOLS;
        }
        found_any = true;
        (*str)++;
    }
    return OK;
}

//int is_number(const char *str)
//{
//    char *pa = shift_spaces(str);
//    if (*pa == '+')
//    {
//        pa++;
//        bool was_num = false;
//        while (is_num(*pa))
//        {
//            was_num = true;
//            pa++;
//        }
//
//        if (!was_num)
//            return NOT_CORRECT_NUMBER;
//    }
//    if (*pa != '(')
//        return NOT_CORRECT_NUMBER;
//    pa++;
//    for (size_t i = 0; i < OPERATOR_CODE_SIZE; i++)
//    {
//        if (!is_num(*pa))
//            return NOT_CORRECT_NUMBER;
//        pa++;
//    }
//
//    if (*pa != ')')
//        return NOT_CORRECT_NUMBER;
//    pa++;
//
//    if (*pa != '-')
//        return NOT_CORRECT_NUMBER;
//    pa++;
//
//    for (size_t i = 0; i < FIRST_PART_NUMBER_SIZE; i++)
//    {
//        if (!is_num(*pa))
//            return NOT_CORRECT_NUMBER;
//        pa++;
//    }
//    if (*pa != '-')
//        return NOT_CORRECT_NUMBER;
//    pa++;
//
//    for (size_t i = 0; i < SECOND_PART_NUMBER_SIZE; i++)
//    {
//        if (!is_num(*pa))
//            return NOT_CORRECT_NUMBER;
//        pa++;
//    }
//    if (*pa != '-')
//        return NOT_CORRECT_NUMBER;
//    pa++;
//
//    for (size_t i = 0; i < THIRD_PART_NUMBER_SIZE; i++)
//    {
//        if (!is_num(*pa))
//            return NOT_CORRECT_NUMBER;
//        pa++;
//    }
//
//    while (*pa != '\0')
//    {
//        if (strchr(SPACE_SYMBOLS, (int) *pa) == NULL)
//            return NOT_CORRECT_NUMBER;
//        pa++;
//    }
//    return OK;
//}

int is_number(const char *str)
{
    const char *pa = shift_spaces(str);
    if (*pa == '+')
    {
        pa++;
        if (check_next_symbols(&pa, 1, NUMBERS, true) != OK)
            return NOT_CORRECT_NUMBER;
    }
    if (check_next_symbols(&pa, 1, "(", false) != OK)
        return NOT_CORRECT_NUMBER;
    if (check_next_symbols(&pa, OPERATOR_CODE_SIZE, NUMBERS, false) != OK)
        return NOT_CORRECT_NUMBER;
    if (check_next_symbols(&pa, 1, ")", false) != OK)
        return NOT_CORRECT_NUMBER;
    if (check_next_symbols(&pa, 1, "-", false) != OK)
        return NOT_CORRECT_NUMBER;
    if (check_next_symbols(&pa, FIRST_PART_NUMBER_SIZE, NUMBERS, false) != OK)
        return NOT_CORRECT_NUMBER;
    if (check_next_symbols(&pa, 1, "-", false) != OK)
        return NOT_CORRECT_NUMBER;
    if (check_next_symbols(&pa, SECOND_PART_NUMBER_SIZE, NUMBERS, false) != OK)
        return NOT_CORRECT_NUMBER;
    if (check_next_symbols(&pa, 1, "-", false) != OK)
        return NOT_CORRECT_NUMBER;
    if (check_next_symbols(&pa, THIRD_PART_NUMBER_SIZE, NUMBERS, false) != OK)
        return NOT_CORRECT_NUMBER;
    pa = shift_spaces(pa);
    if (*pa != '\0')
        return NOT_CORRECT_NUMBER;
    return OK;
}
