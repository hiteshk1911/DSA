Given an array of N integers.
Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

//Brute Force Approach
- Use two nested loops to count the frequency of each element
- If the frequency is greater than N/3, add the element to the result vector
- TC : O(N^2) SC : O(1)

//Better Approach
- Use a hash map to store the frequency of each element
- Iterate through the hash map and add elements with frequency greater than N/3 to the result vector
- TC : O(N) SC : O(N)

//Optimal Approach (Boyer-Moore Voting Algorithm)
- Since an element must appear more than N/3 times to be a valid answer, there can be at most 2 such elements
- Use two candidate variables and their corresponding counts to keep track of potential candidates
- First pass: Identify potential candidates
- Second pass: Verify the candidates by counting their occurrences
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return {};

    int candidate1 = -1, candidate2 = -1;
    int count1 = 0, count2 = 0;

    // First pass: Find potential candidates
    for (int num : nums)
    {
        if (num == candidate1)
        {
            count1++;
        }
        else if (num == candidate2)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            candidate1 = num;
            count1 = 1;
        }
        else if (count2 == 0)
        {
            candidate2 = num;
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    // Second pass: Verify the candidates
    count1 = 0;
    count2 = 0;

    for (int num : nums)
    {
        if (num == candidate1)
            count1++;
        else if (num == candidate2)
            count2++;
    }

    vector<int> result;
    if (count1 > n / 3)
        result.push_back(candidate1);
    if (count2 > n / 3)
        result.push_back(candidate2);

    return result;
}
