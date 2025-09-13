//Insertion Sort Algorithm
- How it works:
  1. Start from the second element (index 1) of the array.
  2. Compare the current element (key) with the elements in the sorted portion (to its left).
  3. Shift all elements in the sorted portion that are greater than the key to one position to the right.
  4. Insert the key into its correct position in the sorted portion.
  5. Repeat until the entire array is sorted.
- The insertion sort algorithm builds the final sorted array one item at a time.
- It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.
- Time Complexity: O(N^2) in the worst and average case, O(N) in the best case (when the array is already sorted).
- Space Complexity: O(1) as it is an in-place sorting algorithm.
- Stable: Yes, it maintains the relative order of records with equal keys.
- Adaptive: Yes, it can be optimized to take advantage of existing order in the array.
- Code CPP:

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Place the key in its correct position
    }
}