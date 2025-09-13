- Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

//Optimal Approach (1)
- Use the formula for the sum of the first n natural numbers to find the expected sum
- Calculate the actual sum of the elements in the array
- The missing number is the difference between the expected sum and the actual sum
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int findMissingNumber(vector<int> &nums)
{
    int n = nums.size();
    int expectedSum = n * (n + 1) / 2; // Sum of first n natural numbers
    int actualSum = 0;

    for (int num : nums)
    {
        actualSum += num;
    }

    return expectedSum - actualSum; // The missing number
}

//Optimal Approach (2)
- Use the XOR operation to find the missing number
- XOR all the numbers from 0 to n and XOR all the elements in the array
- The missing number is the result of XORing these two results
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int findMissingNumber(vector<int> &nums)
{
    int n = nums.size();
    int xorFull = 0;
    int xorArray = 0;

    for (int i = 0; i <= n; i++)
    {
        xorFull ^= i; // XOR of all numbers from 0 to n
    }

    for (int num : nums)
    {
        xorArray ^= num; // XOR of all elements in the array
    }

    return xorFull ^ xorArray; // The missing number
}
