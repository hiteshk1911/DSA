🔹 Method 1: Brian Kernighan’s Algorithm (Optimal)

👉 Keep removing the rightmost set bit until number becomes 0.
👉 Runs in O(number of set bits).

#include <iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1); // remove rightmost set bit
        count++;
    }
    return count;
}

int main() {
    int n = 29; // binary: 11101 -> 4 set bits
    cout << "Number of set bits in " << n << " = " << countSetBits(n) << endl;
    return 0;
}


✅ Output:

Number of set bits in 29 = 4

🔹 Method 2: Bitwise Checking (Slower)

👉 Check each bit using right-shift.
👉 Runs in O(log n).

int countSetBitsLoop(int n) {
    int count = 0;
    while (n) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}