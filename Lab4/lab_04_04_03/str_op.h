#ifndef C_LABS_STR_OP_H
#define C_LABS_STR_OP_H
#include "stddef.h"
#include "string.h"
#include "sizes.h"
#include "errors.h"
#include "stdbool.h"

/**
 * Функция, для проверки, если строка является корректным номером телефона.
 * Перед и после номера может содержаться любое количество пробелов
 * @param[in] str - Строка с номером
 * @return OK - Если корректный, иначе NOT_CORRECT_NUMBER
 */
int is_number(const char *str);
#endif //C_LABS_STR_OP_H
