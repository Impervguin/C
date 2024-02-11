#include <check.h>
#include "sort.h"
#include "errs.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief Функция для сравнения массивов целых чисел, заданных указателями
 * 
 * @param [in] pb1 - Указатель на начало первого массива.
 * @param [in] pe1 - Указатель на конец первого массива.
 * @param [in] pb2 - Указатель на начало второго массива.
 * @param [in] pe2 - Указатель на конец второго массива.
 * @return int 1 - Не равны, 0 - равны
 */
int cmp_parray(const int *pb1, const int *pe1, const int *pb2, const int *pe2)
{
    int s = pe1 - pb1;
    if (s < pe2 - pb2)
        return 0;
    for (int i = 0; i < s; i++, pb1++, pb2++) 
        if (*pb1 != *pb2)
            return 0;
    return 1;
}

 /**
  * @brief Функция для сравнения двух массивов
  * 
  * @param [in] arr1 - Первый массив
  * @param [in] arr2 - Второй массив
  * @param arr_s - Размер массивов
  */
void cmp_array(const int *arr1, const int *arr2, size_t arr_s)
{
    for (size_t i = 0; i < arr_s; i++)
        ck_assert_int_eq(arr1[i], arr2[i]);
}

/**
 * @brief Функция для сравнения char - ов
 * 
 * @param [in] s1 - Указатель на первый char
 * @param [in] s2 - Указатель на второй char
 * @return int >0, если второе больше первого, ноль если равны, иначе <0
 */
int compare_char(const void *s1, const void *s2)
{
    const char *p1 = s1, *p2 = s2;
    return *p1 - *p2;
}

/**
 * @brief Функция для сравнения строка
 * 
 * @param [in] s1 - Указатель на первую строку
 * @param [in] s2 - Указатель на вторую строку
 * @return int Аналогичен strcmp
 */
int compare_str(const void *s1, const void *s2)
{
    const char *p1 = s1, *p2 = s2;
    return strcmp(p1, p2);
}


/**
 * @brief Тест на функцию compare_int.
 * Первое число больше второго.
 */
START_TEST(test_cmp_int_gt)
{
    int a = 2;
    int b = 1;

    ck_assert_int_eq(compare_int(&a, &b), 1);
} END_TEST


/**
 * @brief Тест на функцию compare_int.
 * Первое число равно второму.
 */
START_TEST(test_cmp_int_eq)
{
    int a = 1;
    int b = 1;

    ck_assert_int_eq(compare_int(&a, &b), 0);
} END_TEST


/**
 * @brief Тест на функцию compare_int.
 * Первое число меньше второго.
 */
START_TEST(test_cmp_int_lt)
{
    int a = 0;
    int b = 1;

    ck_assert_int_eq(compare_int(&a, &b), -1);
} END_TEST

/**
 * @brief Создает suite для тестирования compare_int.
 * 
 * @return Suite* 
 */
Suite *compare_suite(void) {
  Suite *s;
  TCase *tc_cmp;

  s = suite_create("Compare int");
  tc_cmp = tcase_create("Cmp");

  tcase_add_test(tc_cmp, test_cmp_int_gt);
  tcase_add_test(tc_cmp, test_cmp_int_eq);
  tcase_add_test(tc_cmp, test_cmp_int_lt);
  suite_add_tcase(s, tc_cmp);

  return s;
}

/**
 * @brief Тест на функцию mysort.
 * Тест с одним элементом в массиве.
 */
START_TEST(test_sort_1)
{
   int a[] = {1};
   int a_s[] = {1};
   size_t s = sizeof(a) / sizeof a[0];

   mysort(a, s, sizeof(int), compare_int);
   cmp_array(a, a_s, s);
} END_TEST

/**
 * @brief Тест на функцию mysort.
 * Тест с двумя элементами в массиве, расположенными по возрастанию.
 */
START_TEST(test_sort_2_s)
{
   int a[] = {1, 2};
   int a_s[] = {1, 2};
   size_t s = sizeof(a) / sizeof a[0];

   mysort(a, s, sizeof(int), compare_int);
   cmp_array(a, a_s, s);
} END_TEST

