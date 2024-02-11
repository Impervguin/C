#include <stdio.h>
#include <math.h>

#define OK 0
#define IOERROR 1
#define PI 3.1415926535
#define DEG_TO_RADS_MULT (PI / 180)
#define MAX_ANGLE 360

int main(void)
{
    double a, b, fi, s;
    printf("Enter sides of triangle and angle between them: ");
    scanf("%lf%lf%lf", &a, &b, &fi);
    if ((a < 0) || (b < 0))
    {
        printf("Side cannot be lower than zero.\n");
        return IOERROR;
    }
    if (fi < 0)
    {
        printf("Angle cannot be lower than zero.\n");
        return IOERROR;
    }
    if (fi > MAX_ANGLE)
    {
        printf("Angle cannot be this high.\n");
        return IOERROR;
    }
    s = (a * b * sin(fi * DEG_TO_RADS_MULT)) / 2;
    printf("Square is %f\n", s);
    return OK;
}
