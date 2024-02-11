#ifndef FILM_ARR_H__
#define FILM_ARR_H__

#include <stdio.h>
#include <stddef.h>
#include "film.h"
#include "errs.h"



#define N_MAX 15
/**
 * @brief Функция для создания критерия сравнения фильмов из строки(которая подается как аргумент командной строки)
 * 
 * @param [in] field_str - Строка с аргументом
 * @param [out] ft - Критерий сравнения
 * @return int - Код возврата
 */
int gen_field_t(const char *field_str, field_t *ft);

/**
 * @brief Функция для чтения и упорядочивания массива фильмов из файла.
 *  Фильмы упорядывачиваются по возрастанию
 * @param [in] f - Файл 
 * @param [out] farr - Массив фильмов
 * @param [out] asize - Указатель на размер массива
 * @param [in] max_s - Максимальный размер массива
 * @param [in] ft - Критерий упорядочивания
 * @return int Код возврата
 */
int film_arr_read(FILE *f, struct film_t *farr, size_t *asize, size_t max_s, int (*cmp)(const struct film_t *, const struct film_t *));

/**
 * @brief Функция для вывода массива фильмов в файл.
 * 
 * @param [out] f - Файл
 * @param [in] farr - Массив фильмов
 * @param [in] asize - Размер массива
 * @return int Код возврата
 */
int film_arr_print(FILE *f, const struct film_t *farr, size_t asize);

/**
 * @brief Функция для поиска и вывода фильма с определенным параметром в файл.
 * 
 * @param [out] f - Файл
 * @param [in] farr - Массив фильмов
 * @param [in] asize - Размер массива
 * @param [in] ft - Тип параметра
 * @param [in] key - Значение параметра
 * @return int Код возврата
 */
int film_arr_find_by_field_print(FILE *f, const struct film_t *farr, size_t asize, const struct film_t *film, int (*cmp)(const struct film_t *, const struct film_t *));


#endif
