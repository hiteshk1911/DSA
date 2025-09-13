You are given a sorted array arr of distinct values and a target value x. You need to search for the index of the target value in the array.
If the value is present in the array, then return its index. Otherwise, determine the index where it would be inserted in the array while maintaining the sorted order.

- If x is greater than all elements in the array, return N (the size of the array).
- If x is smaller than all elements in the array, return 0.
- TC : O(log N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &arr, int x)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // To avoid overflow

        if (arr[mid] == x)
        {
            return mid; // Element found at index mid
        }
        else if (arr[mid] < x)
        {
            left = mid + 1; // Search in the right half
        }
        else
        {
            right = mid - 1; // Search in the left half
        }
    }
    return left; // left is the position where x can be inserted
}