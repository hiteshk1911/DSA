Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.

//Brute Force Approach
- Use three nested loops to generate all possible subarrays and calculate their XOR
- If the XOR is equal to k, increment the count
- TC : O(N^3) SC : O(1)

//Better Approach
- Use two nested loops to generate all possible subarrays and calculate their XOR
- If the XOR is equal to k, increment the count
- TC : O(N^2) SC : O(1)

//Optimal Approach(1) - for both negative & positive integers
- Use a hash map to store the frequency of prefix XORs
- For each element, calculate the current prefix XOR and check if (current_prefix_XOR ^ k) exists in the hash map
- If it exists, add its frequency to the count
- TC : O(N) SC : O(N)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int countSubarraysWithXOR(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> prefixXORCount;
    int count = 0;
    int prefixXOR = 0;

    for (int i = 0; i < n; i++)
    {
        prefixXOR ^= arr[i];

        if (prefixXOR == k)
        {
            count++;
        }

        int requiredXOR = prefixXOR ^ k;
        if (prefixXORCount.find(requiredXOR) != prefixXORCount.end())
        {
            count += prefixXORCount[requiredXOR];
        }

        prefixXORCount[prefixXOR]++;
    }

    return count;
}

//Optimal Approach(2) - Two Pointer (Only for non-negative integers)
- Use two pointers to maintain a sliding window
- Expand the right pointer and calculate the XOR of the current window
- If the XOR is less than k, move the right pointer to the right
- If the XOR is greater than k, move the left pointer to the right
- If the XOR is equal to k, increment the count and move the right pointer to the right
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int countSubarraysWithXOR(vector<int> &arr, int k)
{
    int n = arr.size();
    int left = 0, right = 0;
    int currentXOR = 0;
    int count = 0;

    while (right < n)
    {
        currentXOR ^= arr[right];

        while (currentXOR > k && left <= right)
        {
            currentXOR ^= arr[left];
            left++;
        }

        if (currentXOR == k)
        {
            count++;
        }

        right++;
    }

    return count;
}
