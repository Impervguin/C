#include "str_op.h"

/**
 * Функция, для удаления слова из массива слов
 * @param [in, out] words - Массив слов
 * @param [in, out] word_count - Количество слов в массиве
 * @param [in] index - Индекс удаляемого элемента
 * @return Код ошибки(успеха)
 */
int delete_elem(char (*words)[WORD_LENGTH], size_t *word_count, size_t index)
{
    for (size_t i = index + 1; i < *word_count; i++)
    {
        strcpy(words[i - 1], words[i]);
    }
    (*word_count)--;
    return OK;
}

int delete_words(char (*words)[WORD_LENGTH], size_t *word_count, const char *word)
{
    size_t i = *word_count - 1;
    for (; i != 0; i--)
        if (strcmp(words[i], word) == 0)
            delete_elem(words, word_count, i);
    if (strcmp(words[i], word) == 0)
        delete_elem(words, word_count, i);
    return OK;
}

/**
 * Функция, которая оставляет только первые вхождения каждого символа в слове
 * @param [in, out] word - слово
 * @return Код ошибки(успеха)
 */

int leave_uniq_symbs(char *word)
{
    char tmp[WORD_LENGTH];
    size_t tmp_ind = 1;
    tmp[0] = word[0];
    tmp[1] = '\0';
    for (char *pa = word; *pa != '\0'; pa++)
    {
        if (strchr(tmp, (int) *pa) == NULL)
        {
            tmp[tmp_ind++] = *pa;
            tmp[tmp_ind] = '\0';
        }
    }
    strcpy(word, tmp);
    return OK;
}

int leave_uniq_symbs_words(char (*words)[WORD_LENGTH], size_t word_count)
{
    for (size_t i = 0; i < word_count; i++)
        leave_uniq_symbs(words[i]);
    return OK;
}

int create_new_words_uniq_symbs(char (*words_b)[WORD_LENGTH], size_t word_count, char (*new_words)[WORD_LENGTH], size_t *new_count)
{
    char last[WORD_LENGTH];
    strcpy(last, words_b[word_count - 1]);
    *new_count = 0;
    for (size_t i = 0; i < word_count - 1; i++)
    {
        if (strcmp(words_b[i], last))
        {
            strcpy(new_words[*new_count], words_b[i]);
            leave_uniq_symbs(new_words[*new_count]);
            (*new_count)++;
        }
    }
    return OK;
}

int form_string_reverse(char (*words)[WORD_LENGTH], size_t word_count, char *str)
{
    str[0] = '\0';
    size_t i = word_count - 1;
    for (; i != 0; i--)
    {
        strcat(str, words[i]);
        strcat(str, " ");
    }
    strncat(str, words[i], WORD_LENGTH);
    return OK;
}
