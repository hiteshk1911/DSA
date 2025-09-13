Given a sorted array of N integers, write a program to find the index of the last occurrence of the target key.
If the target is not found then return -1.

- If the target is greater than all elements in the array, return -1.
- If the target is smaller than all elements in the array, return -1.
- TC : O(log N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int lastOccurence(vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;
    int result = -1; // To store the index of the last occurrence

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // To avoid overflow

        if (arr[mid] == target)
        {
            result = mid;   // Update result
            left = mid + 1; // Search in the right half to find the last occurrence
        }
        else if (arr[mid] < target)
        {
            left = mid + 1; // Search in the right half
        }
        else
        {
            right = mid - 1; // Search in the left half
        }
    }
    return result; // Return the index of the last occurrence or -1 if not found
}