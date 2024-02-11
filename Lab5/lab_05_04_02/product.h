#ifndef C_LABS_PRODUCT_H
#define C_LABS_PRODUCT_H
#include <stdint.h>
#include <stdio.h>
#include "errors.h"
#include "io.h"

#define MAXNUM 100
#define NAME_LEN (30 + 1)
#define MANUFACTURER_LEN (15 + 1)

struct product_t
{
    char name[NAME_LEN];
    char manufacturer[MANUFACTURER_LEN];
    uint32_t price;
    uint32_t count;
};

/**
 * Функция, которая добавляет product_t в конец бинарного файла
 * @param f - файл
 * @param product - Указатель на структуру
 * @return Код возврата
 */
int fb_add_struct(FILE *f, struct product_t *product);

/**
 * Функция, которая получает структуру из бинарного файла по индексу
 * @param f - Файл
 * @param product - Указатель на структуру
 * @param index - Индекс
 * @return Код возврата
 */
int fb_get_struct_by_pos(FILE *f, struct product_t *product, long index);

/**
 * Подсчитывает количество структур в бинарном файле
 * @param f - Файл
 * @param count - Указатель на количество
 * @return Код возврата
 */
int fb_struct_count(FILE *f, long *count);

/**
 * Функция которая сравнивает две структуры, сначала по цене, затем по количеству
 * @param prod1 - Первая структура
 * @param prod2 - Вторая структура
 * @return 1 - Если 1 > 2, 0 если равны иначе -1
 */
int struct_cmp(struct product_t *prod1, struct product_t *prod2);


/**
 * Функция которая построчно выводит поля структуры
 * @param product - Указатель о структуре
 */
void print_product(struct product_t *product);

/**
 * Функция, которая читает из текстового файла структуру
 * @param f - Файл
 * @param product - Указатель на структуру
 * @return Код возврата
 */
int read_product_text(FILE *f, struct product_t *product);

/**
 * Функция, которая считывает из текстового файла все структуры в массив
 * @param f - Файл
 * @param arr - Массив структур
 * @param arr_size - Указатель на размер массива
 * @return
 */
int read_products_text(FILE *f, struct product_t *arr, size_t *arr_size);

/**
 * Фукнция, которая сортирует бинарный файл со структурами
 * @param fin - Входной файл
 * @param fout - Выходной файл
 * @return Код возврата
 */
int fb_sort_product(FILE *fin, FILE *fout);

/**
 * Функция, которая в массиве структур ищет структуры поле имен которых оканчивается на заданную подстроку
 * @param substr - Подстрока
 * @param arr - Массив структур
 * @param arr_size - Размер массива
 * @param n_arr - Массив искомых структур
 * @param n_arr_size - Указатель на размер массива искомых структур
 * @return  Код возврата
 */
int find_end_substr_product(const char *substr, const struct product_t *arr, size_t arr_size, struct product_t *n_arr, size_t *n_arr_size);
#endif //C_LABS_PRODUCT_H
