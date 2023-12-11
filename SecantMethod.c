#include <stdio.h>
#include <math.h>

#define e 0.00001 // Adjust the precision by changing the value of 'e'

double funct(double x)
{
    return x * x * x - x - 1.0;
}

void secantMethod(double x0, double x1)
{
    double ans = 0.0f;
    int maxit = 100;
    do
    {
        double xn = x1 - (x1 - x0) / (funct(x1) - funct(x0)) * funct(x1);
        x0 = x1;
        x1 = xn;

    } while (fabs(x1 - x0) >= e && maxit-- > 0);

    printf("Root: %f\n", x0);
}

int main()
{
    secantMethod(1, 2);
    return 0;
}
