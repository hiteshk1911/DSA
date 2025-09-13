//Heap Sort Algorithm
- How it works:
  1. Build a max heap from the input array.
  2. The largest element (the root of the heap) is at the first position of the array.
  3. Swap it with the last element of the array and reduce the size of the heap by one.
  4. Heapify the root of the tree to maintain the max heap property.
  5. Repeat steps 2-4 until the size of the heap is greater than one.
- The heap sort algorithm is an in-place sorting algorithm but not a stable sort.
- Time Complexity: O(N log N) in all cases (worst, average, and best) because building the heap takes O(N) time and each of the N elements is extracted from the heap in O(log N) time.
- Space Complexity: O(1) as it is an in-place sorting algorithm.
- Stable: No, it does not maintain the relative order of records with equal keys.
- Adaptive: No, it does not take advantage of existing order in the array.
- Code CPP:

#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1; // left child index
    int right = 2 * i + 2; // right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]); // Swap root with largest

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
void heapSort(vector<int> &arr)
{
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
