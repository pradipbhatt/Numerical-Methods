// Define the quadratic equation: x^3 - 4x - 9
function equation(x) {
    return x * x * x - 4 * x - 9;
}

// Bisection method function
function bisection(func, a, b, tolerance, maxIterations) {
    for (let i = 1; i <= maxIterations; i++) {
        let root = (a + b) / 2.0;
        let fx = func(root);

        console.log(i + "\t\t" + root + "\t" + fx);

        if (Math.abs(fx) < tolerance) {
            console.log("\nRoot found: " + root);
            return root; // Return the root when found within tolerance
        }

        if (fx * func(a) < 0) {
            b = root; // Update the interval
        } else {
            a = root; // Update the interval
        }
    }

    console.log("\nRoot not found within " + maxIterations + " iterations.");
    return NaN; // Return NaN if root not found
}

// Main function
function main() {
    const a = 1.0; // Left endpoint of the interval
    const b = 3.0; // Right endpoint of the interval
    const tolerance = 1e-6; // Tolerance for stopping criterion
    const maxIterations = 100; // Maximum number of iterations

    console.log("Iteration\tRoot\tf(x)");

    bisection(equation, a, b, tolerance, maxIterations);
}

main();
