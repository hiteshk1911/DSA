//Brute Force Approach
- For each element in the array, if it is 1, count consecutive 1s
- Keep track of the maximum count of consecutive 1s found
- TC : O(N^2) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int maxCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            int count = 0;
            for (int j = i; j < n && nums[j] == 1; j++)
            {
                count++;
            }
            maxCount = max(maxCount, count);
        }
    }

    return maxCount;
}

//Optimal Approach
- Traverse the array once, maintaining a count of consecutive 1s
- Reset the count when a 0 is encountered
- Update the maximum count whenever a 1 is encountered
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxCount = 0;
    int count = 0;

    for (int num : nums)
    {
        if (num == 1)
        {
            count++;
            maxCount = max(maxCount, count);
        }
        else
        {
            count = 0; // Reset count when a 0 is encountered
        }
    }

    return maxCount;
}