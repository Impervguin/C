#include <check.h>
#include "arr.h"


 /**
  * @brief Функция для сравнения двух массивов
  * 
  * @param [in] arr1 - Первый массив
  * @param [in] arr2 - Второй массив
  * @param arr_s - Размер массивов
  * @return int - 0 - равны, иначе 1
  */
int cmp_iarray(const int *arr1, const int *arr2, size_t arr_s)
{
    for (size_t i = 0; i < arr_s; i++)
        if (arr1[i] != arr2[i])
            return 1;
    return 0;
}


/// Тест на объединение массивов с первым вхождениемя из второго, размеры 1
START_TEST(test_extend_1_1)
{
    #define SIZE_SRC 1
    #define SIZE_DST 1
    #define ESIZE 2

    int earr[ESIZE] = {10, 10};
    int src[SIZE_SRC] = {10};
    int dst[ESIZE] = {10};

    size_t size = 0;
    extend_w_uniq(dst, SIZE_DST, ESIZE, src, SIZE_SRC, &size);
    ck_assert_uint_eq(size, ESIZE);
    ck_assert_int_eq(cmp_iarray(earr, dst, ESIZE), 0);
    
    #undef SIZE_SRC 
    #undef SIZE_DST 
    #undef ESIZE
} END_TEST

/// Тест на объединение массивов с первым вхождениемя из второго, размеры 1 и 2 с повторениями
START_TEST(test_extend_2_1)
{
    #define SIZE_SRC 2
    #define SIZE_DST 1
    #define ESIZE 2

    int earr[ESIZE] = {10, 10};
    int src[SIZE_SRC] = {10, 10};
    int dst[ESIZE] = {10};

    size_t size = 0;
    extend_w_uniq(dst, SIZE_DST, ESIZE, src, SIZE_SRC, &size);
    ck_assert_uint_eq(size, ESIZE);
    ck_assert_int_eq(cmp_iarray(earr, dst, ESIZE), 0);

    #undef SIZE_SRC 
    #undef SIZE_DST 
    #undef ESIZE
} END_TEST

/// Тест на объединение массивов с первым вхождениемя из второго, размеры 2 и 1 с повторениями
START_TEST(test_extend_1_2)
{
    #define SIZE_SRC 1
    #define SIZE_DST 2
    #define ESIZE 3

    int earr[ESIZE] = {10, 10, 10};
    int src[SIZE_SRC] = {10};
    int dst[ESIZE] = {10, 10};

    size_t size = 0;
    extend_w_uniq(dst, SIZE_DST, ESIZE, src, SIZE_SRC, &size);
    ck_assert_uint_eq(size, ESIZE);
    ck_assert_int_eq(cmp_iarray(earr, dst, ESIZE), 0);

    #undef SIZE_SRC 
    #undef SIZE_DST 
    #undef ESIZE
} END_TEST

/// Тест на объединение массивов с первым вхождениемя из второго, случайные размеры
START_TEST(test_extend_7_4)
{
    #define SIZE_SRC 7
    #define SIZE_DST 4
    #define ESIZE 9

    int earr[ESIZE] = {10, 10, 60, 80, 10, 20, 40, 60 ,70};
    int src[SIZE_SRC] = {10, 20, 10, 40, 60, 20, 70};
    int dst[ESIZE] = {10, 10, 60, 80};

    size_t size = 0;
    extend_w_uniq(dst, SIZE_DST, ESIZE, src, SIZE_SRC, &size);
    ck_assert_uint_eq(size, ESIZE);
    ck_assert_int_eq(cmp_iarray(earr, dst, ESIZE), 0);

    #undef SIZE_SRC 
    #undef SIZE_DST 
    #undef ESIZE
} END_TEST

/// Тест на объединение массивов с первым вхождениемя из второго, второй массив пустой
START_TEST(test_extend_0_4)
{
    #define SIZE_SRC 0
    #define SIZE_DST 4
    #define ESIZE 4

    int earr[ESIZE] = {10, 10, 20, 40};
    int t;
    int *src = &t;
    int dst[ESIZE] = {10, 10, 20, 40};

    size_t size = 0;
    extend_w_uniq(dst, SIZE_DST, ESIZE, src, SIZE_SRC, &size);
    // ck_assert_uint_eq(size, ESIZE);
    ck_assert_int_eq(cmp_iarray(earr, dst, ESIZE), 0);

    #undef SIZE_SRC 
    #undef SIZE_DST 
    #undef ESIZE
} END_TEST

