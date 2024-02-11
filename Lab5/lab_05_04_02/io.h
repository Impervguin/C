#ifndef C_LABS_IO_H
#define C_LABS_IO_H
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "errors.h"
#include "product.h"

/**
 * Функция, которая выводит все объекты product_t из бинарного файла
 * @param [in] f - Файл
 */
void fb_print_struct(FILE *f);

/**
 * Функция, которая читает строку из файла
 * @param [in] f - Файл
 * @param [out] str - Полученная строка
 * @param [in] read_len - Максимальная длина строки
 * @return Код Возврата
 */
int f_read_str(FILE *f, char *str, size_t read_len);

/**
 * Функция, которая читает 32-битное число из файла
 * @param [in] f - Файл
 * @param [out] num - Указатель на число
 * @return Код возврата
 */
int f_read_uint(FILE *f, uint32_t *num);


#endif //C_LABS_IO_H
