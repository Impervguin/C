#include "split.h"

int split_words(char *string, char (*words)[WORD_LENGTH], size_t *word_count)
{
    *word_count = 0;
    char *word = strtok(string, SEPARATORS);
    while (word != NULL)
    {
        if (*word_count >= MAX_WORD_COUNT)
            return TOO_MANY_WORDS_ERROR;
        if (strlen(word) >= WORD_LENGTH)
            return TOO_BIG_WORD_ERROR;
        strcpy(words[(*word_count)++], word);
        word = strtok(NULL, SEPARATORS);
    }
    return OK;
}
