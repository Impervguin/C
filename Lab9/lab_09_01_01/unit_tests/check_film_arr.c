#include <check.h>
#include "film.h"
#include "film_arr.h"
#include "errs.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Функция для сравнения двух массивов фильмов
 * 
 * @param arr1 - Указатель на первый массив.
 * @param arr2 - Указатель на второй массив.
 * @param asize - Размер массивов.
 * @return int - Код возврата.
 */
int film_arr_cmp(struct film_t *arr1, struct film_t *arr2, size_t asize)
{
    for (size_t i = 0; i < asize; i++)
    {
        if (memcmp(arr1, arr2, asize))
            return 0;
    }
    return 1;
}

/// Тест на поиск места в отсортированном массиве по году
/// Фильм должен быть в начале
START_TEST(test_find_place_year1)
{
    #define SIZE 3
    struct film_t film = {"bba", "aba", 1970};
    struct film_t arr[SIZE] = {
        {"aba", "aba", 1980},
        {"bba", "cba", 1980},
        {"bba", "dda", 1990}
    };
    size_t ind;
    film_find_place_by_field(arr, SIZE, &film, &ind, film_cmp_by_year);
    ck_assert_uint_eq(ind, 0);
    #undef SIZE
} END_TEST

/// Тест на поиск места в отсортированном массиве по году
/// Фильм должен быть в середине
START_TEST(test_find_place_year2)
{
    #define SIZE 3
    struct film_t film = {"bba", "aba", 1981};
    struct film_t arr[SIZE] = {
        {"aba", "aba", 1980},
        {"bba", "cba", 1980},
        {"bba", "dda", 1990}
    };
    size_t ind;
    film_find_place_by_field(arr, SIZE, &film, &ind, film_cmp_by_year);
    ck_assert_uint_eq(ind, 2);
    #undef SIZE
} END_TEST

/// Тест на поиск места в отсортированном массиве по названию
/// Фильм должен быть в начале, после первого элемента
START_TEST(test_find_place_title1)
{
    #define SIZE 3
    struct film_t film = {"aba", "aba", 1981};
    struct film_t arr[SIZE] = {
        {"aba", "aba", 1980},
        {"bba", "cba", 1980},
        {"bba", "dda", 1990}
    };
    size_t ind;
    film_find_place_by_field(arr, SIZE, &film, &ind, film_cmp_by_title);
    ck_assert_uint_eq(ind, 1);
    #undef SIZE
} END_TEST

/// Тест на поиск места в отсортированном массиве по названию
/// Фильм должен быть в конце
START_TEST(test_find_place_title2)
{
    #define SIZE 3
    struct film_t film = {"bba", "aba", 1981};
    struct film_t arr[SIZE] = {
        {"aba", "aba", 1980},
        {"bba", "cba", 1980},
        {"bba", "dda", 1990}
    };
    size_t ind;
    film_find_place_by_field(arr, SIZE, &film, &ind, film_cmp_by_title);
    ck_assert_uint_eq(ind, 3);
    #undef SIZE
} END_TEST

/// Тест на поиск места в отсортированном массиве по имени режиссера
/// Фильм должен быть в начале, после первого элемента
START_TEST(test_find_place_name1)
{
    #define SIZE 3
    struct film_t film = {"bba", "aba", 1981};
    struct film_t arr[SIZE] = {
        {"aba", "aba", 1980},
        {"bba", "cba", 1980},
        {"bba", "dda", 1990}
    };
    size_t ind;
    film_find_place_by_field(arr, SIZE, &film, &ind, film_cmp_by_name);
    ck_assert_uint_eq(ind, 1);
    #undef SIZE
} END_TEST

/// Тест на поиск места в отсортированном массиве по имени режиссера
/// Фильм должен быть в начале, после первого элемента
START_TEST(test_find_place_name2)
{
    #define SIZE 3
    struct film_t film = {"bba", "bba", 1981};
    struct film_t arr[SIZE] = {
        {"aba", "aba", 1980},
        {"bba", "cba", 1980},
        {"bba", "dda", 1990}
    };
    size_t ind;
    film_find_place_by_field(arr, SIZE, &film, &ind, film_cmp_by_name);
    ck_assert_uint_eq(ind, 1);
    #undef SIZE
} END_TEST

/// Тест на поиск места в отсортированном массиве по имени режиссера
/// Фильм должен быть в конце
START_TEST(test_find_place_name3)
{
    #define SIZE 3
    struct film_t film = {"bba", "fba", 1981};
    struct film_t arr[SIZE] = {
        {"aba", "aba", 1980},
        {"bba", "cba", 1980},
        {"bba", "dda", 1990}
    };
    size_t ind;
    film_find_place_by_field(arr, SIZE, &film, &ind, film_cmp_by_name);
    ck_assert_uint_eq(ind, 3);
    #undef SIZE
} END_TEST

/**
 * @brief Создает suite для тестирования функции film_find_place_by_field.
 * 
 * @return Suite* 
 */
Suite *find_place_suite(void) {
  Suite *s;
  TCase *tc_find_place;

  s = suite_create("Find place");
  tc_find_place = tcase_create("Film find place test");
  tcase_add_test(tc_find_place, test_find_place_year1);
  tcase_add_test(tc_find_place, test_find_place_year2);
  tcase_add_test(tc_find_place, test_find_place_title1);
  tcase_add_test(tc_find_place, test_find_place_title2);
  tcase_add_test(tc_find_place, test_find_place_name1);
  tcase_add_test(tc_find_place, test_find_place_name2);
  tcase_add_test(tc_find_place, test_find_place_name3);

  suite_add_tcase(s, tc_find_place);

  return s;
}

