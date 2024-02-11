#include <stdio.h>
#include <math.h>

#define OK 0
#define IOERROR 1

/**
 * Функция для вычисления s(x) с точностью eps
 */
double s(double x, double eps) 
{
    double now, sum = 0;
    int i = 1;
    now = 1;
    
    while (now >= eps) 
    {
        sum += now;
        now = now * (2 * i - 1) * x * x / (2 * i);
        i++;
    }
    return sum;
}

/**
 * Функция f(x)
 */
double f(double x) 
{ 
    return 1 / sqrt(1 - x * x);
}

/**
 * Функция для вычисления абсолютной погрешности
 */
double abs_error(double s, double f)
{
    return fabs(s - f);
}

/**
 * Функция для вычисления относительной погрешности
 */
double eps_error(double s, double f)
{
    return abs_error(s, f) / fabs(f);
}

int main(void)
{
    double eps, x;
    int rc;
    printf("Enter x and accuracy(epsilon): ");
    rc = scanf("%lf%lf", &x, &eps);
    if (rc != 2) 
    {
        printf("Wrong input.\n");
        return IOERROR;
    }
    
    if (eps <= 0 || eps > 1 || x <= -1 || x >= 1) 
    {
        printf("Wrong input.\n");
        return IOERROR;
    }
    double fa = f(x), sa = s(x, eps);
    printf("s = %lf  f = %lf ", sa, fa);
    printf("abs = %lf rel = %lf\n", abs_error(sa, fa), eps_error(sa, fa));
    return OK;
}
