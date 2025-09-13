//Linear Search in C++
- Traversing the array from start to end and checking each element
- If the element is found, return its index
- If the element is not found, return -1
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> &arr, int target)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i; // Element found at index i
        }
    }
    return -1; // Element not found
}
