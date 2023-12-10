#include <stdio.h>

void lagranges(int n, float mat[][2], float x)
{
    double ans = 0.0f;
    for (int i = 0; i < n; i++)
    {
        double num = 1.0f, den = 1.0f;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                num *= (x - mat[j][0]);
                den *= (mat[i][0] - mat[j][0]);
            }
        }
        ans += (num / den) * mat[i][1];
    }
    printf("ans= %lf", ans);
}

int main()
{
    int n;
    float target;
    printf("Enter the number of number of x and y values: ");
    scanf("%d", &n);
    printf("Enter the x you want the value for: ");
    scanf("%f", &target);

    float matrix[100][2];
    for (int i = 0; i < n; i++)
    {
        printf("x[%d] y[%d] :", i, i);
        scanf("%f %f", &matrix[i][0], &matrix[i][1]);
    }
    lagranges(n, matrix, target);
    return 0;
}