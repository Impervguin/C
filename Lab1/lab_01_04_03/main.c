#include <stdio.h>

#define OK 0

int main(void)
{
    int a, m;
    printf("Enter three-digit number: ");
    scanf("%d", &a);
    if (a < 0)
    {
        a = -a;
    }
    m = (a % 10) * (a / 10 % 10) * (a / 100 % 10);
    printf("Mult of num's digits: %d\n", m);
    return OK;
}
