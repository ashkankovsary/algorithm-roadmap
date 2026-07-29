#include <bits/stdc++.h>
using namespace std;

// Check whether bit i (0-indexed from the right) is set in x.
bool checkBit(int x, int i) {
    return (x & (1 << i)) != 0;
}

// Set bit i to 1.
int setBit(int x, int i) {
    return x | (1 << i);
}

// Clear bit i (set it to 0).
int clearBit(int x, int i) {
    return x & ~(1 << i);
}

// Toggle bit i (flip 0 <-> 1).
int toggleBit(int x, int i) {
    return x ^ (1 << i);
}

// Count how many bits are set to 1.
int countSetBits(int x) {
    return __builtin_popcount(x);
}

// Check whether x is a power of two (exactly one bit set).
bool isPowerOfTwo(int x) {
    return x > 0 && (x & (x - 1)) == 0;
}

// Extract the lowest set bit of x (isolates the rightmost 1-bit).
int lowestSetBit(int x) {
    return x & (-x);
}

int main() {
    int x = 22; // binary: 10110

    cout << "x = " << x << " (binary: " << bitset<8>(x) << ")\n\n";

    cout << "checkBit(x, 1) = " << checkBit(x, 1) << " (expected: 1)\n";
    cout << "checkBit(x, 0) = " << checkBit(x, 0) << " (expected: 0)\n";

    cout << "setBit(x, 0) = " << setBit(x, 0)
         << " (binary: " << bitset<8>(setBit(x, 0)) << ", expected: 23)\n";

    cout << "clearBit(x, 1) = " << clearBit(x, 1)
         << " (binary: " << bitset<8>(clearBit(x, 1)) << ", expected: 20)\n";

    cout << "toggleBit(x, 2) = " << toggleBit(x, 2)
         << " (binary: " << bitset<8>(toggleBit(x, 2)) << ", expected: 18)\n";

    cout << "countSetBits(x) = " << countSetBits(x) << " (expected: 3)\n";

    cout << "isPowerOfTwo(16) = " << isPowerOfTwo(16) << " (expected: 1)\n";
    cout << "isPowerOfTwo(x) = " << isPowerOfTwo(x) << " (expected: 0)\n";

    cout << "lowestSetBit(x) = " << lowestSetBit(x)
         << " (binary: " << bitset<8>(lowestSetBit(x)) << ", expected: 2)\n";

    return 0;
}
