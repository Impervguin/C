#ifndef C_LABS_STR_OP_H
#define C_LABS_STR_OP_H

#include "stddef.h"
#include "string.h"
#include "sizes.h"
#include "errors.h"
#include "stdbool.h"

/**
 * Функция, для поиска уникальных слов в двух массивах
 * @param[in] w1 - Первый массив слов
 * @param[in] w1_count - Количество слов в первом массиве
 * @param[in] w2 - Второй массив слов
 * @param[in] w2_count - Количество слов во втором массиве
 * @param[out] w_uniq - Массив уникальных слов
 * @param[out] w_uniq_count - Указатель на количество уникальных слов
 * @return Кол ошибки(успеха)
 */
int find_uniq_words(char (*w1)[WORD_LENGTH], size_t w1_count, char (*w2)[WORD_LENGTH], size_t w2_count, char (*w_uniq)[WORD_LENGTH], size_t *w_uniq_count);

#endif //C_LABS_STR_OP_H
