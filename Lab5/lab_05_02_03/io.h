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
int open_read_file(char *fname, FILE **f);

#endif //C_LABS_IO_H
