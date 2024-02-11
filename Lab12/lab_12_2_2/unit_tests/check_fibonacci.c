#include <check.h>
#include "fibonacci.h"



 /**
  * @brief Функция для сравнения двух массивов
  * 
  * @param [in] arr1 - Первый массив
  * @param [in] arr2 - Второй массив
  * @param arr_s - Размер массивов
  * @return int - 0 - равны, иначе 1
  */
int cmp_array(const int *arr1, const int *arr2, size_t arr_s)
{
    for (size_t i = 0; i < arr_s; i++)
        if (arr1[i] != arr2[i])
            return 1;
    return 0;
}


/// Тест на массив фибоначчи для 1-го числа(0)
START_TEST(test_fibonacci_1)
{
    #define SIZE 1

    int earr[SIZE] = {0};
    int arr[SIZE];

    int res = fill_fibonacci_arr(arr, SIZE);
    ck_assert_int_eq(res, OK);
    ck_assert_int_eq(cmp_array(earr, arr, SIZE), 0);

    #undef SIZE
} END_TEST

/// Тест на массив фибоначчи для 2-го числа(1)
START_TEST(test_fibonacci_2)
{
    #define SIZE 2

    int earr[SIZE] = {0, 1};
    int arr[SIZE];

    int res = fill_fibonacci_arr(arr, SIZE);
    ck_assert_int_eq(res, OK);
    ck_assert_int_eq(cmp_array(earr, arr, SIZE), 0);

    #undef SIZE
} END_TEST

/// Тест на массив фибоначчи для 3-х чисел
START_TEST(test_fibonacci_3)
{
    #define SIZE 3

    int earr[SIZE] = {0, 1, 1};
    int arr[SIZE];

    int res = fill_fibonacci_arr(arr, SIZE);
    ck_assert_int_eq(res, OK);
    ck_assert_int_eq(cmp_array(earr, arr, SIZE), 0);

    #undef SIZE
} END_TEST

/// Тест на массив фибоначчи для 4-х чисел
START_TEST(test_fibonacci_4)
{
    #define SIZE 4

    int earr[SIZE] = {0, 1, 1, 2};
    int arr[SIZE];

    int res = fill_fibonacci_arr(arr, SIZE);
    ck_assert_int_eq(res, OK);
    ck_assert_int_eq(cmp_array(earr, arr, SIZE), 0);

    #undef SIZE
} END_TEST

/// Тест на массив фибоначчи для 5-и чисел
START_TEST(test_fibonacci_5)
{
    #define SIZE 5

    int earr[SIZE] = {0, 1, 1, 2, 3};
    int arr[SIZE];

    int res = fill_fibonacci_arr(arr, SIZE);
    ck_assert_int_eq(res, OK);
    ck_assert_int_eq(cmp_array(earr, arr, SIZE), 0);

    #undef SIZE
} END_TEST

/// Тест на массив фибоначчи для четного кол-ва чисел
START_TEST(test_fibonacci_10)
{
    #define SIZE 10

    int earr[SIZE] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    int arr[SIZE];

    int res = fill_fibonacci_arr(arr, SIZE);
    ck_assert_int_eq(res, OK);
    ck_assert_int_eq(cmp_array(earr, arr, SIZE), 0);

    #undef SIZE
} END_TEST

/// Тест на массив фибоначчи для нечетного кол-ва чисел
START_TEST(test_fibonacci_13)
{
    #define SIZE 13

    int earr[SIZE] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
    int arr[SIZE];

    int res = fill_fibonacci_arr(arr, SIZE);
    ck_assert_int_eq(res, OK);
    ck_assert_int_eq(cmp_array(earr, arr, SIZE), 0);

    #undef SIZE
} END_TEST

/// Тест на массив фибоначчи с нулевым вводом
START_TEST(test_fibonacci_0)
{
    #define SIZE 0

    // int earr[SIZE] = {0};
    int t = 10;
    int *arr = &t;

    int res = fill_fibonacci_arr(arr, SIZE);
    ck_assert_int_eq(res, ERR_ARGS_FIB);
    // ck_assert_int_eq(cmp_array(earr, arr, SIZE), 0);

    #undef SIZE
} END_TEST

/// Тест на массив фибоначчи с нулевым массивом
START_TEST(test_fibonacci_null)
{
    #define SIZE 4

    // int earr[SIZE] = {0};
    int *arr = NULL;

    int res = fill_fibonacci_arr(arr, SIZE);
    ck_assert_int_eq(res, ERR_ARGS_FIB);
    // ck_assert_int_eq(cmp_array(earr, arr, SIZE), 0);

    #undef SIZE
} END_TEST


/**
 * @brief Создает suite для тестирования fill_fibonacci_arr.
 * 
 * @return Suite* 
 */
Suite *fibonacci_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("Fibonacci");
  tc = tcase_create("Fibonacci");

  tcase_add_test(tc, test_fibonacci_0);
  tcase_add_test(tc, test_fibonacci_1);
  tcase_add_test(tc, test_fibonacci_2);
  tcase_add_test(tc, test_fibonacci_3);
  tcase_add_test(tc, test_fibonacci_4);
  tcase_add_test(tc, test_fibonacci_5);
  tcase_add_test(tc, test_fibonacci_10);
  tcase_add_test(tc, test_fibonacci_13);
  tcase_add_test(tc, test_fibonacci_null);
  suite_add_tcase(s, tc);

  return s;
}

