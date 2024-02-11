#ifndef HEX_H__
#define HEX_H__

#include <stddef.h>
/**
 * @brief Функция создает строку числа в шестнадцатиричном виде.
 * Строка выделяется динамически.
 * @param [in] num - Число.
 * @return char* - Полученная строка.
 */
char *get_hex_str(long long unsigned num);

/**
 * @brief Функция возвращает шестандцатиричный символ числа
 * 
 * @param [in] num - Число.
 * @return char - Если число >16 - \0, Иначе шестандцатиричный символ числа.
 */
char get_hex_symb(unsigned num);

/**
 * @brief Функция возвращает длину числа в шестнадцатиричном виде.
 * 
 * @param [in] num - Число
 * @return size_t - Длина числа в шестнадцатиричном виде.
 */
size_t hex_size(long long unsigned num);

#endif // HEX_H__
