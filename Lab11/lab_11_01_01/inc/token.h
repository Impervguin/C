#ifndef TOKEN_H__
#define TOKEN_H__

#include <stddef.h>

typedef enum 
{
    LLX = 1,
    S,
    PERCENT,
    UNKNOWN = 0
} token_num_t;

/**
 * @brief Функция для чтения токена в строке.
 * 
 * @param [in] str - Указатель на начало токена, то есть на %
 * @param [out] token - Указатель на прочитанный токен.
 * @return size_t - Размер прочитанного токена в символах.
 */
size_t read_token(const char *str, token_num_t *token);

#endif // TOKEN_H__
