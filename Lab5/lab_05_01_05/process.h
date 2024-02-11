#ifndef C_LABS_PROCESS_H
#define C_LABS_PROCESS_H

#include <stdio.h>
#include "errors.h"
/**
 * Функция, которая находит наибольшее количество подряд идущих одинаковых элементов в файле
 * @param [in] f - Файл
 * @param [out] res - Указатель на количество подряд подряд идущих одинаковых элементов
 * @return Код возврата
 */
int process(FILE *f, size_t *res);

#endif //C_LABS_PROCESS_H
