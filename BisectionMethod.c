#include <stdio.h>
#include <math.h>

#define e 0.00001 // Adjust the precision by changing the value of 'e'

double funct(double x)
{
    return x * x * x - x - 1.0;
}

void bisectionMethod(double x0, double x1)
{
    double ans = 0.0f;
    int maxit = 100;
    do
    {
        double xn = (x0 - x1) / 2;
        if (funct(xn) < 0)
            x0 = xn;
        else
            x1 = xn;

    } while (fabs(x0 - x1) >= e && maxit-- > 0);

    printf("Root: %f\n", x0);
}

int main()
{
    bisectionMethod(1, 2);
    return 0;
}
