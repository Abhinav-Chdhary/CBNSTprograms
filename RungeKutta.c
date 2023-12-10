/*
    Let y(0) = 1, then find y(0.2) = ?
    func(xn, yn) = (y^2-x^2)/(y^2+x^2)
*/
#include <stdio.h>

float funct(float x, float y)
{
    return (y * y - x * x) / (y * y + x * x);
}

void rungeKuttaMethod(float x, float y, float h)
{
    float k1 = h * funct(x, y);
    float k2 = h * funct(x + h / 2.0, y + k1 / 2.0);
    float k3 = h * funct(x + h / 2.0, y + k2 / 2.0);
    float k4 = h * funct(x + h, y + k3);
    float k = (1.0 / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
    // y of n+1 = y of n + k'
    float ans = y + k;
    printf("ans = %f", ans);
}

int main()
{
    float h, x, y, target;
    printf("Enter the value of x, y, and h: ");
    scanf("%f %f %f", &x, &y, &h);
    rungeKuttaMethod(x, y, h);
    return 0;
}