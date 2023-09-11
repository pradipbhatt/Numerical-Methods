#include <stdio.h>

int main()
{
    system("cls");
    float x[100], y[100], xp, yp = 0.0, p;
    int i, j, n;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the data:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    printf("Enter the interpolation point: ");
    scanf("%f", &xp);

    // Implementing Interpolation
    for (i = 0; i < n; i++)
    {
        p = 1.0;
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                p = p * (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp = yp + p * y[i];
    }

    printf("Interpolation Point at %.3f is %.3f\n", xp, yp);

    return 0;
}
