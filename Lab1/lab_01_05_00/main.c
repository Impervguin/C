#include <stdio.h>

#define OK 0
#define IOERROR 1

long long fast_pow(long long num, unsigned degree)
{
    long long p = 1;
    while (degree != 1)
    {
        if (degree % 2 != 0)
        {
            p *= num;
            degree -= 1;
        }
        else
        {
            num *= num;
            degree /= 2;
        }
    }
    return p * num;
}

int main(void) 
{
    int rc;
    long long a;
    unsigned deg;
    printf("Enter number and degree: ");
    rc = scanf("%lld%u", &a, &deg);
    //printf("%lld %d %c", a, rc, tmpc);
    if (rc != 2)
    {
        printf("Wrong input.\n");
        return IOERROR;
    }
    printf("%lld", fast_pow(a, deg));
    return OK;
}
