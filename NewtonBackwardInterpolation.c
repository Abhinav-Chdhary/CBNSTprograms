#include <stdio.h>

float ucal(float u, int limit)
{
    float res = 1.0f;
    for (int i = 0; i < limit; i++)
    {
        res *= (u + i);
    }
    return res;
}

float fact(int n)
{
    float res = 1.0f;
    for (int i = 2; i <= n; i++)
    {
        res *= i;
    }
    return res;
}

void backward(int n, float xs[], float ys[][100], float x)
{
    float ans = ys[n - 1][0];
    // making table
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            ys[j][i] = ys[j + 1][i - 1] - ys[j][i - 1];
        }
    }
    // calculation
    float u = (x - xs[n - 1]) / (xs[1] - xs[0]);
    for (int i = 1; i < n; i++)
    {
        // printf("%f ", ((ucal(u, i) * ys[n - i - 1][i]) / fact(i)));
        ans = ans + ((ucal(u, i) * ys[n - i - 1][i]) / fact(i));
    }
    printf("ans= %f", ans);
}

int main()
{
    int n;
    float target;
    printf("Enter the number of number of x and y values: ");
    scanf("%d", &n);
    printf("Enter the x you want the value for: ");
    scanf("%f", &target);

    float ys[100][100], xs[100];
    for (int i = 0; i < n; i++)
    {
        printf("x[%d] y[%d] :", i, i);
        scanf("%f %f", &xs[i], &ys[i][0]);
    }
    backward(n, xs, ys, target);
    return 0;
}