#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include "hex.h"

char get_hex_symb(unsigned num)
{
    return "0123456789abcdef"[num];
}

size_t hex_size(long long unsigned num)
{
    size_t now_size = 0;
    if (num == 0)
        now_size = 1;
    for (; num != 0; num /= 16, now_size++);
    return now_size;
}

/// Длина шестнадцатиричной цифры в битах
#define HEX_CHAR_BITS 4

char *get_hex_str(long long unsigned num)
{
    size_t digit_count = hex_size(num);
    size_t now_size = 0;
    int was_not_null = 0;
    char *buf = malloc(sizeof(char) * (digit_count + 1));
    if (!buf)
        return NULL;

    /// Получаем шестнадцатиричное число начиная со старшего разряда
    while (num > 0)
    {
        /// Берем нынешнюю шестнадцатиричную цифру в старшем разряде(первые 4 бита)
        char now_hex = get_hex_symb(num >> (sizeof(num) * CHAR_BIT - HEX_CHAR_BITS));
        /// Если это цифра или не первая ненулевая, то пишем.
        if (now_hex != '0' || was_not_null)
        {
            was_not_null = 1;
            buf[now_size++] = now_hex;
        }
        /// Сдвигаем влево на шестнадцатиричную цифру, чтобы дальше получать следующую.
        num <<= HEX_CHAR_BITS;
    }

    /// Записываем оставшиеся нули(т.к. мы идем до момента пока число не станет нулем, а как-то только закончатся ненулевые цифры оно станет им.)
    while (now_size < digit_count)
    {
        buf[now_size++] = '0';
    }
    buf[now_size++] = '\0';

    return buf;
}