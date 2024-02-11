#ifndef FIBONACCI_H__
#define FIBONACCI_H__

#define OK 0
#define ERR_ARGS_FIB 1

/// @brief Функция для заполнения массива первыми числами фибонначи
/// @param [out] arr - Массив, выделенная память должна быть не меньше count чисел.
/// @param [in] count - Количество необходимых символов.
/// @return - OK - успех, ERR_ARGS - Некорректные аргументы.
int fill_fibonacci_arr(int *arr, size_t count);

#endif // FIBONACCI_H__
