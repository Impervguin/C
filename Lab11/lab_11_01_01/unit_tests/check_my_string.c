#include <check.h>
#include <stdio.h>
#include <limits.h>
#include "my_string.h"


/// @brief Тест на my_snprintf с форматированной строкой без спецификаторов.
START_TEST(test_snprintf_nospec)
{
    #define BUF_SIZE 40
    #define IM_SIZE 40

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];
    // memset(my_str, '\0', 40);
    // memset(std_str, '\0', 40);

    char *format_str = "Who let the dogs out!";

    int my_written = my_snprintf(my_str, IM_SIZE, format_str);
    int std_written = snprintf(std_str, IM_SIZE, format_str);
    
    ck_assert_int_eq(my_written, std_written);
    ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/// @brief Тест на my_snprintf с форматированной строкой "%llx".
START_TEST(test_snprintf_llx)
{
    #define BUF_SIZE 40
    #define IM_SIZE 40

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = "%llx";

    int my_written = my_snprintf(my_str, IM_SIZE, format_str, 52342);
    int std_written = snprintf(std_str, IM_SIZE, format_str, 52342);

    ck_assert_int_eq(my_written, std_written);
    ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/// @brief Тест на my_snprintf с форматированной строкой "%s".
START_TEST(test_snprintf_s)
{
    #define BUF_SIZE 40
    #define IM_SIZE 40

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = "%s";

    int my_written = my_snprintf(my_str, IM_SIZE, format_str, "love of my life");
    int std_written = snprintf(std_str, IM_SIZE, format_str, "love of my life");

    ck_assert_int_eq(my_written, std_written);
    ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/// @brief Тест на my_snprintf с форматированной строкой состоящей только из %llx.
START_TEST(test_snprintf_only_llx)
{
    #define BUF_SIZE 40
    #define IM_SIZE 40

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = "%llx%llx%llx%llx%llx";

    int my_written = my_snprintf(my_str, IM_SIZE, format_str, 34879, 241515, 213123, 564325, 241452);
    int std_written = snprintf(std_str, IM_SIZE, format_str, 34879, 241515, 213123, 564325, 241452);

    ck_assert_int_eq(my_written, std_written);
    ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/// @brief Тест на my_snprintf с форматированной строкой с %llx в начале строки.
START_TEST(test_snprintf_llx_start)
{
    #define BUF_SIZE 40
    #define IM_SIZE 40

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = "%llx - is my favourite hex number";

    int my_written = my_snprintf(my_str, IM_SIZE, format_str, 34879);
    int std_written = snprintf(std_str, IM_SIZE, format_str, 34879);

    ck_assert_int_eq(my_written, std_written);
    ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/// @brief Тест на my_snprintf с форматированной строкой с %llx в середине строки.
START_TEST(test_snprintf_llx_middle)
{
    #define BUF_SIZE 40
    #define IM_SIZE 40

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = "Hex number - %llx - is my favourite";

    int my_written = my_snprintf(my_str, IM_SIZE, format_str, 23142);
    int std_written = snprintf(std_str, IM_SIZE, format_str, 23142);

    ck_assert_int_eq(my_written, std_written);
    ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/// @brief Тест на my_snprintf с форматированной строкой с %llx в конце строки.
START_TEST(test_snprintf_llx_end)
{
    #define BUF_SIZE 40
    #define IM_SIZE 40

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = "My favourite hex number is %llx";

    int my_written = my_snprintf(my_str, IM_SIZE, format_str, 100000);
    int std_written = snprintf(std_str, IM_SIZE, format_str, 100000);

    ck_assert_int_eq(my_written, std_written);
    ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/// @brief Тест на my_snprintf с форматированной строкой состоящей только из %s.
START_TEST(test_snprintf_only_s)
{
    #define BUF_SIZE 40
    #define IM_SIZE 40

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = "%s%s%s%s%s";

    int my_written = my_snprintf(my_str, IM_SIZE, format_str, "Cool", "nice", "super", "mega", "ultra");
    int std_written = snprintf(std_str, IM_SIZE, format_str, "Cool", "nice", "super", "mega", "ultra");

    ck_assert_int_eq(my_written, std_written);
    ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/// @brief Тест на my_snprintf с форматированной строкой с %s в начале строки.
START_TEST(test_snprintf_s_start)
{
    #define BUF_SIZE 40
    #define IM_SIZE 40

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = "%s - is my favourite string";

    int my_written = my_snprintf(my_str, IM_SIZE, format_str, "Cool nice");
    int std_written = snprintf(std_str, IM_SIZE, format_str, "Cool nice");

    ck_assert_int_eq(my_written, std_written);
    ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/// @brief Тест на my_snprintf с форматированной строкой с %s в середине строки.
START_TEST(test_snprintf_s_middle)
{
    #define BUF_SIZE 40
    #define IM_SIZE 40

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = "String - %s - is my favourite";

    int my_written = my_snprintf(my_str, IM_SIZE, format_str, "nice Cool");
    int std_written = snprintf(std_str, IM_SIZE, format_str, "nice Cool");

    ck_assert_int_eq(my_written, std_written);
    ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/// @brief Тест на my_snprintf с форматированной строкой с %s в конце строки.
START_TEST(test_snprintf_s_end)
{
    #define BUF_SIZE 40
    #define IM_SIZE 40

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = "My favourite string is %s";

    int my_written = my_snprintf(my_str, IM_SIZE, format_str, "Duduckgo");
    int std_written = snprintf(std_str, IM_SIZE, format_str, "Duduckgo");

    ck_assert_int_eq(my_written, std_written);
    ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/// @brief Тест на my_snprintf с форматированной строкой с %-ом в конце.
START_TEST(test_snprintf_proc_end)
{
    #define BUF_SIZE 40
    #define IM_SIZE 40

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = "Your mark - 100%";

    int my_written = my_snprintf(my_str, IM_SIZE, format_str);
    int std_written = snprintf(std_str, IM_SIZE, format_str);

    ck_assert_int_eq(my_written, std_written);
    // ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

// Удалил тест, так как в версии snprintf моего компилятора % не вызывает ошибку, а в системе вроде ошибка вызываться должна.
// START_TEST(test_snprintf_proc_middle)
// {
//     #define BUF_SIZE 40
//     #define IM_SIZE 40

//     char my_str[BUF_SIZE];
//     char std_str[BUF_SIZE];

//     char *format_str = "Yooooou % Maan";

//     int my_written = my_snprintf(my_str, IM_SIZE, format_str);
//     int std_written = snprintf(std_str, IM_SIZE, format_str);

//     ck_assert_int_eq(my_written, std_written);
//     ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

//     #undef BUF_SIZE
//     #undef IM_SIZE
// } END_TEST

// Удалил тест, так как в версии snprintf моего компилятора % не вызывает ошибку, а в системе вроде ошибка вызываться должна.
// START_TEST(test_snprintf_proc_spec_symb)
// {
//     #define BUF_SIZE 40
//     #define IM_SIZE 40

//     char my_str[BUF_SIZE];
//     char std_str[BUF_SIZE];

//     char *format_str = "Yooooou %\n Maan";

//     int my_written = my_snprintf(my_str, IM_SIZE, format_str);
//     int std_written = snprintf(std_str, IM_SIZE, format_str);

//     ck_assert_int_eq(my_written, std_written);
//     ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

//     #undef BUF_SIZE
//     #undef IM_SIZE
// } END_TEST

// Удалил тест, так как в версии snprintf моего компилятора % не вызывает ошибку, а в системе вроде ошибка вызываться должна.
// START_TEST(test_snprintf_unknown_spec)
// {
//     #define BUF_SIZE 40
//     #define IM_SIZE 40

//     char my_str[BUF_SIZE];
//     char std_str[BUF_SIZE];

//     char *format_str = "Super %w %r dawwsaaa";

//     int my_written = my_snprintf(my_str, IM_SIZE, format_str);
//     int std_written = snprintf(std_str, IM_SIZE, format_str);

//     ck_assert_int_eq(my_written, std_written);
//     ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

//     #undef BUF_SIZE
//     #undef IM_SIZE
// } END_TEST

/// @brief Тест на my_snprintf с форматированной строкой %llx и %s.
START_TEST(test_snprintf_combination)
{
    #define BUF_SIZE 100
    #define IM_SIZE 100

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = "Hi %s. You are my %llx%s. so you better hurry to become my %llx%s.";

    int my_written = my_snprintf(my_str, IM_SIZE, format_str, "Mark", 3, "friend", 2, "friend");
    int std_written = snprintf(std_str, IM_SIZE, format_str, "Mark", 3, "friend", 2, "friend");

    ck_assert_int_eq(my_written, std_written);
    ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/// @brief Тест на my_snprintf с пустой форматированной строкой.
START_TEST(test_snprintf_empty)
{
    #define BUF_SIZE 40
    #define IM_SIZE 40

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = "";

    int my_written = my_snprintf(my_str, IM_SIZE, format_str);
    int std_written = snprintf(std_str, IM_SIZE, format_str);

    ck_assert_int_eq(my_written, std_written);
    ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/// @brief Тест на my_snprintf с форматированной строкой равной NULL.
START_TEST(test_snprintf_format_null)
{
    #define BUF_SIZE 40
    #define IM_SIZE 40

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = NULL;

    int my_written = my_snprintf(my_str, IM_SIZE, format_str);
    int std_written = snprintf(std_str, IM_SIZE, format_str);

    ck_assert_int_eq(my_written, std_written);
    // ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/// @brief Тест на my_snprintf с буфером NULL и размером NULL(Проверка на возврат ожидаемой длины).
START_TEST(test_snprintf_str_null_count_null)
{
    #define BUF_SIZE 40
    #define IM_SIZE 40

    char *my_str = NULL;
    char *std_str = NULL;

    char *format_str = "awdadf %s %s";

    int my_written = my_snprintf(my_str, 0, format_str, "ASA", "SAS");
    int std_written = snprintf(std_str, 0, format_str, "ASA", "SAS");

    ck_assert_int_eq(my_written, std_written);
    // ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/// @brief Тест на my_snprintf с размером NULL(Проверка на возврат ожидаемой длины).
START_TEST(test_snprintf_count_null)
{
    #define BUF_SIZE 40
    #define IM_SIZE 40

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = "Supet %llx%s, %s, %llx";

    int my_written = my_snprintf(my_str, 0, format_str, 2314124, "21", "WOw", 0);
    int std_written = snprintf(std_str, 0, format_str, 2314124, "21", "WOw", 0);

    ck_assert_int_eq(my_written, std_written);
    // ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/// @brief Тест на my_snprintf с размером меньшем длины форматрованной строки.
START_TEST(test_snprintf_low_count)
{
    #define BUF_SIZE 40
    #define IM_SIZE 15

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = "SUPER DUPER ULTRA MEGA COMBO!!!!";

    int my_written = my_snprintf(my_str, IM_SIZE, format_str);
    int std_written = snprintf(std_str, IM_SIZE, format_str);

    ck_assert_int_eq(my_written, std_written);
    ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/// @brief Тест на my_snprintf с llx на границе конца буфера.
START_TEST(test_snprintf_llx_border)
{
    #define BUF_SIZE 40
    #define IM_SIZE 15

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = "datad data %llx";

    int my_written = my_snprintf(my_str, IM_SIZE, format_str, 1025);
    int std_written = snprintf(std_str, IM_SIZE, format_str, 1025);

    ck_assert_int_eq(my_written, std_written);
    ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/// @brief Тест на my_snprintf с llx на границе конца буфера c обрезаеним числа(не хватает размер буфера). 
START_TEST(test_snprintf_llx_cut)
{
    #define BUF_SIZE 40
    #define IM_SIZE 15

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = "datad datad %llx";

    int my_written = my_snprintf(my_str, IM_SIZE, format_str, 1025);
    int std_written = snprintf(std_str, IM_SIZE, format_str, 1025);

    ck_assert_int_eq(my_written, std_written);
    ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/// @brief Тест на my_snprintf с s на границе конца буфера.
START_TEST(test_snprintf_s_border)
{
    #define BUF_SIZE 40
    #define IM_SIZE 17

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = "I love my %s";

    int my_written = my_snprintf(my_str, IM_SIZE, format_str, "mother");
    int std_written = snprintf(std_str, IM_SIZE, format_str, "mother");

    ck_assert_int_eq(my_written, std_written);
    ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/// @brief Тест на my_snprintf с s на границе конца буфера c обрезаеним числа(не хватает размер буфера).
START_TEST(test_snprintf_s_cut)
{
    #define BUF_SIZE 40
    #define IM_SIZE 18

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = "I very love my %s";

    int my_written = my_snprintf(my_str, IM_SIZE, format_str, "mother");
    int std_written = snprintf(std_str, IM_SIZE, format_str, "mother");

    ck_assert_int_eq(my_written, std_written);
    ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/// @brief Тест на my_snprintf с максимальным значением llu.
START_TEST(test_snprintf_llx_max)
{
    #define BUF_SIZE 40
    #define IM_SIZE 40

    char my_str[BUF_SIZE];
    char std_str[BUF_SIZE];

    char *format_str = "Biggest: %llx";

    int my_written = my_snprintf(my_str, IM_SIZE, format_str, ULLONG_MAX);
    int std_written = snprintf(std_str, IM_SIZE, format_str, ULLONG_MAX);

    ck_assert_int_eq(my_written, std_written);
    ck_assert_int_eq(my_strncmp(my_str, std_str, IM_SIZE), 0);

    #undef BUF_SIZE
    #undef IM_SIZE
} END_TEST

/**
 * @brief Создает suite для тестирования my_snprintf.
 * 
 * @return Suite* 
 */
Suite *snprintf_suite(void) {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("Snprintf tests");
  tc = tcase_create("Snprintf tests");
  tcase_add_test(tc, test_snprintf_nospec);
  tcase_add_test(tc, test_snprintf_s);
  tcase_add_test(tc, test_snprintf_llx);
  tcase_add_test(tc, test_snprintf_llx_start);
  tcase_add_test(tc, test_snprintf_llx_middle);
  tcase_add_test(tc, test_snprintf_llx_end);
  tcase_add_test(tc, test_snprintf_s_start);
  tcase_add_test(tc, test_snprintf_s_middle);
  tcase_add_test(tc, test_snprintf_s_end);
  tcase_add_test(tc, test_snprintf_proc_end);
  tcase_add_test(tc, test_snprintf_only_llx);
  tcase_add_test(tc, test_snprintf_only_s);
  tcase_add_test(tc, test_snprintf_combination);
  tcase_add_test(tc, test_snprintf_empty);
  tcase_add_test(tc, test_snprintf_low_count);
  tcase_add_test(tc, test_snprintf_format_null);
  tcase_add_test(tc, test_snprintf_str_null_count_null);
  tcase_add_test(tc, test_snprintf_count_null);
  tcase_add_test(tc, test_snprintf_llx_border);
  tcase_add_test(tc, test_snprintf_llx_cut);
  tcase_add_test(tc, test_snprintf_s_border);
  tcase_add_test(tc, test_snprintf_s_cut);
  tcase_add_test(tc, test_snprintf_llx_max);

  suite_add_tcase(s, tc);

  return s;
}
