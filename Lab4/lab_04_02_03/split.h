#ifndef C_LABS_SPLIT_H
#define C_LABS_SPLIT_H

#include <stddef.h>
#include <string.h>
#include "sizes.h"
#include "errors.h"

/**
 * Функция для разделения строки на слова по разделителям SEPARATORS
 * @param[in] string - Строка
 * @param[out] words - Массив слов
 * @param[out] word_count - Указатель на количество слов
 * @return Код ошибки(успеха)
 */
int split_words(char *string, char (*words)[WORD_LENGTH], size_t *word_count);

#endif //C_LABS_SPLIT_H
