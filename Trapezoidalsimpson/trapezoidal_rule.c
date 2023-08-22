#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

/* Define function here */
#define f(x) 1 / (1 + pow(x, 2))

int main()
{
    float a, b, integration = 0.0, h, k;
    int i, subInterval;
    system("cls");

    /* Input */
    printf("Enter lower limit of integration: ");
    scanf("%f", &a);
    printf("Enter upper limit of integration: ");
    scanf("%f", &b);
    printf("Enter number of sub intervals: ");
    scanf("%d", &subInterval);

    /* Calculation */
    /* Finding step size */
    h = (b - a) / subInterval;

    /* Finding Integration Value */
    integration = f(a) + f(b);

    for (i = 1; i <= subInterval - 1; i++)
    {
        k = a + i * h;
        integration = integration + 2 * f(k);
    }
    integration = integration * h / 2;
    printf("\nRequired value of integration is: %.3f", integration);
    getch();
    return 0;
}
