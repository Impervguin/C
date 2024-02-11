#ifndef C_LABS_IO_H
#define C_LABS_IO_H
#include <stdio.h>
#include "errors.h"
/**
 * Функция, которая открывает файл в режиме чтения
 * @param [in] fname - Название файла
 * @param [out] f - Указатель на файл
 * @return  Код возврата
 */
int open_bin_read_file(const char *fname, FILE **f);
/**
 * Функция, которая открывает файл в режиме записи
 * @param [in] fname - Название файла
 * @param [out] f - Указатель на файл
 * @return  Код возврата
 */
int open_bin_write_file(const char *fname, FILE **f);
/**
 * Функция, которая открывает файл в режиме чтения и дозаписи
 * @param [in] fname - Название файла
 * @param [out] f - Указатель на файл
 * @return  Код возврата
 */
int open_bin_read_append_file(const char *fname, FILE **f);
/**
 * Функция, которая выводит массив
 * @param [in] arr - Массив
 * @param [in] size - Размер массива
 */
void output_array(const int *arr, size_t size);

#endif //C_LABS_IO_H
