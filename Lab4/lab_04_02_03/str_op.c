#include "str_op.h"



/**
 * Функция, для проверки наличия слова в массиве слов
 * @param [in] w - Массив слов
 * @param [in] w_count - Количество слов
 * @param [in] word - слово, которое надо найти
 * @return true - Если слово есть в массиве слов, иначе false
 */
bool word_in_words(char (*w)[WORD_LENGTH], size_t w_count, const char *word)
{
    for (size_t i = 0; i < w_count; i++)
    {
        if (strcmp(w[i], word) == 0)
            return true;
    }
    return false;
}

size_t calc_word_in_words(char (*w)[WORD_LENGTH], size_t w_count, const char *word)
{
    size_t word_apppeared = 0;
    for (size_t i = 0; i < w_count; i++)
    {
        if (strcmp(w[i], word) == 0)
            word_apppeared++;
    }
    return word_apppeared;
}
int find_uniq_words(char (*w1)[WORD_LENGTH], size_t w1_count, char (*w2)[WORD_LENGTH], size_t w2_count, char (*w_uniq)[WORD_LENGTH], size_t *w_uniq_count)
{
    size_t uniq_ind = 0; /// Указатель, куда помещать следующее уникальное слово
    /// Проверяем все слова на уникальность в 1-ом массиве
    for (size_t i = 0; i < w1_count; i++)
    {
//        if (!word_in_words(w1, i, w1[i])
//            && !word_in_words((w1 + i + 1), w1_count - i - 1, w1[i])
//            && !word_in_words(w2, w2_count, w1[i]))
//            strcpy(w_uniq[uniq_ind++], w1[i]);
        if (calc_word_in_words(w1, w1_count, w1[i]) == 1 && calc_word_in_words(w2, w2_count, w1[i]) == 0)
            strcpy(w_uniq[uniq_ind++], w1[i]);
    }
    /// Проверяем все слова на уникальность во 2-ом массиве
    for (size_t i = 0; i < w2_count; i++)
    {
//        if (!word_in_words(w2, i, w2[i])
//            && !word_in_words((w2 + i + 1), w2_count - i - 1, w2[i])
//            && !word_in_words(w1, w1_count, w2[i]))
//            strcpy(w_uniq[uniq_ind++], w2[i]);
        if (calc_word_in_words(w1, w1_count, w2[i]) == 0 && calc_word_in_words(w2, w2_count, w2[i]) == 1)
            strcpy(w_uniq[uniq_ind++], w2[i]);
    }
    *w_uniq_count = uniq_ind;
    return OK;
}
