Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the 'nth root is not an integer, return -1.

//Brute Force Approach
- Traverse all numbers from 1 to M and find the largest number whose Nth power is less than or equal to M
- TC : O(M^(1/N)) SC : O(1)
- Code CPP:

#include <bits/stdc++.h>
using namespace std;

int nthRoot(int N, int M) {
    if (M == 0 || M == 1) return M; // Nth root of 0 is 0 and Nth root of 1 is 1

    for (int i = 1; i <= M; i++) {
        long long power = 1;
        for (int j = 1; j <= N; j++) {
            power *= i;
            if (power > M) break; // No need to continue if power exceeds M
        }
        if (power == M) {
            return i; // Nth root found
        } else if (power > M) {
            return -1; // Nth root is not an integer
        }
    }
    return -1; // This line will never be reached for positive integers
}

//Optimal Approach
- Use binary search to find the Nth root
- TC : O(N * log M) SC : O(1)
- Code CPP:

#include <bits/stdc++.h>
using namespace std;

int power(int base, int exp) { //This can be optimized using fast exponentiation -> O(log exp)
    long long result = 1;
    for (int i = 1; i <= exp; i++) {
        result *= base;
        if (result > INT_MAX) return INT_MAX; // Prevent overflow
    }
    return result;
}
int fastPower(int base, int exp) { //O(log exp)
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) { // If exp is odd
            result *= base;
            if (result > INT_MAX) return INT_MAX; // Prevent overflow
        }
        base *= base; // Square the base
        if (base > INT_MAX) return INT_MAX; // Prevent overflow
        exp /= 2; // Divide exp by 2
    }
    return result;
}
int nthRoot(int N, int M) {
    if (M == 0 || M == 1) return M; // Nth root of 0 is 0 and Nth root of 1 is 1

    int low = 1, high = M, ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long midPower = power(mid, N); // Calculate mid^N

        if (midPower == M) {
            return mid; // Nth root found
        } else if (midPower < M) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    return -1; // Nth root is not an integer
}