#include <check.h>
#include "film.h"
#include "errs.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/// Тест на функцию сравнения фильмов по году. Первый фильм раньше второго.
START_TEST(test_cmp_year_eq)
{
    struct film_t a = {NULL, NULL, 1980};
    struct film_t b = {NULL, NULL, 1980};

    ck_assert_int_eq(film_cmp_by_year(&a, &b), 0);
} END_TEST

/// Тест на функцию сравнения фильмов по году. Первый фильм равен второму.
START_TEST(test_cmp_year_lt)
{
    struct film_t a = {NULL, NULL, 1970};
    struct film_t b = {NULL, NULL, 1980};

    ck_assert_int_lt(film_cmp_by_year(&a, &b), 0);
} END_TEST

/// Тест на функцию сравнения фильмов по году. Первый фильм позже второго.
START_TEST(test_cmp_year_gt)
{
    struct film_t a = {NULL, NULL, 1990};
    struct film_t b = {NULL, NULL, 1980};

    ck_assert_int_ge(film_cmp_by_year(&a, &b), 0);
} END_TEST

/// Тест на функцию сравнения фильмов по названию. Первый фильм равен второму по алфавитному порядку.
START_TEST(test_cmp_title_eq)
{
    struct film_t a = {"aba", NULL, 0};
    struct film_t b = {"aba", NULL, 0};

    ck_assert_int_eq(film_cmp_by_title(&a, &b), 0);
} END_TEST

/// Тест на функцию сравнения фильмов по названию. Первый фильм позже второго по алфавитному порядку.
START_TEST(test_cmp_title_gt)
{
    struct film_t a = {"dba", NULL, 0};
    struct film_t b = {"aba", NULL, 0};

    ck_assert_int_gt(film_cmp_by_title(&a, &b), 0);
} END_TEST

/// Тест на функцию сравнения фильмов по названию. Первый фильм раньше второго по алфавитному порядку.
START_TEST(test_cmp_title_lt)
{
    struct film_t a = {"aba", NULL, 0};
    struct film_t b = {"dba", NULL, 0};

    ck_assert_int_lt(film_cmp_by_title(&a, &b), 0);
} END_TEST

/// Тест на функцию сравнения фильмов по названию. Первый фильм длиннее второго.
START_TEST(test_cmp_title_longer)
{
    struct film_t a = {"abab", NULL, 0};
    struct film_t b = {"aba", NULL, 0};

    ck_assert_int_gt(film_cmp_by_title(&a, &b), 0);
} END_TEST

/// Тест на функцию сравнения фильмов по имени режиссера. Первый фильм равен второму по алфавитному порядку.
START_TEST(test_cmp_name_eq)
{
    struct film_t a = {NULL, "aba", 0};
    struct film_t b = {NULL, "aba", 0};

    ck_assert_int_eq(film_cmp_by_name(&a, &b), 0);
} END_TEST

/// Тест на функцию сравнения фильмов по имени режиссера. Первый фильм позже второго по алфавитному порядку.
START_TEST(test_cmp_name_gt)
{
    struct film_t a = {NULL, "dba", 0};
    struct film_t b = {NULL, "aba", 0};

    ck_assert_int_gt(film_cmp_by_name(&a, &b), 0);
} END_TEST

/// Тест на функцию сравнения фильмов по имени режиссера. Первый фильм раньше второму по алфавитному порядку.
START_TEST(test_cmp_name_lt)
{
    struct film_t a = {NULL, "aba", 0};
    struct film_t b = {NULL, "dba", 0};

    ck_assert_int_lt(film_cmp_by_name(&a, &b), 0);
} END_TEST


/**
 * @brief Создает suite для тестирования функция сравнения фильмов.
 * 
 * @return Suite* 
 */
Suite *compare_suite(void) {
  Suite *s;
  TCase *tc_cmp;

  s = suite_create("Films comparison");
  tc_cmp = tcase_create("Film compare text");
  tcase_add_test(tc_cmp, test_cmp_year_eq);
  tcase_add_test(tc_cmp, test_cmp_year_lt);
  tcase_add_test(tc_cmp, test_cmp_year_gt);
  tcase_add_test(tc_cmp, test_cmp_title_eq);
  tcase_add_test(tc_cmp, test_cmp_title_gt);
  tcase_add_test(tc_cmp, test_cmp_title_lt);
  tcase_add_test(tc_cmp, test_cmp_title_longer);
  tcase_add_test(tc_cmp, test_cmp_name_eq);
  tcase_add_test(tc_cmp, test_cmp_name_gt);
  tcase_add_test(tc_cmp, test_cmp_name_lt);

  suite_add_tcase(s, tc_cmp);

  return s;
}
