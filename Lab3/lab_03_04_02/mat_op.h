#ifndef C_LABS_MAT_OP_H
#define C_LABS_MAT_OP_H
#include "sizes.h"
#include "errors.h"
#include <stddef.h>
#include <stdbool.h>

int find_max_under_secondary_diag(int (*mat)[MAX_SIZE], size_t size, int *num);

#endif //C_LABS_MAT_OP_H
