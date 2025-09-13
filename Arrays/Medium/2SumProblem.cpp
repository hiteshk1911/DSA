Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

//Brute Force Approach
- Use two nested loops to check each pair of elements
- If the sum of the pair equals the target, return their indices
- TC : O(N^2) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j}; // Return the indices of the two numbers
            }
        }
    }
    return {}; // Return an empty vector if no solution is found
}

//Optimal Approach(1)
- Use a hash map to store the elements and their indices
- For each element, check if the complement (target - element) exists in the hash map
- If it exists, return the indices of the current element and the complement
- TC : O(N) SC : O(N)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap; // Map to store the element and its index
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i}; // Return the indices of the two numbers
        }
        numMap[nums[i]] = i; // Store the element and its index in the map
    }
    return {}; // Return an empty vector if no solution is found
}

//Optimal Approach(2)
- Sort the array while keeping track of the original indices
- Use two pointers, one at the start and one at the end of the array
- If the sum of the elements at the two pointers equals the target, return their original indices
- If the sum is less than the target, move the left pointer to the right
- If the sum is greater than the target, move the right pointer to the left
- TC : O(N log N) SC : O(N)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<pair<int, int>> numWithIndex; // Pair of (element, original index)

    for (int i = 0; i < n; i++) {
        numWithIndex.push_back({nums[i], i});
    }

    sort(numWithIndex.begin(), numWithIndex.end()); // Sort based on the element values

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int sum = numWithIndex[left].first + numWithIndex[right].first;
        if (sum == target) {
            return {numWithIndex[left].second, numWithIndex[right].second}; // Return original indices
        } else if (sum < target) {
            left++; // Move left pointer to the right
        } else {
            right--; // Move right pointer to the left
        }
    }

    return {}; // Return an empty vector if no solution is found
}

