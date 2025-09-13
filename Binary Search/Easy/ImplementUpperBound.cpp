Given a sorted array of N integers and an integer x, write a program to find the upper bound of x.

- The upper bound of x is the first position where an element greater than x can be inserted in the array without violating the order.
- If x is present in the array, return the index of the first element greater than x.
- If x is not present in the array, return the index where it can be inserted to maintain the sorted order.
- If x is greater than or equal to all elements in the array, return N (the size of the array).
- If x is smaller than all elements in the array, return 0.
- TC : O(log N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x)
{
    int left = 0;
    int right = arr.size(); // right is set to size of array to handle case when x is greater than or equal to all elements

    while (left < right)
    {
        int mid = left + (right - left) / 2; // To avoid overflow

        if (arr[mid] <= x) // Why equal to? Because we want the first element greater than x
        {
            left = mid + 1; // Search in the right half
        }
        else
        {
            right = mid; // Search in the left half including mid
        }
    }
    return left; // left is the position where an element greater than x can be inserted
}