/**
 * @brief Тест на функцию mysort.
 * Тест с двумя элементами в массиве, расположенными по убыванию.
 */
START_TEST(test_sort_2_ns)
{
   int a[] = {2, 1};
   int a_s[] = {1, 2};
   size_t s = sizeof(a) / sizeof a[0];

   mysort(a, s, sizeof(int), compare_int);
   cmp_array(a, a_s, s);
} END_TEST

/**
 * @brief Тест на функцию mysort.
 * Тест с 5-ю элементами в массиве, расположенными по возрастанию.
 */
START_TEST(test_sort_5_s)
{
   int a[] = {1, 2, 3, 4, 5};
   int a_s[] = {1, 2, 3, 4, 5};
   size_t s = sizeof(a) / sizeof a[0];

   mysort(a, s, sizeof(int), compare_int);
   cmp_array(a, a_s, s);
} END_TEST

/**
 * @brief Тест на функцию mysort.
 * Тест с 5-ю элементами в массиве, расположенными случайно.
 */
START_TEST(test_sort_5_ns)
{
   int a[] = {5, 4, 3, 2, 1};
   int a_s[] = {1, 2, 3, 4, 5};
   size_t s = sizeof(a) / sizeof a[0];

   mysort(a, s, sizeof(int), compare_int);
   cmp_array(a, a_s, s);
} END_TEST

/**
 * @brief Тест на функцию mysort.
 * Тест с 5-ю элементами в массиве, расположенными по убыванию.
 */
START_TEST(test_sort_5_r)
{
   int a[] = {2, 1, 4, 3, 5};
   int a_s[] = {1, 2, 3, 4, 5};
   size_t s = sizeof(a) / sizeof a[0];

   mysort(a, s, sizeof(int), compare_int);
   cmp_array(a, a_s, s);
} END_TEST

/**
 * @brief Тест на функцию mysort.
 * Тест с 6-ю элементами в массиве, расположенными по возрастанию.
 */
START_TEST(test_sort_6_s)
{
   int a[] = {1, 2, 3, 4, 5, 6};
   int a_s[] = {1, 2, 3, 4, 5, 6};
   size_t s = sizeof(a) / sizeof a[0];

   mysort(a, s, sizeof(int), compare_int);
   cmp_array(a, a_s, s);
} END_TEST

/**
 * @brief Тест на функцию mysort.
 * Тест с 6-ю элементами в массиве, расположенными случайно.
 */
START_TEST(test_sort_6_ns)
{
   int a[] = {6, 5, 4, 3, 2, 1};
   int a_s[] = {1, 2, 3, 4, 5, 6};
   size_t s = sizeof(a) / sizeof a[0];

   mysort(a, s, sizeof(int), compare_int);
   cmp_array(a, a_s, s);
} END_TEST

/**
 * @brief Тест на функцию mysort.
 * Тест с 6-ю элементами в массиве, расположенными по убыванию.
 */
START_TEST(test_sort_6_r)
{
   int a[] = {4, 2, 1, 6, 3, 5};
   int a_s[] = {1, 2, 3, 4, 5, 6};
   size_t s = sizeof(a) / sizeof a[0];

   mysort(a, s, sizeof(int), compare_int);
   cmp_array(a, a_s, s);
} END_TEST

/**
 * @brief Тест на функцию mysort.
 * Тест с пустым массивом.
 */
START_TEST(test_sort_0)
{
   int *a = NULL;
   int *a_s = NULL;
   size_t s = 0;

   mysort(a, s, sizeof(int), compare_int);
   cmp_array(a, a_s, s);
} END_TEST

/**
 * @brief Тест на функцию mysort.
 * Тест с массивом char-ов.
 */
START_TEST(test_sort_char)
{
   char a[] = {'b', 'a', 'b', 'c'};
   char a_s[] = {'a', 'b', 'b', 'c'};
   size_t s = sizeof(a) / sizeof(a[0]);

   mysort(a, s, sizeof(char), compare_char);
   for (size_t i = 0; i < 4; i++)
       ck_assert_int_eq(a[i] == a_s[i], 1);
} END_TEST

