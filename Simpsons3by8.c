/*
    inte from x0 to x0+nh = (3/8)*h*((y0+yn)+2(y3+y6+y9..)+3(y1+y2+y4...))
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
    float others = 0.0f, mul3 = 0.0f;
    for (int i = 1; i < sz - 1; i++)
    {
        if (i % 3 == 0)
            mul3 += arr[i];
        else
            others += arr[i];
    }
    float ans = (3.0 / 8.0) * h * (arr[0] + arr[n] + 2.0 * mul3 + 3.0 * others);
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