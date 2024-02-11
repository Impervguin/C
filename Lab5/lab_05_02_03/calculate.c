#include "calculate.h"

int calc_expected_value(FILE *f, double *res)
{
    size_t count = 0;
    double sum = 0;
    double now;
    while (fscanf(f, "%lf", &now) == 1)
    {
        sum += now;
        count++;
    }
    if (feof(f))
    {
        if (count == 0)
            return NO_ELEMENTS_ERROR;
        *res = (sum / count);
        return OK;
    }
    return FIO_ERROR;
}

int calc_standard_deviation(FILE *f, double *res, double expected_value)
{
    double now, square_sum = 0;
    size_t count = 0;
    while (fscanf(f, "%lf", &now) == 1)
    {
        square_sum += (now - expected_value) * (now - expected_value);
        count++;
    }
    if (feof(f))
    {
        if (count == 0)
            return NO_ELEMENTS_ERROR;
        *res = sqrt(square_sum / count);
        return OK;
    }
    return FIO_ERROR;
}

int check_three_sigma_rule(FILE *f, int *res, double expected_value, double deviation)
{
    size_t count = 0, count_three_sigma = 0;
    double now;
    if (deviation < EPS)
    {
        *res = 0;
        return OK;
    }
    while (fscanf(f, "%lf", &now) == 1)
    {
        if (expected_value - 3 * deviation - now < EPS && now - (expected_value + 3 * deviation) < EPS)
            count_three_sigma++;
        count++;
    }
    if (feof(f))
    {
        if (count == 0)
            return NO_ELEMENTS_ERROR;
        *res = (((double) count_three_sigma) / count > THREE_SIGMA_PROB ? 1 : 0);
        return OK;
    }
    return FIO_ERROR;
}
