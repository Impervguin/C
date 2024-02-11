#include <check.h>
#include "mat.h"
#include "errs.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Тест на создание и закрытие матрицы 1 на 1. С помощью valgrind можно проверить на утечки при освобождении.
 * 
 */
START_TEST(create_free_test1)
{
    double **mat = create_matrix(1, 1);
    free_matrix(mat, 1);
}

/**
 * @brief Тест на создание и закрытие матрицы 5 на 3. С помощью valgrind можно проверить на утечки при освобождении.
 * 
 */
START_TEST(create_free_test2)
{
    double **mat = create_matrix(5, 3);
    free_matrix(mat, 5);
}

/**
 * @brief Создает suite для тестирования функций create_matrix и free_matrix.
 * 
 * @return Suite* 
 */
Suite *create_free_suite(void) {
  Suite *s;
  TCase *tc_cf;

  s = suite_create("Create-free");

  tc_cf = tcase_create("Create-free tests");
  tcase_add_test(tc_cf, create_free_test1);
  tcase_add_test(tc_cf, create_free_test2);
  suite_add_tcase(s, tc_cf);

  return s;
}
