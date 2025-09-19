//Complexity
Total strings: 2^n.
Time: O(2^n * n) (since printing each string takes O(n)).
Space: O(n) recursion depth.

#include <bits/stdc++.h>
using namespace std;

void generateBinary(int n, string str) {
    // Base case: if string length == n, print it
    if(str.size() == n) {
        cout << str << endl;
        return;
    }

    // Choice 1: add '0'
    generateBinary(n, str + "0");

    // Choice 2: add '1'
    generateBinary(n, str + "1");
}

int main() {
    int n = 3; // Example: length of binary string
    generateBinary(n, "");
    return 0;
}
