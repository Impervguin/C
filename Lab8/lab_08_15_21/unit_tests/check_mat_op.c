#include <check.h>
#include "mat_op.h"
#include "mat.h"
#include "errs.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * @brief Функция для сравнения вещественных чисел
 * 
 * @param a - Первое число
 * @param b - Второе число
 * @return int - 1 Если первое больше второго, 0 - если равны, иначе -1.
 */
int cmp_double(double a, double b)
{
    double diff = a - b;
    if (diff < EPS && diff > -EPS)
        return 0;
    if (diff > EPS)
        return 1;
    return -1;
}

#define MAT_EQ 0
#define MAT_NEQ 1

int cmp_matrix(double **mat1, double **mat2, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            if (cmp_double(mat1[i][j], mat2[i][j]))
                return MAT_NEQ;
    return MAT_EQ;
}

/**
 * @brief Тест на функцию check_double_null c нулем.
 * 
 */
START_TEST(check_null_test0)
{
    ck_assert_int_eq(1, check_double_null(0));
}

/**
 * @brief Тест на функцию check_double_null c 1.
 * 
 */
START_TEST(check_null_test1)
{
    ck_assert_int_eq(0, check_double_null(1));
}

/**
 * @brief Тест на функцию check_double_null c -1.
 * 
 */
START_TEST(check_null_test2)
{
    ck_assert_int_eq(0, check_double_null(-1));
}

/**
 * @brief Тест на функцию check_double_null c 0.0001.
 * 
 */
START_TEST(check_null_test3)
{
    ck_assert_int_eq(0, check_double_null(0.0001));
}


/**
 * @brief Сьют для check_double_null.
 * 
 * @return Suite* 
 */
Suite *check_null_suite(void) {
  Suite *s;
  TCase *tc_null;

  s = suite_create("Check null");

  tc_null = tcase_create("Check null tests");
  tcase_add_test(tc_null, check_null_test0);
  tcase_add_test(tc_null, check_null_test1);
  tcase_add_test(tc_null, check_null_test2);
  tcase_add_test(tc_null, check_null_test3);
  suite_add_tcase(s, tc_null);

  return s;
}


/**
 * @brief Тест на функцию swap_rows.
 * 
 */
START_TEST(swap_rows_test1)
{
    #define ROWS 3
    #define COLS 5

    double et[ROWS][COLS] = {{1, 2, 3, 4, 5}, {11, 12, 13, 14, 15}, {6, 7, 8, 9, 10}};
    double *emat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        emat[i] = et[i];
    double t[ROWS][COLS] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    double *mat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat[i] = t[i];
    swap_rows(mat, 1, 2);

    int cmp_rc = cmp_matrix(mat, emat, ROWS, COLS);
    ck_assert_int_eq(MAT_EQ, cmp_rc);

    #undef ROWS
    #undef COLS
}

/**
 * @brief Тест на функцию swap_rows.
 * 
 */
START_TEST(swap_rows_test2)
{
    #define ROWS 3
    #define COLS 5

    double et[ROWS][COLS] = {{6, 7, 8, 9, 10}, {1, 2, 3, 4, 5}, {11, 12, 13, 14, 15}};
    double *emat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        emat[i] = et[i];
    double t[ROWS][COLS] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    double *mat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat[i] = t[i];
    swap_rows(mat, 0, 1);
    int cmp_rc = cmp_matrix(mat, emat, ROWS, COLS);
    ck_assert_int_eq(MAT_EQ, cmp_rc);
    
    #undef ROWS
    #undef COLS
}

/**
 * @brief Тест на функцию swap_cols.
 * 
 */
START_TEST(swap_cols_test1)
{
    #define ROWS 3
    #define COLS 5

    double et[ROWS][COLS] = {{5, 2, 3, 4, 1}, {10, 7, 8, 9, 6}, {15, 12, 13, 14, 11}};
    double *emat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        emat[i] = et[i];
    double t[ROWS][COLS] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    double *mat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat[i] = t[i];
    swap_cols(mat, ROWS, 0, 4);
    int cmp_rc = cmp_matrix(mat, emat, ROWS, COLS);
    ck_assert_int_eq(MAT_EQ, cmp_rc);
    
    #undef ROWS
    #undef COLS
}

