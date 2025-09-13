//Better Approach
- Count the number of zeroes in the array
- Shift the non-zero elements to the front of the array
- Fill the remaining positions with zeroes
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

void moveZeroesToEnd(vector<int> &arr)
{
    int n = arr.size();
    int count = 0; // Count of non-zero elements

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[count++] = arr[i]; // Move non-zero element to the front
        }
    }

    // Fill remaining positions with zeroes
    while (count < n)
    {
        arr[count++] = 0;
    }
}

//Optimal Approach
- Use two pointers to keep track of the position of non-zero elements
- Iterate through the array and whenever a non-zero element is found, swap it with the element at the non-zero pointer and move the pointer forward
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

void moveZeroesToEnd(vector<int> &arr)
{
    int n = arr.size();
    int nonZeroIndex = 0; // Pointer for the position of non-zero elements

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[nonZeroIndex++]); // Swap non-zero element to the front
        }
    }
}