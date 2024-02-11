#ifndef FILM_H__
#define FILM_H__

#include <stdio.h>
// #include "film_arr.h"
#include "errs.h"

#define TITLE_SIZE 25
#define DIRNAME_SIZE 25

/// @brief Структура фильма
struct film_t
{
    char title[TITLE_SIZE + 1];
    char name[DIRNAME_SIZE + 1];
    int year;
};

/**
 * @brief Создан для передачи в функцию, как определитель того, по какому элементу сортировать, искать и т.д.
 * Созда для того, что бы не приходилось передавать строку в функцию и каждый раз там ее сравнивать
 * 
 */
typedef enum  
{
    TITLE,
    NAME,
    YEAR
} field_t;

/**
 * @brief Функция для считывания фильма из файла.
 * 
 * @param [in] f - Файл
 * @param [out] pf - Указатель на фильм
 * @return int Код возврата
 */
int film_read(FILE *f, struct film_t *pf, int *sr);

/**
 * @brief Функция для вывода информации о фильме в файл
 * 
 * @param [out] f - Файл
 * @param [in] pf - Указатель на фильм
 * @return int Код возврата
 */
int film_print(FILE *f, const struct film_t *pf);

/**
 * @brief Функция для сравнения двух фильмов по названию
 * 1 - Первый фильм раньше по лекскикографическому порядку
 * 0 - Одинаковые названия
 * -1 - Второй фильм раньше по лекскикографическому порядку
 * @param [in] pf1 - Указатель на первый фильм
 * @param [in] pf2 - Указатель на второй фильм
 * @return int Результат сранения
 */
int film_cmp_by_name(const struct film_t *pf1, const struct film_t *pf2);

/**
 * @brief Функция для сравнения двух фильмов по имени режиссёра
 * 1 - Режиссер первого фильма раньше по лекскикографическому порядку
 * 0 - Одинаковые имена
 * -1 - Режиссер второго фильма раньше по лекскикографическому порядку
 * @param [in] pf1 - Указатель на первый фильм
 * @param [in] pf2 - Указатель на второй фильм
 * @return int Результат сранения
 */
int film_cmp_by_title(const struct film_t *pf1, const struct film_t *pf2);
/**
 * @brief Функция для сравнения двух фильмов по году выпуска
 * 1 - Первый фильм позже
 * 0 - Одинаковые названия
 * -1 - Второй фильм позже
 * @param [in] pf1 - Указатель на первый фильм
 * @param [in] pf2 - Указатель на второй фильм
 * @return int Результат сранения
 */
int film_cmp_by_year(const struct film_t *pf1, const struct film_t *pf2);

// /**
//  * @brief Функция для сравнения двух фильмов. Критерий сранения передается в field
//  * @param [in] pf1 - Указатель на первый фильм
//  * @param [in] pf2 - Указатель на второй фильм
//  * @param [in] field - Критерий сравнения
//  * @return int Результат сранения
//  */
// int film_cmp(const struct film_t *pf1, const struct film_t *pf2);

/// @brief Функция для копирования информации об одном фильме в другой
/// @param [out] pf_dest - Указатель на фильм - назначение 
/// @param [in] pf_src - Указатель на фильм - источник
void film_cpy(struct film_t *pf_dest, const struct film_t *pf_src);

#endif
