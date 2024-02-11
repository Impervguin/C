#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define OK 0
#define IOERROR 1
#define NSECERROR 2
#define EPS 0.000001

/**
 * Функция для проверки на равенство чисел с плавающей точкой с точностью EPS
 */
bool float_equal(double x1, double x2) 
{
    return fabs(x1 - x2) < EPS;
}

/**
 * Функция для вычисления векторного произведения двух векторов (x1, y1) и (x2, y2)
 */
double vec_mul(double x1, double y1, double x2, double y2)
{
    return x1 * y2 - y1 * x2;
}

/**
 * Функция для проверки на пересечение двух отрезков, заданных двумя точками каждый: ((x1, y1), (x2, y2)) и ((x3, y3), (x4, y4))
 * Под пересечением в данной реализации понимается то, что отрезки имеют одну общую точку, и это точка не является краевой для каждого из отрезков
 */
bool has_intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) 
{
    double v1_dir = vec_mul(x2 - x1, y2 - y1, x3 - x1, y3 - y1), v2_dir = vec_mul(x2 - x1, y2 - y1, x4 - x1, y4 - y1);
    if (v1_dir * v2_dir >= 0)
    {
        return false;
    }
    double v3_dir = vec_mul(x4 - x3, y4 - y3, x1 - x3, y1 - y3), v4_dir = vec_mul(x4 - x3, y4 - y3, x2 - x3, y2 - y3);
    if (v3_dir * v4_dir >= 0)
    {
        return false;
    }
    return true;
}

int main(void) 
{
    int rc;
    double xp, yp, xq, yq, xr, yr, xs, ys;
    printf("Enter coordinate of first section (xp yp xq yq): ");
    rc = scanf("%lf%lf%lf%lf", &xp, &yp, &xq, &yq);
    if (rc != 4) 
    {
        printf("Wrong input.\n");
        return IOERROR;
    }
    
    printf("Enter coordinate of second section (xr yr xs ys): ");
    rc = scanf("%lf%lf%lf%lf", &xr, &yr, &xs, &ys);
    if (rc != 4) 
    {
        printf("Wrong input.\n");
        return IOERROR;
    }
    
    if ((float_equal(xp, xq) && float_equal(yp, yq)) || (float_equal(xr, xs) && float_equal(yr, ys)))
    {
        printf("Section cannot be one point.\n");
        return NSECERROR;
    }
    
    if (has_intersect(xp, yp, xq, yq, xr, yr, xs, ys))
    {
        printf("1\n");
    } 
    else
    {
        printf("0\n");
    }
    return OK;
}
