#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my_string.h"
#include "hex.h"
#include "token.h"


int my_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t now = 0;
    for (; *s1 == *s2 && *s1 != '\0' && *s2 != '\0' && now < n - 1; s1++, s2++, now++);
    return *s1 - *s2;
}

size_t my_strlen(const char *s)
{
    size_t size = 0;
    for (; *s != '\0'; s++, size++);
    return size;
}

/**
 * @brief Функция для записи строки в другой буфер с ограничением количества записываемых символов.
 * 
 * @param [in] s - Строка для записи.
 * @param [out] dst - Буфер, куда будет записываться строка.
 * @param [in] max_write - Максимальное количество символов для записи.
 * @param [out] written - Количество записанных символов, если бы в буфере точно хватало бы место.
 * @param [in] write - Флаг, если 0, то символы не будут записаны, только заполнен *written.
 * @return int - 1, если все символы записаны, 0 - если не удалось записать всю строку.
 */
int string_write(char *s, char **dst, size_t max_write, size_t *written, int write)
{
    *written = 0;
    for (; write && *written < max_write && *s != '\0'; (*dst)++, (*written)++, s++)
        **dst = *s;
    *written += my_strlen(s);
    if (*s != '\0')
        return 0;
    return 1;
}

int my_snprintf(char *s, size_t n, const char *format, ...)
{
    if (format == NULL)
        return -1;
    char *now = s;
    int now_len = 0;
    va_list args;
    const char *fnow = format;
    
    int write = 1;
    if (n == 0)
        write = 0;

    va_start(args, format);

    while (*fnow != '\0')
    {
        if (write && now_len >= n - 1)
        {
            write = 0;
        }
        if (*fnow == '%')
        {
            token_num_t token = UNKNOWN;
            size_t token_size = read_token(fnow, &token);
            if (token == UNKNOWN)
                return -1;
            else if (token == LLX)
            {
                size_t written = 0;
                long long unsigned num = va_arg(args, long long unsigned);
                char *hex_str = get_hex_str(num);
                string_write(hex_str, &now, n - now_len - 1, &written, write);
                now_len += written;
                free(hex_str);
            }
            else if (token == S)
            {
                size_t written = 0;
                char *tmp = va_arg(args, char*);
                string_write(tmp, &now, n - now_len - 1, &written, write);
                now_len += written;
            }
            fnow += token_size;
        }
        else
        {
            if (write)
            {
                *now = *fnow;
                now++;
            }
            now_len++;
            fnow++;
        }
    }
    va_end(args);
    if (now && n)
        *now = '\0';
    return now_len;
}
