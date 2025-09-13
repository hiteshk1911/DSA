Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array.
You may consider that such an element always exists in the array.

//Brute Force Approach
- Use a hash map to store the frequency of each element
- Traverse the array and update the frequency of each element in the hash map
- Return the element with frequency greater than N/2
- TC : O(N) SC : O(N)

//Optimal Approach (Boyer-Moore Voting Algorithm)
- Initialize two variables: candidate and count
- Traverse the array and update the candidate and count based on the current element
- If count is 0, set the candidate to the current element and set count to 1
- If the current element is equal to the candidate, increment count
- If the current element is not equal to the candidate, decrement count
- After the first pass, the candidate will be the majority element
- NOTE: Since the problem guarantees that a majority element always exists, we do not need a second pass to verify the candidate .
        Otherwise, we would need to count the occurrences of the candidate in a second pass to confirm it appears more than N/2 times.
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &arr) {
    int candidate = -1;
    int count = 0;

    for (int num : arr) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    return candidate;
}