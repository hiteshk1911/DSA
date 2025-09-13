//Bubble Sort Algorithm
- Repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.
- The pass through the list is repeated until the list is sorted.
- Time Complexity: O(N^2) in the worst and average case, O(N) in the best case (when the array is already sorted).
- Space Complexity: O(1) as it is an in-place sorting algorithm.
- Stable: Yes, it maintains the relative order of records with equal keys.
- Adaptive: Yes, it can be optimized to stop early if the array is already sorted.

- Code CPP:

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++)
    {
        swapped = false; // To optimize the algorithm if the array is already sorted

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true; // A swap occurred
            }
        }

        // If no two elements were swapped in the inner loop, then the array is already sorted
        if (!swapped)
            break;
    }
}
