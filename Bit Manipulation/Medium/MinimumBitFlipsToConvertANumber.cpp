🔹 Idea

Let the two numbers be a and b.

XOR them: a ^ b → bits that are different between a and b.

Count the number of set bits in a ^ b → that’s the minimum flips needed.

🔹 Code (C++)
#include <iostream>
using namespace std;

// Brian Kernighan's method to count set bits
int countSetBits(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1); // remove rightmost set bit
        count++;
    }
    return count;
}

// Minimum flips to convert a -> b
int minBitFlips(int a, int b) {
    int xorVal = a ^ b;  // bits that differ
    return countSetBits(xorVal);
}

int main() {
    int a = 29; // 11101
    int b = 15; // 01111

    cout << "Minimum bit flips to convert " << a << " to " << b
         << " = " << minBitFlips(a, b) << endl;

    return 0;
}