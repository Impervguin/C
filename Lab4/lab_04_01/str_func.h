#ifndef C_LABS_STR_FUNC_H
#define C_LABS_STR_FUNC_H
#include <stdbool.h>
#include <stddef.h>

/**
 * Функция для проверки на наличие в строке символа
 * @param[in] str Строка
 * @param[in] sym Символ
 * @return true если символ есть, иначе false
 */
char *sym_in_str(const char *str, const char sym);
#endif //C_LABS_STR_FUNC_H
