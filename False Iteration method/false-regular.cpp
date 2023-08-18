#include <iostream>
#include <cmath>

#define f(x) (x) * log10(x) - 1.2

int main()
{
    float x0, x1, x2, f0, f1, f2, e;
    int step = 1;
    
    system("cls"); // You can remove this line or replace it with system("clear") for non-Windows systems.

up:
    std::cout << "Enter two initial guesses:" << std::endl;
    std::cin >> x0 >> x1;
    std::cout << "Enter tolerable error:" << std::endl;
    std::cin >> e;
    
    f0 = f(x0);
    f1 = f(x1);

    if (f0 * f1 > 0.0)
    {
        std::cout << "Incorrect Initial Guesses." << std::endl;
        goto up;
    }

    std::cout << "\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)" << std::endl;

    do
    {
        x2 = x0 - (x0 - x1) * f0 / (f0 - f1);
        f2 = f(x2);
        std::cout << step << "\t\t" << x0 << "\t" << x1 << "\t" << x2 << "\t" << f2 << std::endl;

        if (f0 * f2 < 0)
        {
            x1 = x2;
            f1 = f2;
        }
        else
        {
            x0 = x2;
            f0 = f2;
        }
        step = step + 1;

    } while (fabs(f2) > e);

    std::cout << "\nRoot is: " << x2 << std::endl;
    return 0;
}
