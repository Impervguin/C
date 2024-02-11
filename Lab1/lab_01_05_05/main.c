#include <stdio.h>

#define OK 0
#define IOERROR 1
#define NEGERROR 2

/**
 * Функция для получения 10 в степени, необходимой для получение цифры в старшем разряде числа num методом целочисленного деления
 */
long long get_num_pos(long long num)
{
    int n = 1;
    num /= 10;
    while (num > 0) 
    {
        n *= 10;
        num /= 10;
    }
    return n;
}

/**
 * Функция для вывода числа по одной цифре за вызов printf
 */
int print_num_by_one(long long num) 
{
    int del = get_num_pos(num);
    while (del > 0) 
    {
        printf("%lld", num / del);
        num %= del;
        del /= 10;
    }
    printf("\n");
    return OK; 
}

int main(void) 
{
    int rc;
    long long a;
    printf("Enter number: ");
    rc = scanf("%lld", &a);
    //printf("%lld %d %c", a, rc, tmpc);
    if (rc != 1)
    {
        printf("Wrong input.\n");
        return IOERROR;
    }
    
    if (a <= 0) 
    {
        printf("Can't be negative.\n");
        return NEGERROR;
    }
    
    print_num_by_one(a);
    return OK;
}
