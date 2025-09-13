You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.
Note: The question explicitly states that if the given number, n, is not a perfect square, our objective is to find the maximum number, x, such that x squared is less than or equal to n (x*x <= n). In other words, we need to determine the floor value of the square root of n.

//Brute Force Approach
- Traverse all numbers from 1 to n and find the largest number whose square is less than or equal to n
- TC : O(sqrt(N)) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int squareRoot(int n) {
    if (n == 0 || n == 1) return n; // Square root of 0 is 0 and square root of 1 is 1

    for (int i = 1; i <= n / 2; i++) {
        if (i * i == n) {
            return i; // Perfect square found
        } else if (i * i > n) {
            return i - 1; // Return the floor value of the square root
        }
    }
    return -1; // This line will never be reached for positive integers
}

//Optimal Approach
- Use binary search to find the square root
- TC : O(log N) SC : O(1)
- CPP Code:
#include <bits/stdc++.h>
using namespace std;

int squareRoot(int n) {
    if (n == 0 || n == 1) return n; // Square root of 0 is 0 and square root of 1 is 1

    int low = 1, high = n / 2, ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long midSquared = (long long)mid * mid; // Use long long to prevent overflow

        if (midSquared == n) {
            return mid; // Perfect square found
        } else if (midSquared < n) {
            ans = mid; // Update answer and search in the right half
            low = mid + 1;
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    return ans; // Return the floor value of the square root
}

// Note: The use of long long for midSquared is crucial to avoid overflow when mid is large.

//For decimal values
#include <bits/stdc++.h>
using namespace std;

double squareRoot(int n, int precision) {
    if (n == 0 || n == 1) return n; // Square root of 0 is 0 and square root of 1 is 1

    int low = 1, high = n / 2, ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long midSquared = (long long)mid * mid; // Use long long to prevent overflow

        if (midSquared == n) {
            return mid; // Perfect square found
        } else if (midSquared < n) {
            ans = mid; // Update answer and search in the right half
            low = mid + 1;
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    double increment = 0.1;
    double result = ans;

    for (int i = 0; i < precision; i++) {
        while (result * result <= n) {
            result += increment;
        }
        result -= increment; // Step back to the last valid value
        increment /= 10; // Move to the next decimal place
    }

    return result;
}