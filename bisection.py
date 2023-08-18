# Define the quadratic equation: x^3 - 4x - 9
def quadratic_equation(x):
    return x**3 - 4*x - 9

# Bisection method function
def bisection_method(func, interval_start, interval_end, tolerance, max_iterations):
    for iteration in range(1, max_iterations + 1):
        root = (interval_start + interval_end) / 2.0
        function_value = func(root)

        print(f"{iteration}\t\t{root:.6f}\t{function_value:.6f}")

        if abs(function_value) < tolerance:
            print(f"\nRoot found: {root:.6f}")
            return root  # Return the root when found within tolerance

        if function_value * func(interval_start) < 0:
            interval_end = root  # Update the interval
        else:
            interval_start = root  # Update the interval

    print(f"\nRoot not found within {max_iterations} iterations.")
    return None  # Return None if root not found

# Main function
def main():
    interval_start = 1.0  # Left endpoint of the interval
    interval_end = 3.0  # Right endpoint of the interval
    tolerance = 1e-6  # Tolerance for stopping criterion
    max_iterations = 100  # Maximum number of iterations

    print("Iteration\tRoot\tf(x)")

    bisection_method(quadratic_equation, interval_start, interval_end, tolerance, max_iterations)

if __name__ == "__main__":
    main()
#  if you would like to avoid using if __name__ == "__main__":, you can directly call the main() function without the need for this construct.