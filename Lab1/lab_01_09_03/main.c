#include <stdio.h>
#include <math.h>

#define OK 0
#define IOERROR 1
#define NOELEMENTSERROR 2
/**
 * Фукнция для добавления следующей части знаменателя к степени, исходя из формулы в задании.
 */
/*
void add_next(double *degree, int *n, double x)
{
    *degree = *degree / (x + *n);
    *n += 1;
}

int main(void)
{
    double x;
    int rc, flag = 0;
    int n = 1;
    double degree = 1;
    printf("Enter positive numbers(stops when entering any negative number): ");
    rc = scanf("%lf", &x);
    if (rc != 1) 
    {
        printf("Wrong input.\n");
        return IOERROR;
    }
    while (x >= 0) 
    {
        add_next(&degree, &n, x);
        flag = 1;
        rc = scanf("%lf", &x);
        if (rc != 1) 
        {
            printf("Wrong input.\n");
            return IOERROR;
        }
    }
    if (flag == 0) 
    {
        printf("No elements.\n");
        return IOERROR;
    }
    printf("%lf\n", exp(degree));
    return OK;
}
*/
int g(double *res)
{
    double degree = 1, x;
    int rc, flag = 0;
    int n = 1;
    printf("Enter positive numbers(stops when entering any negative number): ");
    rc = scanf("%lf", &x);
    if (rc != 1) 
    {
        printf("Wrong input.\n");
        return IOERROR;
    }
    while (x >= 0) 
    {
        degree /= (x + n);
        n += 1;
        flag = 1;
        rc = scanf("%lf", &x);
        if (rc != 1) 
        {
            return IOERROR;
        }
    }
    if (flag == 0) 
    {
        return NOELEMENTSERROR;
    }
    *res = exp(degree);
    return OK; 
}

int main(void)
{
    double res;
    int rc;
    rc = g(&res);
    if (rc == IOERROR)
    {
        printf("Wrong input.\n");
        return IOERROR;
    }
    if (rc == NOELEMENTSERROR)
    {
        printf("No elements.\n");
        return NOELEMENTSERROR;
    }
    printf("%lf\n", res);
    return OK;
}
