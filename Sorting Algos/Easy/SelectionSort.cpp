//Selection Sort Algorithm
- How it works:
    1. Start from the first element (index 0) of the array.
    2. Assume the first element is the minimum and store its index.
    3. Compare this minimum with the rest of the elements in the array to find the actual minimum element.
    4. If a smaller element is found, update the index of the minimum element.
    5. After completing the inner loop, swap the found minimum element with the first element of the unsorted portion of the array.
    6. Move the boundary of the unsorted portion one element to the right.
- The selection sort algorithm divides the input list into two parts:
    a sorted sublist of items which is built up from left to right at the front (left) of the list and a sublist of the remaining unsorted items that occupy the rest of the list.
- Initially, the sorted sublist is empty and the unsorted sublist is the entire input list.
- The algorithm proceeds by finding the smallest (or largest, depending on sorting order) element in the unsorted sublist, swapping it with the leftmost unsorted element (putting it in sorted order), and moving the sublist boundaries one element to the right.
- Time Complexity: O(N^2) in all cases (worst, average, and best) because of the nested loops.
- Space Complexity: O(1) as it is an in-place sorting algorithm.
- Stable: No, it does not maintain the relative order of records with equal keys.
- Adaptive: No, it does not take advantage of existing order in the array.
- Code CPP:

#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i; // Assume the minimum is the first element of the unsorted part

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j; // Update minIndex if a smaller element is found
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
        }
    }
}