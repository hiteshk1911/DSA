Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero.
In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

//Brute Force Approach
- Use three nested loops to check all possible triplets
- Use a set to store unique triplets
- TC : O(N^3) SC : O(N)

//Better Approach
- Sort the array
- Fix one element and use two pointers to find the other two elements
- Use a set to store unique triplets
- TC : O(N^2) SC : O(N)
- Code CPP:

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> uniqueTriplets;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++)
    {
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0)
            {
                uniqueTriplets.insert({nums[i], nums[left], nums[right]});
                left++;
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
}

//Optimal Approach
- Sort the array
- Fix one element and use two pointers to find the other two elements
- Skip duplicate elements to avoid duplicate triplets
- TC : O(N^2) SC : O(1)
- Code CPP:

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1]) // Skip duplicate elements
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0)
            {
                result.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1]) // Skip duplicate elements
                    left++;
                while (left < right && nums[right] == nums[right + 1]) // Skip duplicate elements
                    right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return result;
}