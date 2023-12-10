/*
    inte from x0 to x0+nh = 0.5*h*((y0+yn)+2(y1+y2+y3..yn-1))
*/
#include <stdio.h>

float funct(float x)
{
    return 1.0 / (1.0 + x * x);
}

void trapezoidalMethod(float x0, float h, int n)
{
    // calculate y for n intervals
    const int sz = n + 1;
    float arr[100] = {0.0}, x = x0;

    for (int i = 0; i < sz; i++)
    {
        arr[i] = funct(x);
        x += h;
    }
    float others = 0.0f;
    for (int i = 1; i < sz - 1; i++)
        others += arr[i];
    float ans = 0.5 * h * (arr[0] + arr[n] + 2.0 * (others));
    printf("ans = %f", ans);
}

int main()
{
    float h, x0;
    int n;
    printf("Enter the value of starting x, h and number of intervals: ");
    scanf("%f %f %d", &x0, &h, &n);
    trapezoidalMethod(x0, h, n);
    return 0;
}