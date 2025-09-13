//Merge Sort Algorithm
- How it works:
  1. Divide the unsorted array into n subarrays, each containing one element (a list of one element is considered sorted).
  2. Repeatedly merge subarrays to produce new sorted subarrays until there is only one subarray remaining. This will be the sorted array.
- The merge sort algorithm follows the divide-and-conquer paradigm.
- Time Complexity: O(N log N) in all cases (worst, average, and best) because the array is repeatedly divided in half (log N divisions) and each division requires a linear amount of time to merge (N).
- Space Complexity: O(N) as it requires additional space for the temporary arrays used during the merge process.
- Stable: Yes, it maintains the relative order of records with equal keys.
- Adaptive: No, it does not take advantage of existing order in the array.
- Code CPP:

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray

    vector<int> L(n1); // Temporary array for left subarray
    vector<int> R(n2); // Temporary array for right subarray

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;   // Initial index of the first subarray
    int j = 0;   // Initial index of the second subarray
    int k = left; // Initial index of the merged subarray

    // Merge the temporary arrays back into arr[left..right]
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // Find the middle point to divide the array into two halves

        mergeSort(arr, left, mid);       // Sort the first half
        mergeSort(arr, mid + 1, right);  // Sort the second half
        merge(arr, left, mid, right);    // Merge the sorted halves
    }
}