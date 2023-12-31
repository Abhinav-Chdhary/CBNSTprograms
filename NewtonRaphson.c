#include <stdio.h>
#include <math.h>

#define e 0.0001 // Adjust the precision by changing the value of 'e'

double funct(double x)
{
    return x * x * x - x - 1.0;
}

double functDash(double x)
{
    return 3.0 * x * x - 1.0;
}

void newtonRaphson(double x)
{
    double h = funct(x) / functDash(x);

    while (fabs(h) >= e)
    {
        h = funct(x) / functDash(x);
        x = x - h;
    }

    printf("Root: %f\n", x);
}

int main()
{
    newtonRaphson(1.5);
    return 0;
}