/**
 * @brief Тест на функцию mysort.
 * Тест со строками длиной 10 символов.
 */
START_TEST(test_sort_str)
{
   char a[][10] = {"mama", "papa", "brother", "sister", "sister"};
   char a_s[][10] = {"brother", "mama", "papa", "sister", "sister"};
   size_t s = sizeof(a) / sizeof(a[0]);

   mysort(a, s, sizeof(a[0]), compare_str);
   for (size_t i = 0; i < 5; i++)
        ck_assert_int_eq(strcmp(a[i], a_s[i]), 0);
} END_TEST

/**
 * @brief Создает suite для тестирования mysort.
 * 
 * @return Suite* 
 */
Suite *sort_suite(void) {
  Suite *s;
  TCase *tc_sort, *tc_universal;

  s = suite_create("Mysort");
  tc_sort = tcase_create("Standard sort checks");
  tcase_add_test(tc_sort, test_sort_0);
  tcase_add_test(tc_sort, test_sort_1);
  tcase_add_test(tc_sort, test_sort_2_ns);
  tcase_add_test(tc_sort, test_sort_2_s);
  tcase_add_test(tc_sort, test_sort_5_ns);
  tcase_add_test(tc_sort, test_sort_5_r);
  tcase_add_test(tc_sort, test_sort_5_s);
  tcase_add_test(tc_sort, test_sort_6_ns);
  tcase_add_test(tc_sort, test_sort_6_r);
  tcase_add_test(tc_sort, test_sort_6_s);
  suite_add_tcase(s, tc_sort);

  tc_universal = tcase_create("Tests on universality of sort");
  tcase_add_test(tc_universal, test_sort_str);
  tcase_add_test(tc_universal, test_sort_char);
  suite_add_tcase(s, tc_universal);

  return s;
}

/**
 * @brief Тест на функцию key.
 * Тест с пустым массивом.
 */
START_TEST(test_key_0)
{
    int *pb1 = NULL, *pe1 = NULL;
    int *pbexp = NULL, *peexp = NULL;
    int *pb2 = NULL, *pe2 = NULL;
    int eq = 1;
    int rc;
    int rc_s = ERR_ARR_EMPTY;
    size_t esize = 0;
    size_t arr_size = 0;

    rc = key(pb1, pe1, pb2, &pe2, &arr_size);
    if (!rc)
        eq = cmp_parray(pbexp, peexp, pb2, pe2);
    
    ck_assert_int_eq(arr_size, esize);
    ck_assert_int_eq(rc, rc_s);
    ck_assert_int_eq(eq, 1);
} END_TEST

/**
 * @brief Тест на функцию key.
 * Тест с одним элементом.
 */
START_TEST(test_key_1)
{
    int a[] = {1};
    int *pb1 = a, *pe1 = a + sizeof(a)/sizeof(a[0]);
    int *pbexp = NULL, *peexp = NULL;
    int *pb2 = NULL, *pe2 = NULL;
    int eq = 1;
    int rc;
    int rc_s = ERR_ARR_EMPTY;
    size_t esize = 0;
    size_t arr_size = 0;

    rc = key(pb1, pe1, pb2, &pe2, &arr_size);
    if (!rc)
        eq = cmp_parray(pbexp, peexp, pb2, pe2);
    
    ck_assert_int_eq(arr_size, esize);
    ck_assert_int_eq(rc, rc_s);
    ck_assert_int_eq(eq, 1);
} END_TEST

/**
 * @brief Тест на функцию key.
 * Тест с массивом из двух элементов, который при фильтрации опустеет.
 */
START_TEST(test_key_2_empty)
{ 
    int a[] = {1, 2};
    int *pb1 = a, *pe1 = a + sizeof(a)/sizeof(a[0]);
    int *pbexp = NULL, *peexp = NULL;
    int *pb2 = NULL, *pe2 = NULL;
    int eq = 1;
    int rc;
    int rc_s = ERR_ARR_EMPTY;
    size_t esize = 0;
    size_t arr_size = 0;

    rc = key(pb1, pe1, pb2, &pe2, &arr_size);
    if (!rc)
        eq = cmp_parray(pbexp, peexp, pb2, pe2);
    
    ck_assert_int_eq(arr_size, esize);
    ck_assert_int_eq(rc, rc_s);
    ck_assert_int_eq(eq, 1);
} END_TEST

