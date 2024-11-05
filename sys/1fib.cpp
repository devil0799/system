#include <iostream>
using namespace std;

int fibonacci_recursive(int n, int &steps) {
    steps++; // Increment step count for each call
    if (n <= 1) {
        return n;
    }
    return fibonacci_recursive(n - 1, steps) + fibonacci_recursive(n - 2, steps);
}

int main() {
    int n = 5; // Change this value to test for different numbers
    int steps = 0;
    int result = fibonacci_recursive(n, steps);
    
    cout << "Fibonacci(" << n << ") = " << result << ", Step count = " << steps << endl;
    return 0;
}
