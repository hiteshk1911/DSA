Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

//Brute Force Approach
- Use two nested loops to consider all subarrays
- Calculate the sum of each subarray and check if it equals k
- Keep track of the maximum length of subarrays that sum to k
- TC : O(N^2) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxLength = 0;

    for (int i = 0; i < n; i++)
    {
        int currentSum = 0;
        for (int j = i; j < n; j++)
        {
            currentSum += arr[j];
            if (currentSum == k)
            {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
}

//Optimal Approach(1)
- Use a hash map to store the cumulative sum and its earliest index
- Traverse the array, updating the cumulative sum
- Check if (cumulative sum - k) exists in the map to find a subarray summing to k
- Update the maximum length whenever a valid subarray is found
- NOTE : This approach works for arrays with both positive and negative numbers
- TC : O(N) SC : O(N)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> sumIndexMap; // Maps cumulative sum to its earliest index
    int cumulativeSum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++)
    {
        cumulativeSum += arr[i];

        if (cumulativeSum == k)
        {
            maxLength = i + 1; // Subarray from start to current index
        }

        if (sumIndexMap.find(cumulativeSum - k) != sumIndexMap.end())
        {
            maxLength = max(maxLength, i - sumIndexMap[cumulativeSum - k]);
        }

        // Store the earliest index of the cumulative sum - only if it is not already present - to ensure the longest subarray
        if (sumIndexMap.find(cumulativeSum) == sumIndexMap.end())
        {
            sumIndexMap[cumulativeSum] = i;
        }
    }

    return maxLength;
}

//Optimal Approach(2) (Only for Positive Numbers)
- Use the sliding window technique to find the longest subarray with sum k
- Maintain a window defined by two pointers and adjust the window size based on the current sum
- Expand the window by moving the right pointer and contract it by moving the left pointer when the sum exceeds k
- Update the maximum length whenever the current sum equals k
- NOTE : This approach works only for arrays with positive numbers
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> &arr, int k)
{
    int n = arr.size();
    int left = 0, right = 0;
    int currentSum = 0;
    int maxLength = 0;

    while (right < n)
    {
        currentSum += arr[right];

        while (currentSum > k && left <= right) // Shrink the window from the left if the current sum exceeds k
        {
            currentSum -= arr[left];
            left++;
        }

        if (currentSum == k)
        {
            maxLength = max(maxLength, right - left + 1);
        }

        right++;
    }

    return maxLength;
}

