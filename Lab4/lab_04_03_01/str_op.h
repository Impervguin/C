#ifndef C_LABS_STR_OP_H
#define C_LABS_STR_OP_H
#include "stddef.h"
#include "string.h"
#include "sizes.h"
#include "errors.h"
#include "stdbool.h"

/**
 * Функция, которая в каждом слове массива, оставляет только первые вхождения каждого символа
 * @param[in, out] words - Массив слов
 * @param[in] word_count - Количество слов
 * @return Код ошибки(успеха)
 */
int leave_uniq_symbs_words(char (*words)[WORD_LENGTH], size_t word_count);

/**
 * Функция, для удаления всех вхождений слова из массива слов
 * @param[in, out] words - Массив слов
 * @param[in, out] word_count - Указатель на количество слов
 * @param[in] word - Слово, которое нужно удалить
 * @return Код ошибки(успеха)
 */
int delete_words(char (*words)[WORD_LENGTH], size_t *word_count, const char *word);

/**
 * Функция, которая формирует строку из массива слов, добавляя слова в обратном порядке
 * @param[in] words - Массив слов
 * @param[in] word_count - Количество слов
 * @param[out] str - Строка, куда будут записаны слова
 * @return Код ошибки(успеха)
 */
int form_string_reverse(char (*words)[WORD_LENGTH], size_t word_count, char *str);

int create_new_words_uniq_symbs(char (*words_b)[WORD_LENGTH], size_t word_count, char (*new_words)[WORD_LENGTH], size_t *new_count);
#endif //C_LABS_STR_OP_H
