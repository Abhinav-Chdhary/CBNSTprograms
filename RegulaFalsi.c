#include <stdio.h>
#include <math.h>

#define e 0.0001 // Adjust the precision by changing the value of 'e'

double funct(double x)
{
    return x * x * x - x - 1.0;
}

void regulaFalsi(double x0, double x1)
{
    double ans = 0.0f;
    int maxit = 100;
    do
    {
        double xn = x0 - (x1 - x0) / (funct(x1) - funct(x0)) * funct(x0);
        if (funct(xn) < 0)
            x1 = xn;
        else
            x0 = xn;
    } while (fabs(x0 - x1) >= e && maxit > 0);

    printf("Root: %f\n", x0);
}

int main()
{
    regulaFalsi(1, 2);
    return 0;
}
