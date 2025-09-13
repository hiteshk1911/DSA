//Cycle Sort Algorithm
- How it works:
  1. Traverse the array to find the correct position of each element.
  2. If the element is not in its correct position, swap it with the element at its correct position.
  3. Repeat the process until all elements are in their correct positions.
- The cycle sort algorithm is based on the idea of minimizing the number of writes to the array.
- Time Complexity: O(N^2) in all cases (worst, average, and best) because of the nested loops.
- Space Complexity: O(1) as it is an in-place sorting algorithm.
- Stable: No, it does not maintain the relative order of records with equal keys.
- Adaptive: No, it does not take advantage of existing order in the array.
- Code CPP:

#include <bits/stdc++.h>
using namespace std;

void cycleSort(vector<int> &arr)
{
    int n = arr.size();

    for (int cycleStart = 0; cycleStart < n - 1; cycleStart++)
    {
        int item = arr[cycleStart];
        int pos = cycleStart;

        // Find the position where we put the element
        for (int i = cycleStart + 1; i < n; i++)
        {
            if (arr[i] < item)
            {
                pos++;
            }
        }

        // If the element is already in the correct position
        if (pos == cycleStart)
            continue;

        // Skip duplicates
        while (item == arr[pos])
        {
            pos++;
        }

        // Put the element to its correct position
        if (pos != cycleStart)
        {
            swap(item, arr[pos]);
        }

        // Rotate the rest of the cycle
        while (pos != cycleStart)
        {
            pos = cycleStart;

            // Find the position where we put the element
            for (int i = cycleStart + 1; i < n; i++)
            {
                if (arr[i] < item)
                {
                    pos++;
                }
            }

            // Skip duplicates
            while (item == arr[pos])
            {
                pos++;
            }

            // Put the element to its correct position
            if (item != arr[pos])
            {
                swap(item, arr[pos]);
            }
        }
    }
}