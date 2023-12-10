/*
    Let y(0) = 1, then find y(x) = ?
    func(xn, yn) = xn+yn
*/
#include <stdio.h>

float funct(float x, float y)
{
    return x + y;
}

void eulersMethod(float x, float y, float h, float target)
{
    while (x < target)
    {
        float dydx = funct(x, y);
        y = y + h * dydx;
        x = x + h;
    }
    printf("y is %f at %f\n", y, target);
}

int main()
{
    float h, x, y, target;
    printf("Enter the value of x, y, and h: ");
    scanf("%f %f %f", &x, &y, &h);
    printf("Enter the x you want to find y for: ");
    scanf("%f", &target);
    eulersMethod(x, y, h, target);
    return 0;
}