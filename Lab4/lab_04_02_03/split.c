#include "split.h"

int split_words(char *string, char (*words)[WORD_LENGTH], size_t *word_count)
{
    *word_count = 0;
    char now_word[WORD_LENGTH];
    size_t char_index = 0;
    for (char *pa = string; *pa != '\0'; pa++)
    {
        char *found = strchr(SEPARATORS, *pa);
        if (found == NULL)
        {
            if (char_index >= WORD_LENGTH)
                return TOO_BIG_WORD_ERROR;
            now_word[char_index++] = *pa;
        }
        else if (char_index != 0)
        {
            if (*word_count >= MAX_WORD_COUNT)
                return TOO_MANY_WORDS_ERROR;
            now_word[char_index] = '\0';
            strcpy(words[*word_count], now_word);
            char_index = 0;
            (*word_count)++;
        }
    }
    if (char_index != 0)
    {
        if (*word_count >= MAX_WORD_COUNT)
            return TOO_MANY_WORDS_ERROR;
        now_word[char_index] = '\0';
        strcpy(words[*word_count], now_word);
        (*word_count)++;
    }
    return OK;
}
