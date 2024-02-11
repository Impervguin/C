#ifndef MAT_H__
#define MAT_H__

#include <stddef.h>
#include <stdio.h>

#define EPS 1e-8
/**
 * @brief Функция которая создает матрицу, которая хранится как массив указателей на строки, при этом все строки расположены одним блоком памяти
 * 
 * @param [in] rows - Количество строк в матрице
 * @param [in] cols - Количество столбцов в матрице
 * @return double** - NULL - Если не удалось создать матрицу, иначе указатель  на массив указатеей на строки
 */
double **create_matrix(size_t rows, size_t cols);


/**
 * @brief Функция которая создает матрицу, которая хранится как массив указателей на строки, при этом все строки расположены одним блоком памяти
 * При создании инициализирует матрицу нулями.
 * @param [in] rows - Количество строк в матрице
 * @param [in] cols - Количество столбцов в матрице
 * @return double** - NULL - Если не удалось создать матрицу, иначе указатель  на массив указатеей на строки
 */
double **create_null_matrix(size_t rows, size_t cols);
/**
 * @brief Функция для освобождения памяти из под матрицы.
 * Если подать NULL, то ничего не пройзодет.
 * @param [in] matrix - Матрица в виде массива указателей на строки.
 * @param [in] rows - Количество строк в матрице.
 */
void free_matrix(double **matrix, size_t rows);

/**
 * @brief Функция для чтения матрицы из файла. При успешном чтении размеров динамически создает матрицу и затем читает ее элементы.
 * 
 * @param [in/out] f - Файл.
 * @param [out] matrix - Тройной указатель, по значению которого поместят матрицу.
 * @param [out] rows - Указатель на количество строк матрицы.
 * @param [out] cols - Указатель на количество столбцов матрицы.
 * @return int - Код возврата.
 */
int read_matrix_file(FILE *f, double ***matrix, size_t *rows, size_t *cols);

/**
 * @brief Функция для записи матрицы в файл.
 * 
 * @param [in/out] f - Файл.
 * @param [in] matrix - Матрица.
 * @param [in] rows - Количество строк в матрице.
 * @param [in] cols - Количество столбцов в матрице.
 * @return int - Код возврата
 */
int write_matrix_file(FILE *f, double **matrix, size_t rows, size_t cols);

#endif
