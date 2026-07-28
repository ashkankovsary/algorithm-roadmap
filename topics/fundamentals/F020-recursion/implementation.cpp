// Recursion — a function calling itself to solve smaller instances
// of the same problem.
//
// Every recursive function has two essential parts:
//   1. Base Case: the simplest input, solved directly (stops the recursion)
//   2. Recursive Case: reduces the problem and calls itself

#include <bits/stdc++.h>
using namespace std;

// ---- Example 1: Sum of numbers from 1 to n ----
// sum(n) = n + sum(n - 1), with sum(0) = 0
int sum(int n) {
    if (n == 0) {                  // Base Case
        return 0;
    }
    return n + sum(n - 1);         // Recursive Case
}

// ---- Example 2: Power (base^exp) ----
// power(base, exp) = base * power(base, exp - 1), with power(base, 0) = 1
// Uses long long to avoid overflow, since results grow quickly.
long long power(long long base, int exp) {
    if (exp == 0) {                 // Base Case
        return 1;
    }
    return base * power(base, exp - 1); // Recursive Case
}

// ---- Example 3: Sum of elements in a vector ----
// Passed by const reference to avoid copying the container on every call.
int sumVector(const vector<int>& values, int index) {
    if (index == (int)values.size()) { // Base Case: reached the end
        return 0;
    }
    return values[index] + sumVector(values, index + 1); // Recursive Case
}

int main() {
    // ---- sum ----
    cout << sum(4) << "\n";           // 4 + 3 + 2 + 1 = 10

    // ---- power ----
    cout << power(2, 4) << "\n";      // 2^4 = 16

    // ---- sumVector ----
    vector<int> values = {10, 20, 30, 40};
    cout << sumVector(values, 0) << "\n"; // 10 + 20 + 30 + 40 = 100

    return 0;
}