/// Тест на вставку фильма в массив фильма. Проверяется вставка в самое начало.
START_TEST(test_insert_name_0)
{
    #define SIZE 3
    size_t ind = 0;
    struct film_t film = {"bba", "fba", 1981};
    struct film_t arr[SIZE + 1] = {
        {"aba", "aba", 1980},
        {"bba", "cba", 1980},
        {"bba", "dda", 1990}
    };
    struct film_t earr[SIZE + 1] = {
        {"bba", "fba", 1981},
        {"aba", "aba", 1980},
        {"bba", "cba", 1980},
        {"bba", "dda", 1990}
    };
    size_t size = SIZE;
    film_insert(arr, &size, &film, ind);
    ck_assert_uint_eq(film_arr_cmp(arr, earr, SIZE + 1), 1);
    #undef SIZE
} END_TEST

/// Тест на вставку фильма в массив фильма. Проверяется вставка в середину.
START_TEST(test_insert_name_1)
{
    #define SIZE 3
    size_t ind = 1;
    struct film_t film = {"bba", "fba", 1981};
    struct film_t arr[SIZE + 1] = {
        {"aba", "aba", 1980},
        {"bba", "cba", 1980},
        {"bba", "dda", 1990}
    };
    struct film_t earr[SIZE + 1] = {
        {"aba", "aba", 1980},
        {"bba", "fba", 1981},
        {"bba", "cba", 1980},
        {"bba", "dda", 1990}
    };
    size_t size = SIZE;
    film_insert(arr, &size, &film, ind);
    ck_assert_uint_eq(film_arr_cmp(arr, earr, SIZE + 1), 1);
    #undef SIZE
} END_TEST

/// Тест на вставку фильма в массив фильма. Проверяется вставка в середину.
START_TEST(test_insert_name_2)
{
    #define SIZE 3
    size_t ind = 2;
    struct film_t film = {"bba", "fba", 1981};
    struct film_t arr[SIZE + 1] = {
        {"aba", "aba", 1980},
        {"bba", "cba", 1980},
        {"bba", "dda", 1990}
    };
    struct film_t earr[SIZE + 1] = {
        {"aba", "aba", 1980},
        {"bba", "cba", 1980},
        {"bba", "fba", 1981},
        {"bba", "dda", 1990}
    };
    size_t size = SIZE;
    film_insert(arr, &size, &film, ind);
    ck_assert_uint_eq(film_arr_cmp(arr, earr, SIZE + 1), 1);
    #undef SIZE
} END_TEST

/// Тест на вставку фильма в массив фильма. Проверяется вставка в конец.
START_TEST(test_insert_name_3)
{
    #define SIZE 3
    size_t ind = 3;
    struct film_t film = {"bba", "fba", 1981};
    struct film_t arr[SIZE + 1] = {
        {"aba", "aba", 1980},
        {"bba", "cba", 1980},
        {"bba", "dda", 1990}
    };
    struct film_t earr[SIZE + 1] = {
        {"aba", "aba", 1980},
        {"bba", "cba", 1980},
        {"bba", "dda", 1990},
        {"bba", "fba", 1981}
    };
    size_t size = SIZE;
    film_insert(arr, &size, &film, ind);
    ck_assert_uint_eq(film_arr_cmp(arr, earr, SIZE + 1), 1);
    #undef SIZE
} END_TEST

/**
 * @brief Создает suite для тестирования функции film_insert.
 * 
 * @return Suite* 
 */
Suite *insert_suite(void) {
  Suite *s;
  TCase *tc_insert;

  s = suite_create("Film insert");
  tc_insert = tcase_create("Film insert test");
  tcase_add_test(tc_insert, test_insert_name_0);
  tcase_add_test(tc_insert, test_insert_name_1);
  tcase_add_test(tc_insert, test_insert_name_2);
  tcase_add_test(tc_insert, test_insert_name_3);
    
  suite_add_tcase(s, tc_insert);

  return s;
}

/// Функция на тестирование генерации field_t по строке. Проверяется создание по строке year
START_TEST(test_gen_field_year)
{
    field_t ft;
    int rc = gen_field_t("year", &ft);
    ck_assert_int_eq(rc, ERR_OK);
    ck_assert_uint_eq(ft, YEAR);
    #undef SIZE
} END_TEST

/// Функция на тестирование генерации field_t по строке. Проверяется создание по строке title
START_TEST(test_gen_field_title)
{
    field_t ft;
    int rc = gen_field_t("title", &ft);
    ck_assert_int_eq(rc, ERR_OK);
    ck_assert_uint_eq(ft, TITLE);
    #undef SIZE
} END_TEST

/// Функция на тестирование генерации field_t по строке. Проверяется создание по строке name
START_TEST(test_gen_field_name)
{
    field_t ft;
    int rc = gen_field_t("name", &ft);
    ck_assert_int_eq(rc, ERR_OK);
    ck_assert_uint_eq(ft, NAME);
    #undef SIZE
} END_TEST

/// Функция на тестирование генерации field_t по строке. Проверяется создание по некорректной строке
START_TEST(test_gen_field_err)
{
    field_t ft;
    int rc = gen_field_t("yeadaar", &ft);
    ck_assert_int_eq(rc, ERR_NOT_FOUND);
    #undef SIZE
} END_TEST

/**
 * @brief Создает suite для тестирования функции gen_field_t.
 * 
 * @return Suite* 
 */
Suite *gen_field_suite(void) {
  Suite *s;
  TCase *tc_gen;

  s = suite_create("Gen field");
  tc_gen = tcase_create("Gen field test");
  tcase_add_test(tc_gen, test_gen_field_year);
  tcase_add_test(tc_gen, test_gen_field_title);
  tcase_add_test(tc_gen, test_gen_field_name);
  tcase_add_test(tc_gen, test_gen_field_err);
    
  suite_add_tcase(s, tc_gen);

  return s;
}
