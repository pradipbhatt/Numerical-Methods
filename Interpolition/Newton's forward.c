#include <stdio.h>
#include <conio.h>
int main()
{

    float x[100], y[100], xp, yp = 0.0, p;
    int i, j, n;
    system("cls");

    printf("Enter the  number of data :");
    scanf("%d", &n);

    printf("Enter the data :\t");
    for (i = 0; i <= n; i++)
    {
        printf("x[%d]="i);
        scanf("%f", &x[i]);
        printf("y[%d]="i);
        scanf("%f", &y[i]);
    }

    printf("\n The Interpolition Point:");
    scanf("%d", &xp);

    // Implementing Interpolition Point
    for (i = 1; i <= n; i++)
    {
        p = 1;
        for (j = 1; j <= n; j++)

        {
            if (i != j)
            {
                p = p * (xp - x[j] / (x[i] - x[j]));
            }
        }
        yp = yp + p * y[i];
    }

    printf("Interpolitation Point at  %.3f\n ", xp, yp);
}