/**
 * @brief Тест на функцию swap_cols.
 * 
 */
START_TEST(swap_cols_test2)
{
    #define ROWS 3
    #define COLS 5

    double et[ROWS][COLS] = {{1, 2, 4, 3, 5}, {6, 7, 9, 8, 10}, {11, 12, 14, 13, 15}};
    double *emat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        emat[i] = et[i];
    double t[ROWS][COLS] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    double *mat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat[i] = t[i];
    swap_cols(mat, 3, 2, 3);
    int cmp_rc = cmp_matrix(mat, emat, ROWS, COLS);
    ck_assert_int_eq(MAT_EQ, cmp_rc);
    
    #undef ROWS
    #undef COLS
}


/**
 * @brief Сьют на функции swap_rows и swap_cols.
 * 
 * @return Suite* 
 */
Suite *swap_suite(void) {
  Suite *s;
  TCase *tc_swap_rows, *tc_swap_cols;

  s = suite_create("Swap");

  tc_swap_rows = tcase_create("Swap rows tests");
  tcase_add_test(tc_swap_rows, swap_rows_test1);
  tcase_add_test(tc_swap_rows, swap_rows_test2);
  suite_add_tcase(s, tc_swap_rows);

  tc_swap_cols = tcase_create("Swap cols tests");
  tcase_add_test(tc_swap_cols, swap_cols_test1);
  tcase_add_test(tc_swap_cols, swap_cols_test2);
  suite_add_tcase(s, tc_swap_cols);

  return s;
}


/**
 * @brief Тест на mult_row с натуральным коэффициентом
 * 
 */
START_TEST(mult_row_test2)
{
    #define ROWS 3
    #define COLS 5

    double et[ROWS][COLS] = {{1, 2, 3, 4, 5}, {24, 28, 32, 36, 40}, {11, 12, 13, 14, 15}};
    double *emat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        emat[i] = et[i];
    double t[ROWS][COLS] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    double *mat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat[i] = t[i];
    mult_row(mat, 1, COLS, 4);
    int cmp_rc = cmp_matrix(mat, emat, ROWS, COLS);
    ck_assert_int_eq(MAT_EQ, cmp_rc);
    
    #undef ROWS
    #undef COLS
}


/**
 * @brief Тест на mult_row с коэффициентом 1
 * 
 */
START_TEST(mult_row_test1)
{
    #define ROWS 3
    #define COLS 5

    double et[ROWS][COLS] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    double *emat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        emat[i] = et[i];
    double t[ROWS][COLS] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    double *mat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat[i] = t[i];
    mult_row(mat, 0, COLS, 1);
    int cmp_rc = cmp_matrix(mat, emat, ROWS, COLS);
    ck_assert_int_eq(MAT_EQ, cmp_rc);
    
    #undef ROWS
    #undef COLS
}

/**
 * @brief Тест на mult_row с вещественным коэффициентом
 * 
 */
START_TEST(mult_row_test3)
{
    #define ROWS 3
    #define COLS 5

    double et[ROWS][COLS] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {5.5, 6, 6.5, 7, 7.5}};
    double *emat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        emat[i] = et[i];
    double t[ROWS][COLS] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    double *mat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat[i] = t[i];
    mult_row(mat, 2, COLS, 0.5);
    int cmp_rc = cmp_matrix(mat, emat, ROWS, COLS);
    ck_assert_int_eq(MAT_EQ, cmp_rc);
    
    #undef ROWS
    #undef COLS
}

/**
 * @brief Тест на mult_row с коэффициентом равным нулю.
 * 
 */