/// Тест на объединение массивов с первым вхождениемя из второго, первый массив пустой
START_TEST(test_extend_5_0)
{
    #define SIZE_SRC 5
    #define SIZE_DST 0
    #define ESIZE 3

    int earr[ESIZE] = {-10, 20, 43};
    int src[SIZE_SRC] = {-10, 20, 43, 43, 20};
    int dst[ESIZE];

    size_t size = 0;
    extend_w_uniq(dst, SIZE_DST, ESIZE, src, SIZE_SRC, &size);
    ck_assert_uint_eq(size, ESIZE);
    ck_assert_int_eq(cmp_iarray(earr, dst, ESIZE), 0);

    #undef SIZE_SRC 
    #undef SIZE_DST 
    #undef ESIZE
} END_TEST

/// Тест на объединение массивов с первым вхождениемя из второго, оба массива пустые
START_TEST(test_extend_0_0)
{
    #define SIZE_SRC 0
    #define SIZE_DST 0
    #define ESIZE 0

    // int earr[ESIZE] = {10, 10};
    // int src[SIZE_SRC] = {10};
    // int dst[ESIZE] = {10};
    int t;
    int *src = &t;
    int a;
    int *dst = &a;

    size_t size = 0;
    extend_w_uniq(dst, SIZE_DST, ESIZE, src, SIZE_SRC, &size);
    ck_assert_uint_eq(size, ESIZE);
    // ck_assert_int_eq(cmp_iarray(earr, dst, ESIZE), 0);

    #undef SIZE_SRC 
    #undef SIZE_DST 
    #undef ESIZE
} END_TEST

/// Тест на объединение массивов с первым вхождениемя из второго, вместо второго null
START_TEST(test_extend_src_null)
{
    #define SIZE_SRC 1
    #define SIZE_DST 4
    #define ESIZE 4

    int earr[ESIZE] = {10, 10, 25, 25};
    int *src = NULL;
    int dst[ESIZE] = {10, 10, 25, 25};

    size_t size = 0;
    extend_w_uniq(dst, SIZE_DST, ESIZE, src, SIZE_SRC, &size);
    // ck_assert_uint_eq(size, ESIZE);
    ck_assert_int_eq(cmp_iarray(earr, dst, ESIZE), 0);

    #undef SIZE_SRC 
    #undef SIZE_DST 
    #undef ESIZE
} END_TEST

/// Тест на объединение массивов с первым вхождениемя из второго, вмксто первого null
/// Должен вернуть необходимый размер по второй
START_TEST(test_extend_dst_null)
{
    #define SIZE_SRC 5
    #define SIZE_DST 0
    #define ESIZE 3

    // int earr[ESIZE] = {};
    int src[SIZE_SRC] = {40, 50, 40, 50, 81};
    int *dst = NULL;

    size_t size = 0;
    extend_w_uniq(dst, SIZE_DST, ESIZE, src, SIZE_SRC, &size);
    ck_assert_uint_eq(size, ESIZE);
    // ck_assert_int_eq(cmp_iarray(earr, dst, ESIZE), 0);

    #undef SIZE_SRC 
    #undef SIZE_DST 
    #undef ESIZE
} END_TEST

/// Тест на объединение массивов с первым вхождениемя из второго, вмксто первого null
/// Должен вернуть необходимый размер для итогового
START_TEST(test_extend_size_gt_max_size)
{
    #define SIZE_SRC 7
    #define SIZE_DST 2
    #define ESIZE 2

    int earr[ESIZE] = {10, 20};
    int src[SIZE_SRC] = {40, 50, 40, 50, 81, 64, 12};
    int dst[ESIZE] = {10, 20};

    size_t size = 0;
    extend_w_uniq(dst, SIZE_DST, ESIZE, src, SIZE_SRC, &size);
    ck_assert_uint_eq(size, SIZE_DST + 5);
    ck_assert_int_eq(cmp_iarray(earr, dst, ESIZE), 0);

    #undef SIZE_SRC 
    #undef SIZE_DST 
    #undef ESIZE
} END_TEST

/**
 * @brief Создает suite для тестирования extend_w_uniq.
 * 
 * @return Suite* 
 */
Suite *extend_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("Extend");
  tc = tcase_create("Extend");

  tcase_add_test(tc, test_extend_1_1);
  tcase_add_test(tc, test_extend_2_1);
  tcase_add_test(tc, test_extend_1_2);
  tcase_add_test(tc, test_extend_0_4);
  tcase_add_test(tc, test_extend_5_0);
  tcase_add_test(tc, test_extend_0_0);
  tcase_add_test(tc, test_extend_7_4);
  tcase_add_test(tc, test_extend_dst_null);
  tcase_add_test(tc, test_extend_src_null);
  tcase_add_test(tc, test_extend_size_gt_max_size);
  suite_add_tcase(s, tc);

  return s;
}

