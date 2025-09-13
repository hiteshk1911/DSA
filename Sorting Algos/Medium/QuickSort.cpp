//Quick Sort Algorithm
- How it works:
  1. Choose a 'pivot' element from the array.
  2. Partition the array into two sub-arrays:
     - Elements less than the pivot
     - Elements greater than the pivot
  3. Recursively apply the above steps to the sub-arrays.
- The base case for the recursion is when the array has one or zero elements, which are inherently sorted.
- Time Complexity: O(N log N) on average, O(N^2) in the worst case (when the smallest or largest element is always chosen as the pivot).
- Space Complexity: O(log N) due to the recursive stack space.
- Stable: No, it does not maintain the relative order of records with equal keys.
- Adaptive: No, it does not take advantage of existing order in the array.
- Code CPP:

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1;      // Pointer for the smaller element

    for (int j = low; j < high; j++)
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Place the pivot in the correct position
    return i + 1;                // Return the index of the pivot
}
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
