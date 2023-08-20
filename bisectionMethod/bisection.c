#include <stdio.h>
#include <math.h>

// Define the quadratic equation: x^3 - 4x - 9
float equation(float x)
{
    return (x * x * x) - (9* x) +1;
}

// Bisection method function
float bisection(float func(float), float a, float b, float tolerance, int maxIterations)
{
    for (int i = 1; i <= maxIterations; i++)
    {
        float root = (a + b) / 2.0;
        float fx = func(root);

        printf("%d\t\t%.6f\t%.6f\n", i, root, fx);

        if (fabs(fx) < tolerance)
        {
            printf("\nRoot found: %.6f\n", root);
            return root; // Return the root when found within tolerance
        }

        if (fx * func(a) < 0)
        {
            b = root; // Update the interval
        }
        else
        {
            a = root; // Update the interval
        }
    }

    printf("\nRoot not found within %d iterations.\n", maxIterations);
    return NAN; // Return NaN if root not found
}

int main()
{
    float a = 1.0;           // Left endpoint of the interval
    float b = 3.0;           // Right endpoint of the interval
    float tolerance = 1e-6;  // Tolerance for stopping criterion
    int maxIterations = 100; // Maximum number of iterations

    printf("Iteration\tRoot\tf(x)\n");

    bisection(equation, a, b, tolerance, maxIterations);

    return 0;
}
