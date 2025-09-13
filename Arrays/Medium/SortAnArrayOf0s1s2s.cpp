Given an array consisting of only 0s, 1s, and 2s.

//Brute Force Approach
- Sort the array using any sorting algorithm
- TC : O(N log N) SC : O(1)

//Better Approach
- Count the number of 0s, 1s, and 2s in the array
- Overwrite the array with the counted number of 0s, 1s, and 2s
- TC : O(N) SC : O(1)

//Optimal Approach (Dutch National Flag Algorithm)
- Use three pointers to keep track of the position of 0s, 1s, and 2s
- Iterate through the array and swap elements to their correct position based on the value
- NOTE: Take care of the mid pointer when swapping with high pointer
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &arr)
{
    int n = arr.size();
    int low = 0;        // Pointer for the next position of 0
    int mid = 0;        // Current element under consideration
    int high = n - 1;   // Pointer for the next position of 2

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low++], arr[mid++]); // Swap 0 to the front
        }
        else if (arr[mid] == 1)
        {
            mid++; // Move to the next element
        }
        else // arr[mid] == 2
        {
            swap(arr[mid], arr[high--]); // Swap 2 to the end
        }
    }
}