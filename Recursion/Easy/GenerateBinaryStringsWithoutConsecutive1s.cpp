Given an integer n, return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order.

A binary string is a string consisting only of characters '0' and '1'.


Examples:
Input: n = 3

Output: ["000", "001", "010", "100", "101"]

Explanation: All strings are of length 3 and do not contain consecutive 1s.

Input: n = 2

Output: ["00", "01", "10"]

//Solution
Complexity

Roughly
𝑂
(
𝜙
𝑛
)
O(ϕ
n
) where
𝜙
≈
1.618
ϕ≈1.618 (Fibonacci growth), since the count of valid strings follows Fibonacci numbers.

Recursion depth: O(n).

#include <bits/stdc++.h>
using namespace std;

void generateBinaryNoConsec1(int n, string str) {
    // Base case
    if(str.size() == n) {
        cout << str << endl;
        return;
    }

    // Always safe to add '0'
    generateBinaryNoConsec1(n, str + "0");

    // Add '1' only if last char is not '1'
    if(str.empty() || str.back() != '1') {
        generateBinaryNoConsec1(n, str + "1");
    }
}