START_TEST(mult_row_test0)
{
    #define ROWS 3
    #define COLS 5

    double et[ROWS][COLS] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {0, 0, 0, 0, 0}};
    double *emat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        emat[i] = et[i];
    double t[ROWS][COLS] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    double *mat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat[i] = t[i];
    mult_row(mat, 2, COLS, 0);
    // for (size_t i = 0; i < ROWS; i++)
    // {
    //     for (size_t j = 0; j < COLS; j++)
    //     {
    //         printf("%lf ", mat[i][j]);
    //     }
    //     printf("\n");
    // }
    int cmp_rc = cmp_matrix(mat, emat, ROWS, COLS);
    ck_assert_int_eq(MAT_EQ, cmp_rc);
    
    #undef ROWS
    #undef COLS
}

/**
 * @brief Сьют на mult_row
 * 
 * @return Suite* 
 */
Suite *mult_row_suite(void) {
  Suite *s;
  TCase *tc_mrow;

  s = suite_create("Mult row");

  tc_mrow = tcase_create("Mult row tests");
  tcase_add_test(tc_mrow, mult_row_test0);
  tcase_add_test(tc_mrow, mult_row_test1);
  tcase_add_test(tc_mrow, mult_row_test2);
  tcase_add_test(tc_mrow, mult_row_test3);
  suite_add_tcase(s, tc_mrow);
  return s;
}

/**
 * @brief Тест на sub_matrix_rows с коэффициентом 1
 * 
 */
START_TEST(sub_matrix_rows_test1)
{
    #define ROWS 3
    #define COLS 5

    double et[ROWS][COLS] = {{1, 2, 3, 4, 5}, {5, 5, 5, 5, 5}, {11, 12, 13, 14, 15}};
    double *emat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        emat[i] = et[i];
    double t[ROWS][COLS] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    double *mat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat[i] = t[i];
    sub_matrix_rows(mat, 0, 1, COLS, 1);
    int cmp_rc = cmp_matrix(mat, emat, ROWS, COLS);
    ck_assert_int_eq(MAT_EQ, cmp_rc);
    
    #undef ROWS
    #undef COLS
}

/**
 * @brief Тест на sub_matrix_rows с вещественным коэффициентом.
 * 
 */
