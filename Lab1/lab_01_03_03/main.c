#include <stdio.h>

#define OK 0
#define IOERROR 1

int main(void) 
{
    double a, v0, t, s;
    printf("Enter velocity, acceleration and time of movement: ");
    scanf("%lf%lf%lf", &v0, &a, &t);
    if (t < 0) 
    {
        printf("Movement time cannot be less than zero.\n");
        return IOERROR;
    }
    s = ((a * t * t) / 2) + v0 * t;
    printf("Total movement: %f\n", s);
    return OK;
}
