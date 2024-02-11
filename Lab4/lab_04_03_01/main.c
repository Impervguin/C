#include "io.h"
#include "split.h"
#include "sizes.h"
#include "errors.h"
#include "str_op.h"

int main(void)
{
    char str[STRING_LENGTH];
    char words[MAX_WORD_COUNT][WORD_LENGTH], new_words[MAX_WORD_COUNT][WORD_LENGTH];
    size_t words_count, new_count;

    int rc;

    rc = string_input(str);

    if (rc == OK)
        rc = split_words(str, words, &words_count);

    if (rc == OK)
    {
//        delete_words(words, &words_count, words[words_count - 1]);
//        if (words_count == 0)
//            rc = NO_RESULT;
//        if (rc == OK)
//            leave_uniq_symbs_words(words, words_count);
        create_new_words_uniq_symbs(words, words_count, new_words, &new_count);
        if (new_count == 0)
            rc = NO_RESULT;
    }

    if (rc == OK)
    {
        form_string_reverse(new_words, new_count, str);
        string_output(str);
    }

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
