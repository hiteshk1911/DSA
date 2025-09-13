Given an array of N integers, your task is to find unique quads that add up to give a target value.
In short, you need to return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.

//Brute Force Approach
- Use four nested loops to check all possible quadruplets
- Use a set to store unique quadruplets
- TC : O(N^4) SC : O(N)

//Better Approach
- Sort the array
- Fix two elements and use two pointers to find the other two elements
- Use a set to store unique quadruplets
- TC : O(N^3) SC : O(N)
- Code CPP:

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> uniqueQuadruplets;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int left = j + 1;
            int right = n - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target)
                {
                    uniqueQuadruplets.insert({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }

    return vector<vector<int>>(uniqueQuadruplets.begin(), uniqueQuadruplets.end());
}

//Optimal Approach
- Sort the array
- Fix two elements and use two pointers to find the other two elements
- Skip duplicate elements to avoid duplicate quadruplets
- TC : O(N^3) SC : O(1)
- Code CPP:

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1]) // Skip duplicate elements for the first position
            continue;

        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1]) // Skip duplicate elements for the second position
                continue;

            int left = j + 1;
            int right = n - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target)
                {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) // Skip duplicate elements for the third position
                        left++;
                    while (left < right && nums[right] == nums[right + 1]) // Skip duplicate elements for the fourth position
                        right--;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }

    return result;
}