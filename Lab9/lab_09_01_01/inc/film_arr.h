#ifndef FILM_ARR_H__
#define FILM_ARR_H__

#include <stdio.h>
#include <stddef.h>
#include "film.h"
#include "errs.h"

/**
 * @brief Функция для вставки фильма в массив фильмов
 * 
 * @param [out] farr - Массив фильмов
 * @param [in/out] asize - Указатель на размер массива
 * @param [in] film - Фильм
 * @param [in] ind - Индекс для вставки
 */
void film_insert(struct film_t *farr, size_t *asize, const struct film_t *film, size_t ind);

/**
 * @brief Динамически создает массив размером asize.
 * 
 * @param [in] asize - Размер массива.
 * @return struct film_t* - Указатель на массив, если память выделилась удачно, иначе NULL.
 */
struct film_t *create_film_arr(size_t asize);

/**
 * @brief Освобождает память из под массива фильмов, при этом освобождая память из под строк в каждом фильме.
 * 
 * @param [in] arr - Массив фильмов.
 * @param [in] size - Размер массива.
 */
void free_film_arr(struct film_t *arr, size_t size);

/**
 * @brief Функция для создания критерия сравнения фильмов из строки(которая подается как аргумент командной строки)
 * 
 * @param [in] field_str - Строка с аргументом
 * @param [out] ft - Критерий сравнения
 * @return int - Код возврата
 */
int gen_field_t(const char *field_str, field_t *ft);

/**
 * @brief Функция для динамического чтения и упорядочивания массива фильмов из файла.
 *  Фильмы упорядывачиваются по возрастанию.
 * @param [in] f - Файл 
 * @param [out] farr - Массив фильмов
 * @param [out] asize - Указатель на размер массива
 * @param [in] ft - Критерий упорядочивания
 * @return int Код возврата
 */
int film_arr_read(FILE *f, struct film_t **farr, size_t *asize, int (*cmp)(const struct film_t *, const struct film_t *));

/**
 * @brief Функция для поиска места фильма в упорядоченном массиве
 * 
 * @param [in] farr - Массив фильмов
 * @param [in] asize - Размер массива
 * @param [in] film - Фильм
 * @param [out] ind - Указатель на индекс
 * @param [in] ft - Критерий упорядочивания
 * @return int Код возврата
 */
int film_find_place_by_field(const struct film_t *farr, size_t asize, const struct film_t *film, size_t *ind, int (*cmp)(const struct film_t *, const struct film_t *));

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
