#include "io.h"
#include "split.h"
#include "sizes.h"
#include "errors.h"
#include "str_op.h"

int main(void)
{
    char str1[STRING_LENGTH], str2[STRING_LENGTH];
    char words1[MAX_WORD_COUNT][WORD_LENGTH], words2[MAX_WORD_COUNT][WORD_LENGTH], w_uniq[2 * MAX_WORD_COUNT][WORD_LENGTH];
    size_t words1_count, words2_count, w_uniq_count;
    int rc;

    rc = string_2_input(str1, str2);

    if (rc == OK)
    {
        rc = split_words(str1, words1, &words1_count);
        if (rc == OK)
            rc = split_words(str2, words2, &words2_count);
    }
    if (rc == OK)
    {
        find_uniq_words(words1, words1_count, words2, words2_count, w_uniq, &w_uniq_count);
        if (w_uniq_count == 0)
            rc = NO_RESULT;
    }
    if (rc == OK)
        words_output(w_uniq, w_uniq_count);

    switch (rc)
    {
        case IO_ERROR:
            printf("Wrong input.");
            break;
        case EMPTY_STRING_ERROR:
            printf("Empty string.");
            break;
        case TOO_BIG_STRING_ERROR:
            printf("Too big string.");
            break;
        case TOO_BIG_WORD_ERROR:
            printf("Too big word.");
            break;
        case NO_RESULT:
            printf("Empty string.");
            break;
        case TOO_MANY_WORDS_ERROR:
            printf("Too many words in string.");
            break;
        case OK:
            break;
        default:
            printf("Unknown error");
            break;
    }
    return rc;
}
