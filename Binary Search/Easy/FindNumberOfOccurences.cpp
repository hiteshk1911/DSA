 You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.

- If X is not present in the array, return 0.
- If X is smaller than all elements in the array, return 0.
- First And Last Occurence Approach
- TC : O(log N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;
    int result = -1; // To store the index of the first occurrence

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // To avoid overflow

        if (arr[mid] == target)
        {
            result = mid;    // Update result
            right = mid - 1; // Search in the left half to find the first occurrence
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
    return result; // Return the index of the first occurrence or -1 if not found
}
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
int countOccurrences(vector<int> &arr, int x)
{
    int first = firstOccurence(arr, x);
    if (first == -1)
        return 0; // x is not present in the array

    int last = lastOccurence(arr, x);

    return last - first + 1; // Number of occurrences
}