/**
 * @brief Тест на функцию key.
 * Тест с массивом из двух элементов, который при фильтрации не будет пустым.
 */
START_TEST(test_key_2)
{
    int a[] = {2, 1};
    int a_s[] = {2};
    int *pb1 = a, *pe1 = a + sizeof(a)/sizeof(a[0]);
    int *pbexp = a_s, *peexp = a_s + sizeof(a_s)/sizeof(a_s[0]);
    int arr[sizeof(a)/sizeof(a[0])];
    int *pb2 = arr, *pe2 = NULL;
    int eq = 1;
    int rc;
    int rc_s = ERR_OK;
    size_t esize = 1;
    size_t arr_size = 0;

    rc = key(pb1, pe1, pb2, &pe2, &arr_size);
    if (!rc)
        eq = cmp_parray(pbexp, peexp, pb2, pe2);
    
    ck_assert_int_eq(arr_size, esize);
    ck_assert_int_eq(rc, rc_s);
    ck_assert_int_eq(eq, 1);
} END_TEST

/**
 * @brief Тест на функцию key.
 * Тест с массивом из 5-и элементов, который при фильтрации опустеет.
 */
START_TEST(test_key_5_empty)
{
    int a[] = {8, 4, 2, 1, 2};
    int *pb1 = a, *pe1 = a + sizeof(a)/sizeof(a[0]);
    int *pbexp = NULL, *peexp = NULL;
    int *pb2 = NULL, *pe2 = NULL;
    int eq = 1;
    int rc;
    int rc_s = ERR_ARR_EMPTY;
    size_t esize = 0;
    size_t arr_size = 0;

    rc = key(pb1, pe1, pb2, &pe2, &arr_size);
    if (!rc)
        eq = cmp_parray(pbexp, peexp, pb2, pe2);
    
    ck_assert_int_eq(arr_size, esize);
    ck_assert_int_eq(rc, rc_s);
    ck_assert_int_eq(eq, 1);
} END_TEST

/**
 * @brief Тест на функцию key.
 * Тест с массивом из 5-ти элементов, который при фильтрации не будет пустым.
 */
START_TEST(test_key_5)
{
    int a[] = {13, 7, 4, 2, 1};
    int a_s[] = {4, 2};
    int *pb1 = a, *pe1 = a + sizeof(a)/sizeof(a[0]);
    int *pbexp = a_s, *peexp = a_s + sizeof(a_s)/sizeof(a_s[0]);
    int arr[sizeof(a)/sizeof(a[0])];
    int *pb2 = arr, *pe2 = NULL;
    int eq = 1;
    int rc;
    int rc_s = ERR_OK;
    size_t esize = 2;
    size_t arr_size = 0;

    rc = key(pb1, pe1, pb2, &pe2, &arr_size);
    if (!rc)
        eq = cmp_parray(pbexp, peexp, pb2, pe2);
    
    ck_assert_int_eq(arr_size, esize);
    ck_assert_int_eq(rc, rc_s);
    ck_assert_int_eq(eq, 1);
} END_TEST

/**
 * @brief Создает suite для тестирования key.
 * 
 * @return Suite* 
 */
Suite *key_suite(void) {
  Suite *s;
  TCase *tc_k;

  s = suite_create("Key");

  tc_k = tcase_create("Key tests");
  tcase_add_test(tc_k, test_key_0);
  tcase_add_test(tc_k, test_key_1);
  tcase_add_test(tc_k, test_key_2_empty);
  tcase_add_test(tc_k, test_key_2);
  tcase_add_test(tc_k, test_key_5_empty);
  tcase_add_test(tc_k, test_key_5);
  suite_add_tcase(s, tc_k);

  return s;
}
