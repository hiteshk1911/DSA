Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

//Brute Force Approach
- Use a map to count the occurrences of each element
- Traverse the map to find the element with a count of 1
- TC : O(N) SC : O(N)

//Optimal Approach
- Use the XOR operation to find the single element
- XORing two identical numbers results in 0, and XORing a number with 0 results in the number itself
- Thus, XORing all elements will cancel out the duplicates, leaving only the single element
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int findSingleNumber(vector<int> &nums)
{
    int singleNumber = 0;
    for (int num : nums)
    {
        singleNumber ^= num; // XOR operation
    }
    return singleNumber;
}