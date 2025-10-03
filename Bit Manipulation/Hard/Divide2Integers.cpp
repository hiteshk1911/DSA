Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.



Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.

//Complexity Analysis
- TC: O(log N) where N is the absolute value of the dividend. This is because in each iteration, we are effectively doubling the divisor (using bit shifts) until it exceeds the dividend.
- SC: O(1) as we are using a constant amount of space.

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Sign of result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long and positive
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        long long ans = 0;

        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            // Keep doubling divisor until it is larger than dividend
            while ((temp << 1) <= dvd) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            ans += multiple;
        }

        return negative ? -ans : ans;
    }
};
