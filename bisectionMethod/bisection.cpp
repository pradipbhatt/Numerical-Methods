#include <iostream>
#include <cmath>

using namespace std;

// Define the quadratic equation: x^3 - 4x - 9
float equation(float x)
{
    return (x * x * x) - (4 * x) - 9;
}

// Bisection method function
float bisection(float func(float), float a, float b, float tolerance, int maxIterations)
{
    for (int i = 1; i <= maxIterations; i++)
    {
        float root = (a + b) / 2.0;
        float fx = func(root);

        cout << i << "\t\t" << root << "\t" << fx << endl;

        if (fabs(fx) < tolerance)
        {
            cout << "\nRoot found: " << root << endl;
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

    cout << "\nRoot not found within " << maxIterations << " iterations." << endl;
    return NAN; // Return NaN if root not found
}

int main()
{
    float a = 1.0;           // Left endpoint of the interval
    float b = 3.0;           // Right endpoint of the interval
    float tolerance = 1e-6;  // Tolerance for stopping criterion
    int maxIterations = 100; // Maximum number of iterations

    cout << "Iteration\tRoot\tf(x)" << endl;

    bisection(equation, a, b, tolerance, maxIterations);

    return 0;
}
