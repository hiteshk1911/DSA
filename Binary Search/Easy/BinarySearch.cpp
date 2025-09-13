//Binary Search
- Searching in a sorted array by repeatedly dividing the search interval in half
- TC: O(log N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // To avoid overflow

        if (arr[mid] == target)
        {
            return mid; // Element found at index mid
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
    return -1; // Element not found
}