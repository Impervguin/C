#ifndef C_LABS_PROCESS_BIN_FILES_H
#define C_LABS_PROCESS_BIN_FILES_H
#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "io.h"
#include "consts.h"

/**
 * Функция, которая создает бинарный файл заполненный случайными числами
 * @param [in] fname - Название файла
 * @param [in] count - Количество чисел
 * @return Код возврата
 */
int create_bfile_with_rand_nums(const char *fname, size_t count);

/**
 * Функция, которая читает числа и бинарного файла в массив
 * @param [in] fname - Название файла
 * @param [in] arr - Массив
 * @param [out] size - Указатель на размер массива
 * @return Код возврата
 */
int read_bfile_nums(const char *fname, int *arr, size_t *size);
/**
 * Функция, которая получает число из бинарного файла по индексу
 * @param [in] f - Файл
 * @param [in] index - индекс
 * @param [out] res - Указатель на полученное число
 * @return Код возврата
 */
int get_number_by_pos(FILE *f, size_t index, int *res);
/**
 * Функция, которая кладет число в бинарный файл по индексу
 * @param [in] f - Файл
 * @param [in] index - Индекс
 * @param [in] num - Число
 * @return Код возврата
 */
int put_number_by_pos(FILE *f, size_t index, int num);
/**
 * Функция, которая сортирует бинарный файл с числами
 * @param [in] fname - Название файла
 * @return Код возврата
 */
int sort_bfile_nums(const char *fname);

/**
 * Функция, которая находит количество чисел в файле
 * @param [in, out] f - Файл
 * @param [out] count - Указатель на количество
 * @return Код возврата
 */
int get_bfile_nums_count(FILE *f, size_t *count);


#endif