START_TEST(sub_matrix_rows_test2)
{
    #define ROWS 3
    #define COLS 5

    double et[ROWS][COLS] = {{-2, -1.5, -1, -0.5, 0}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    double *emat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        emat[i] = et[i];
    double t[ROWS][COLS] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    double *mat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat[i] = t[i];
    sub_matrix_rows(mat, 1, 0, COLS, 0.5);
    int cmp_rc = cmp_matrix(mat, emat, ROWS, COLS);
    ck_assert_int_eq(MAT_EQ, cmp_rc);
    
    #undef ROWS
    #undef COLS
}

/**
 * @brief Тест на sub_matrix_rows с коэффициентом 0
 * 
 */
START_TEST(sub_matrix_rows_test0)
{
    #define ROWS 3
    #define COLS 5

    double et[ROWS][COLS] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    double *emat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        emat[i] = et[i];
    double t[ROWS][COLS] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    double *mat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat[i] = t[i];
    sub_matrix_rows(mat, 1, 0, COLS, 0);
    int cmp_rc = cmp_matrix(mat, emat, ROWS, COLS);
    ck_assert_int_eq(MAT_EQ, cmp_rc);
    
    #undef ROWS
    #undef COLS
}

 /**
  * @brief Сьют на sub_matrix_rows
  * 
  * @return Suite* 
  */
Suite *sub_matrix_rows_suite(void) {
  Suite *s;
  TCase *tc_sub;

  s = suite_create("Sub rows");

  tc_sub = tcase_create("Sub rows tests");
  tcase_add_test(tc_sub, sub_matrix_rows_test0);
  tcase_add_test(tc_sub, sub_matrix_rows_test1);
  tcase_add_test(tc_sub, sub_matrix_rows_test2);
  suite_add_tcase(s, tc_sub);
  return s;
}

/**
 * @brief Тест на add_matrix с матрицами 1 на 1
 * 
 */
START_TEST(add_mat_test1)
{
    #define ROWS 1
    #define COLS 1

    double et[ROWS][COLS] = {{3}};
    double *emat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        emat[i] = et[i];
    double t1[ROWS][COLS] = {{2}};
    double *mat1[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat1[i] = t1[i];
    
    double t2[ROWS][COLS] = {{1}};
    double *mat2[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat2[i] = t2[i];

    double **res = NULL;
    while (res == NULL)
        res = add_matrix(mat1, mat2, ROWS, COLS);
    int cmp_res;
    if (res != NULL)
        cmp_res = cmp_matrix(res, emat, ROWS, COLS);
    free_matrix(res, ROWS);
    ck_assert_ptr_ne(res, NULL);
    ck_assert_int_eq(cmp_res, MAT_EQ);
    
    #undef ROWS
    #undef COLS
}

/**
 * @brief Тест на add_matrix с матрицами 6 на 6
 * 
 */
START_TEST(add_mat_test6)
{
    #define ROWS 6
    #define COLS 6

    double et[ROWS][COLS] = {{2, 4, 6, 8, 10, 12}, {2, 4, 6, 8, 10, 12}, {2, 4, 6, 8, 10, 12}, {2, 4, 6, 8, 10, 12}, {0, 0, 0, 0, 0, 0}, {2, 4.5, 4, 9.3, 6.4, 10.3}};
    double *emat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        emat[i] = et[i];
    double t1[ROWS][COLS] = {{1, 2, 3, 4, 5, 6}, {1, 2, 3, 4, 5, 6}, {1, 2, 3, 4, 5, 6}, {1, 2, 3, 4, 5, 6}, {-1, 2, -3, 4, -5, 6}, {1, 0.5, 2, 3, 4, 5.3}};
    double *mat1[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat1[i] = t1[i];
    
    double t2[ROWS][COLS] = {{1, 2, 3, 4, 5, 6}, {1, 2, 3, 4, 5, 6}, {1, 2, 3, 4, 5, 6}, {1, 2, 3, 4, 5, 6}, {1, -2, 3, -4, 5, -6}, {1, 4, 2, 6.3, 2.4, 5}};
    double *mat2[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat2[i] = t2[i];

    double **res = NULL;
    while (res == NULL)
        res = add_matrix(mat1, mat2, ROWS, COLS);
    if (res != NULL)
    {
        int cmp_rc = cmp_matrix(res, emat, ROWS, COLS);
        free_matrix(res, ROWS);
        ck_assert_int_eq(MAT_EQ, cmp_rc);
    }
    ck_assert_ptr_ne(res, NULL);

    #undef ROWS
    #undef COLS
}

/**
 * @brief Тест на add_matrix с матрицами 2 на 2
 * 
 */
START_TEST(add_mat_test2)
{
    #define ROWS 2
    #define COLS 2

    double et[ROWS][COLS] = {{2, 4}, {6, 8}};
    double *emat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        emat[i] = et[i];
    double t1[ROWS][COLS] = {{1, 2}, {3, 4}};
    double *mat1[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat1[i] = t1[i];
    
    double t2[ROWS][COLS] = {{1, 2}, {3, 4}};
    double *mat2[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat2[i] = t2[i];

    double **res = NULL;
    while (res == NULL)
        res = add_matrix(mat1, mat2, ROWS, COLS);
    if (res != NULL)
    {
        int cmp_rc = cmp_matrix(res, emat, ROWS, COLS);
        free_matrix(res, ROWS);
        ck_assert_int_eq(MAT_EQ, cmp_rc);
    }
    ck_assert_ptr_ne(res, NULL);
    
    #undef ROWS
    #undef COLS
}

/**
 * @brief Тест на add_matrix с матрицами 5 на 5
 * 
 */
START_TEST(add_mat_test5)
{
    #define ROWS 5
    #define COLS 5

    double et[ROWS][COLS] = {{3, 3, 3, 3, 3}, {3, 3, 3, 3, 3}, {3, 3, 3, 3, 3}, {3, 3, 3, 3, 3}, {3, 3, 3, 3, 3}};
    double *emat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        emat[i] = et[i];
    double t1[ROWS][COLS] = {{1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}};
    double *mat1[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat1[i] = t1[i];
    
    double t2[ROWS][COLS] = {{2, 1, 2, 1, 2}, {2, 1, 2, 1, 2}, {2, 1, 2, 1, 2}, {2, 1, 2, 1, 2}, {2, 1, 2, 1, 2}};
    double *mat2[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat2[i] = t2[i];

    double **res = NULL;
    while (res == NULL)
        res = add_matrix(mat1, mat2, ROWS, COLS);
    if (res != NULL)
    {
        int cmp_rc = cmp_matrix(res, emat, ROWS, COLS);
        free_matrix(res, ROWS);
        ck_assert_int_eq(MAT_EQ, cmp_rc);
    }
    ck_assert_ptr_ne(res, NULL);
    
    #undef ROWS
    #undef COLS
}

/**
 * @brief Тест на add_matrix с матрицами 2 на 3
 * 
 */
START_TEST(add_mat_test23)
{
    #define ROWS 2
    #define COLS 3

    double et[ROWS][COLS] = {{2, 5, 4}, {2, 2, 2}};
    double *emat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        emat[i] = et[i];
    double t1[ROWS][COLS] = {{2, 1, 3}, {2, 4, 4}};
    double *mat1[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat1[i] = t1[i];
    
    double t2[ROWS][COLS] = {{0, 4, 1}, {0, -2, -2}};
    double *mat2[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat2[i] = t2[i];

    double **res = NULL;
    while (res == NULL)
        res = add_matrix(mat1, mat2, ROWS, COLS);
    if (res != NULL)
    {
        int cmp_rc = cmp_matrix(res, emat, ROWS, COLS);
        free_matrix(res, ROWS);
        ck_assert_int_eq(MAT_EQ, cmp_rc);
    }
    ck_assert_ptr_ne(res, NULL);
    
    #undef ROWS
    #undef COLS
}

/**
 * @brief Тест на add_matrix с матрицами 7 на 5
 * 
 */
START_TEST(add_mat_test75)
{
    #define ROWS 7
    #define COLS 5

    double et[ROWS][COLS] = {{3, 3, 3, 3, 3}, {3, 3, 3, 3, 3}, {3, 3, 3, 3, 3}, {3, 3, 3, 3, 3}, {3, 3, 3, 3, 3}, {3, 3, 3, 3, 3}, {3, 3, 3, 3, 3}};
    double *emat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        emat[i] = et[i];
    double t1[ROWS][COLS] = {{6, 6, 6, 6, 6}, {6, 6, 6, 6, 6}, {6, 6, 6, 6, 6}, {6, 6, 6, 6, 6}, {6, 6, 6, 6, 6}, {6, 6, 6, 6, 6}, {6, 6, 6, 6, 6}};
    double *mat1[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat1[i] = t1[i];
    
    double t2[ROWS][COLS] = {{-3, -3, -3, -3, -3}, {-3, -3, -3, -3, -3}, {-3, -3, -3, -3, -3}, {-3, -3, -3, -3, -3}, {-3, -3, -3, -3, -3}, {-3, -3, -3, -3, -3}, {-3, -3, -3, -3, -3}};
    double *mat2[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat2[i] = t2[i];

    double **res = NULL;
    while (res == NULL)
        res = add_matrix(mat1, mat2, ROWS, COLS);
    if (res != NULL)
    {
        int cmp_rc = cmp_matrix(res, emat, ROWS, COLS);
        free_matrix(res, ROWS);
        ck_assert_int_eq(MAT_EQ, cmp_rc);
    }
    ck_assert_ptr_ne(res, NULL);
    
    #undef ROWS
    #undef COLS
}


/**
 * @brief Сьют на add_matrix
 * 
 * @return Suite* 
 */
Suite *add_suite(void) {
  Suite *s;
  TCase *tc_add;

  s = suite_create("Add matrix");

  tc_add = tcase_create("Add matrix tests");
  tcase_add_test(tc_add, add_mat_test1);
  tcase_add_test(tc_add, add_mat_test2);
  tcase_add_test(tc_add, add_mat_test5);
  tcase_add_test(tc_add, add_mat_test6);
  tcase_add_test(tc_add, add_mat_test23);
  tcase_add_test(tc_add, add_mat_test75);
  suite_add_tcase(s, tc_add);
  return s;
}

/**
 * @brief Тест на mult_matrix с матрицами 1 на 1
 * 
 */
START_TEST(mult_mat_test1)
{
    #define ROWS 1
    #define COLS 1

    double et[ROWS][COLS] = {{12}};
    double *emat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        emat[i] = et[i];
    double t1[ROWS][COLS] = {{3}};
    double *mat1[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat1[i] = t1[i];
    
    double t2[ROWS][COLS] = {{4}};
    double *mat2[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat2[i] = t2[i];

    double **res = NULL;
    size_t rres,cres;
    while (res == NULL)
        res = mult_matrix(mat1, ROWS, COLS, mat2, ROWS, COLS, &rres, &cres);
    if (res != NULL)
    {
        int cmp_rc = cmp_matrix(res, emat, ROWS, COLS);
        free_matrix(res, ROWS);
        ck_assert_int_eq(MAT_EQ, cmp_rc);
    }
    ck_assert_ptr_ne(res, NULL);

    #undef ROWS
    #undef COLS
}

/**
 * @brief Тест на mult_matrix с матрицами 4 на 4
 * 
 */
START_TEST(mult_mat_test4)
{
    #define ROWS 4
    #define COLS 4

    double et[ROWS][COLS] = {{90, 100, 110, 120}, {202, 228, 254, 280}, {314, 356, 398, 440}, {426, 484, 542, 600}};
    double *emat[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        emat[i] = et[i];
    double t1[ROWS][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    double *mat1[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat1[i] = t1[i];
    
    double t2[ROWS][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    double *mat2[ROWS];
    for (size_t i = 0; i < ROWS; i++)
        mat2[i] = t2[i];

    double **res = NULL;
    size_t rres,cres;
    while (res == NULL)
        res = mult_matrix(mat1, ROWS, COLS, mat2, ROWS, COLS, &rres, &cres);
    if (res != NULL)
    {
        int cmp_rc = cmp_matrix(res, emat, ROWS, COLS);
        free_matrix(res, ROWS);
        ck_assert_int_eq(MAT_EQ, cmp_rc);
    }
    ck_assert_ptr_ne(res, NULL);
    #undef ROWS
    #undef COLS
}
/**
 * @brief Тест на mult_matrix с матрицами 4 на 3 и 3 на 6
 * 
 */
START_TEST(mult_mat_test4336)
{

    #define ROWS1 4
    #define COLS1 3
    #define ROWS2 3
    #define COLS2 6

    double et[ROWS1][COLS2] = {{54, 60, 66, 72, 78, 84}, {117, 132, 147, 162, 177, 192}, {180, 204, 228, 252, 276, 300}, {243, 276, 309, 342, 375, 408}};
    double *emat[ROWS1];
    for (size_t i = 0; i < ROWS1; i++)
        emat[i] = et[i];
    double t1[ROWS1][COLS1] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    double *mat1[ROWS1];
    for (size_t i = 0; i < ROWS1; i++)
        mat1[i] = t1[i];
    
    double t2[ROWS2][COLS2] = {{1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}, {13, 14, 15, 16, 17, 18}};
    double *mat2[ROWS2];
    for (size_t i = 0; i < ROWS2; i++)
        mat2[i] = t2[i];

    double **res = NULL;
    size_t rres,cres;
    while (res == NULL)
        res = mult_matrix(mat1, ROWS1, COLS1, mat2, ROWS2, COLS2, &rres, &cres);
    if (res != NULL)
    {
        int cmp_rc = cmp_matrix(res, emat, ROWS1, COLS2);
        free_matrix(res, ROWS1);
        ck_assert_int_eq(MAT_EQ, cmp_rc);
    }
    ck_assert_ptr_ne(res, NULL);
    #undef ROWS1
    #undef COLS1
    #undef ROWS2
    #undef COLS2
}

/**
 * @brief Негативный тест на mult_matrix с матрицами 4 на 5 и 3 на 6
 * 
 */
START_TEST(mult_mat_test4536)
{
    #define ROWS1 4
    #define COLS1 5
    #define ROWS2 3
    #define COLS2 6

    double t1[ROWS1][COLS1];
    double *mat1[ROWS1];
    for (size_t i = 0; i < ROWS1; i++)
        mat1[i] = t1[i];
    
    double t2[ROWS2][COLS2];
    double *mat2[ROWS2];
    for (size_t i = 0; i < ROWS2; i++)
        mat2[i] = t2[i];

    double **res = NULL;
    size_t rres,cres;
    res = mult_matrix(mat1, ROWS1, COLS1, mat2, ROWS2, COLS2, &rres, &cres);
    double **tmp = res;
    free_matrix(res, ROWS1);
    ck_assert_ptr_eq(tmp, NULL);
    #undef ROWS1
    #undef COLS1
    #undef ROWS2
    #undef COLS2
}

/**
 * @brief Сьют на mult_matrix
 * 
 * @return Suite* 
 */
Suite *mult_matrix_suite(void) {
  Suite *s;
  TCase *tc_mult;

  s = suite_create("Multiply matrix");

  tc_mult = tcase_create("Multiply matrix tests");
  tcase_add_test(tc_mult, mult_mat_test1);
  tcase_add_test(tc_mult, mult_mat_test4);
  tcase_add_test(tc_mult, mult_mat_test4336);
  tcase_add_test(tc_mult, mult_mat_test4536);
  suite_add_tcase(s, tc_mult);
  return s;
}

/**
 * @brief Тест на inv_matrix с матрицей с нулевым определителем
 * 
 */
START_TEST(inv_mat_test_null_det1)
{
    #define SIZE 2

    double t[SIZE][SIZE] = {{1, 2}, {2, 4}};
    double *mat[SIZE];
    for (size_t i = 0; i < SIZE; i++)
        mat[i] = t[i];
    double **res = NULL;
    int rc = inv_matrix(mat, &res, SIZE);
    free_matrix(res, SIZE);
    ck_assert_int_eq(rc, ERR_NO_INV_MATRIX);
    
    #undef SIZE
}

/**
 * @brief Тест на inv_matrix с матрицей с нулевым определителем
 * 
 */
START_TEST(inv_mat_test_null_det2)
{
    #define SIZE 3

    double t[SIZE][SIZE] = {{0, 23, 2}, {0, 2, 4}, {0, 4, 123}};
    double *mat[SIZE];
    for (size_t i = 0; i < SIZE; i++)
        mat[i] = t[i];
    double **res = NULL;
    int rc = inv_matrix(mat, &res, SIZE);
    free_matrix(res, SIZE);
    ck_assert_int_eq(rc, ERR_NO_INV_MATRIX);
    
    #undef SIZE
}

/**
 * @brief Тест на inv_matrix с матрицей 2 на 2
 * 
 */
START_TEST(inv_mat_test2)
{
    #define SIZE 2

    double et[SIZE][SIZE] = {{((double) 1) / 12, -0.125}, {0, 0.5}};
    double *emat[SIZE];
    for (size_t i = 0; i < SIZE; i++)
        emat[i] = et[i];
    double t[SIZE][SIZE] = {{12, 3}, {0, 2}};
    double *mat[SIZE];
    for (size_t i = 0; i < SIZE; i++)
        mat[i] = t[i];
    double **res = NULL;
    int rc = inv_matrix(mat, &res, SIZE);
    if (!rc)
    {
        int cmp_rc = cmp_matrix(res, emat, SIZE, SIZE);
        free_matrix(res, SIZE);
        ck_assert_int_eq(MAT_EQ, cmp_rc);
    }
    ck_assert_int_eq(rc, ERR_OK);
    
    #undef SIZE
}

/**
 * @brief Тест на inv_matrix с матрицей 3 на 3
 * 
 */
START_TEST(inv_mat_test3)
{
    #define SIZE 3

    double et[SIZE][SIZE] = {{((double) 1)/11, ((double) 1)/88, -((double) 1)/22}, {0, 0.25, 0}, {0, -((double) 5)/24, ((double) 1)/6}};
    double *emat[SIZE];
    for (size_t i = 0; i < SIZE; i++)
        emat[i] = et[i];
    double t[SIZE][SIZE] = {{11, 2, 3}, {0, 4, 0}, {0, 5, 6}};
    double *mat[SIZE];
    for (size_t i = 0; i < SIZE; i++)
        mat[i] = t[i];
    double **res = NULL;
    int rc = inv_matrix(mat, &res, SIZE);
    if (!rc)
    {
        int cmp_rc = cmp_matrix(res, emat, SIZE, SIZE);
        free_matrix(res, SIZE);
        ck_assert_int_eq(MAT_EQ, cmp_rc);
    }
    ck_assert_int_eq(rc, ERR_OK);
    
    #undef SIZE
}

/**
 * @brief Тест на inv_matrix с матрицей 1 на 1
 * 
 */
START_TEST(inv_mat_test1)
{
    #define SIZE 1

    double et[SIZE][SIZE] = {{0.125}};
    double *emat[SIZE];
    for (size_t i = 0; i < SIZE; i++)
        emat[i] = et[i];
    double t[SIZE][SIZE] = {{8}};
    double *mat[SIZE];
    for (size_t i = 0; i < SIZE; i++)
        mat[i] = t[i];
    double **res = NULL;
    int rc = inv_matrix(mat, &res, SIZE);
    if (!rc)
    {
        int cmp_rc = cmp_matrix(res, emat, SIZE, SIZE);
        free_matrix(res, SIZE);
        ck_assert_int_eq(MAT_EQ, cmp_rc);
    }
    ck_assert_int_eq(rc, ERR_OK);
    
    #undef SIZE
}

/**
 * @brief Тест на inv_matrix с умножением
 * 
 */
START_TEST(inv_mat_test_mult)
{
    #define SIZE 3

    double ed_matrix[SIZE][SIZE] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double *emat[SIZE];
    for (size_t i = 0; i < SIZE; i++)
        emat[i] = ed_matrix[i];
    double t[SIZE][SIZE] = {{5, 2, 13}, {41, 20, 21}, {32, 23, 12}};    
    double *mat[SIZE];
    for (size_t i = 0; i < SIZE; i++)
        mat[i] = t[i];
    double **inv = NULL;
    int rc = inv_matrix(mat, &inv, SIZE);
    ck_assert_int_eq(rc, ERR_OK);
    size_t s1, s2;
    double **res = mult_matrix(mat, SIZE, SIZE, inv, SIZE, SIZE, &s1, &s2);
    if (res != NULL)
    {
        int cmp_rc = cmp_matrix(res, emat, SIZE, SIZE);
        free_matrix(res, SIZE);
        free_matrix(inv, SIZE);
        ck_assert_int_eq(MAT_EQ, cmp_rc);
    }
    else     
        free_matrix(inv, SIZE);
    ck_assert_ptr_ne(res, NULL);
    #undef SIZE
}

/**
 * @brief Сьют на inv_matrix
 * 
 * @return Suite* 
 */
Suite *inv_matrix_suite(void) {
  Suite *s;
  TCase *tc_inv;

  s = suite_create("Inverse matrix");

  tc_inv = tcase_create("Inverse matrix tests");
  tcase_add_test(tc_inv, inv_mat_test_null_det1);
  tcase_add_test(tc_inv, inv_mat_test_null_det2);
  tcase_add_test(tc_inv, inv_mat_test1);
  tcase_add_test(tc_inv, inv_mat_test2);
  tcase_add_test(tc_inv, inv_mat_test3);
  tcase_add_test(tc_inv, inv_mat_test_mult);
  suite_add_tcase(s, tc_inv);
  return s;
}
