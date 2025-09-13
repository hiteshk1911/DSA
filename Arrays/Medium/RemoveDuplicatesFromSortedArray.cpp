//Brute Force Approach
- Store the unique elements in a set
- Copy the elements from the set back to the array
- Return the size of the set
- TC : O(N) SC : O(N)

//Optimal Approach
- Use two pointers to keep track of the position of unique elements
- Iterate through the array and compare each element with the last unique element found
- If they are different, move the unique pointer forward and update the value at that position
- Return the position of the unique pointer + 1 as the new length of the array
- TC : O(N) SC : O(1)
- Note : The input array is modified in place to contain the unique elements at the start of the array
- The elements beyond the new length are not important
- The order of elements is maintained
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    int uniqueIndex = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[uniqueIndex])
        {
            uniqueIndex++;
            nums[uniqueIndex] = nums[i];
        }
    }

    return uniqueIndex + 1;
}

