You're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
The floor of x is the largest element in the array which is smaller than or equal to x.
The ceiling of x is the smallest element in the array greater than or equal to x.

- If the floor or ceiling does not exist, return -1 for that value.
- TC : O(log N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

pair<int, int> findFloorAndCeil(vector<int> &arr, int x)
{
    int n = arr.size();
    int left = 0;
    int right = n - 1;
    int floor = -1;
    int ceil = -1;

    // Finding Floor
    while (left <= right)
    {
        int mid = left + (right - left) / 2; // To avoid overflow

        if (arr[mid] == x)
        {
            floor = arr[mid];
            break; // Element found at index mid
        }
        else if (arr[mid] < x)
        {
            floor = arr[mid]; // Update floor
            left = mid + 1;  // Search in the right half
        }
        else
        {
            right = mid - 1; // Search in the left half
        }
    }

    left = 0;
    right = n - 1;

    // Finding Ceil
    while (left <= right)
    {
        int mid = left + (right - left) / 2; // To avoid overflow

        if (arr[mid] == x)
        {
            ceil = arr[mid];
            break; // Element found at index mid
        }
        else if (arr[mid] < x)
        {
            left = mid + 1; // Search in the right half
        }
        else
        {
            ceil = arr[mid]; // Update ceil
            right = mid - 1; // Search in the left half
        }
    }

    return {floor, ceil};
}