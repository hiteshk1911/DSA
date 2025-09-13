Given an array of integers and an integer k, return the total number of subarrays whose sum equals k.
A subarray is a contiguous non-empty sequence of elements within an array.

//Brute Force Approach
- Generate all possible subarrays and calculate their sums
- TC : O(N^2) SC : O(1)

//Optimal Approach(1)
- Use a hashmap to store the cumulative sum and its frequency
- For each element, calculate the cumulative sum and check if (cumulative sum - k) exists in the hashmap
- NOTE: Works for negative numbers as well
- TC : O(N) SC : O(N)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int countSubarraysWithSumK(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> prefixSumCount;
    int cumulativeSum = 0;
    int count = 0;

    // Initialize the map with sum 0 having one occurrence
    prefixSumCount[0] = 1;

    for (int i = 0; i < n; i++)
    {
        cumulativeSum += arr[i];

        // Check if there is a prefix sum that when subtracted from cumulativeSum gives k
        if (prefixSumCount.find(cumulativeSum - k) != prefixSumCount.end())
        {
            count += prefixSumCount[cumulativeSum - k];
        }

        // Update the frequency of the current cumulative sum
        prefixSumCount[cumulativeSum]++;
    }

    return count;
}

//Optimal Approach(2) (Only for non-negative numbers) - Does not work for negative numbers
- Use the sliding window technique to find subarrays with sum k
- Expand the window by adding elements to the right until the sum is greater than or equal to k
- If the sum exceeds k, shrink the window from the left until the sum is less than or equal to k
- If the sum equals k, increment the count
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int countSubarraysWithSumK(vector<int> &arr, int k)
{
    int n = arr.size();
    int left = 0, right = 0;
    int currentSum = 0;
    int count = 0;

    while (right < n)
    {
        currentSum += arr[right];

        // Shrink the window from the left if the current sum exceeds k
        while (currentSum > k && left <= right)
        {
            currentSum -= arr[left];
            left++;
        }

        // If the current sum equals k, increment the count
        if (currentSum == k)
        {
            count++;
        }

        right++;
    }

    return count;
}