#include "numbers.h"



bool check_digit_in_num(int num, int digit)
{
    if (num == 0 && digit == 0)
        return true;

    if (num < 0)
        num = -num;

    while (num > 0)
    {
        if (num % 10 == digit)
            return true;
        num /= 10;
    }
    return false;
}
