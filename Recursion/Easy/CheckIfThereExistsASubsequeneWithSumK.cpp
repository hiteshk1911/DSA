Given an array nums and an integer k. R﻿eturn true if there exist subsequences such that the sum of all elements in subsequences is equal to k else false.


Examples:
Input : nums = [1, 2, 3, 4, 5] , k = 8

Output : Yes

Explanation : The subsequences like [1, 2, 5] , [1, 3, 4] , [3, 5] sum up to 8.

Input : nums = [4, 3, 9, 2] , k = 10

Output : No

Explanation : No subsequence can sum up to 10.

//Solution

class Solution {
private:
    bool checkHelper(int n, vector<int>& arr, int k, int index) {
        // Base case
        if(index >= n) {
            return (k == 0);
        }

        // Exclude current element
        if(checkHelper(n, arr, k, index + 1)) return true;

        // Include current element (only if it doesn't exceed k)
        if(arr[index] <= k) {
            if(checkHelper(n, arr, k - arr[index], index + 1)) return true;
        }

        return false;
    }

public:
    bool existsSubsequenceWithTargetSum(vector<int>& arr, int k) {
        int n = arr.size();
        return checkHelper(n, arr, k, 0);
    }
};
