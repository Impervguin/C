#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <inttypes.h>

#define OK 0
#define IOERROR 1
#define NEGNUMERROR 2

/**
 * Фукнция для перемены местами битов находящихся на четных и нечетных местах
 */
uint32_t swap_bytes(uint32_t x) 
{
    size_t nbits = sizeof(x) * CHAR_BIT;
    uint32_t res = 0, even_mask = 2, neven_mask = 1;
    
    for (size_t i = 0; i < nbits / 2;i++)
    {
        res += ((x & even_mask) >> 1) + ((x & neven_mask) << 1);
        even_mask <<= 2;
        neven_mask <<= 2; 
    }
    return res;
}

/**
 * Функция для вывода беззнакового целого числа в двоичном виде
 */
void print_bin(uint32_t x)
{
    printf("Result:");
    // bool flag = false;
    // unsigned short last_bit;
    size_t nbits = sizeof(x) * CHAR_BIT;
    for (size_t i = 0; i < nbits; i++)
    {
        printf("%" SCNu32, x >> (nbits - 1));
        x <<= 1;
    }
    printf("\n");
}

int main(void)
{
    uint32_t x;
    int rc;
    printf("Enter number: ");
    rc = scanf("%" PRIu32, &x);
    if (rc != 1) 
    {
        printf("Error:Wrong input.\n");
        return IOERROR;
    }
    print_bin(swap_bytes(x));
    return OK;
}
