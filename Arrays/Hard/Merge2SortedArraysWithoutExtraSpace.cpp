Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order.
Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

//Brute Force Approach
- Use a temporary array to store the merged elements
- Sort the temporary array
- Copy the first N elements to arr1 and the last M elements to arr2
- TC : O((N+M) log(N+M)) SC : O(N+M)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

void mergeSortedArrays(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    vector<int> temp(n + m);
    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            temp[k++] = arr1[i++];
        }
        else
        {
            temp[k++] = arr2[j++];
        }
    }

    while (i < n)
    {
        temp[k++] = arr1[i++];
    }

    while (j < m)
    {
        temp[k++] = arr2[j++];
    }

    for (i = 0; i < n; i++)
    {
        arr1[i] = temp[i];
    }

    for (j = 0; j < m; j++)
    {
        arr2[j] = temp[n + j];
    }
}

//Optimal Approach(1) - Two Pointer from End
- Use two pointers to traverse both arrays from the end
- Compare the elements and place the larger element at the end of arr1 or arr2
- TC : O(N+M) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

void mergeSortedArrays(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    int i = n - 1, j = m - 1, k = n + m - 1;

    // Resize arr1 to hold elements of both arrays
    arr1.resize(n + m);

    while (i >= 0 && j >= 0)
    {
        if (arr1[i] > arr2[j])
        {
            arr1[k--] = arr1[i--];
        }
        else
        {
            arr1[k--] = arr2[j--];
        }
    }

    while (j >= 0)
    {
        arr1[k--] = arr2[j--];
    }

    // Copy the first N elements back to arr2
    for (int idx = 0; idx < m; idx++)
    {
        arr2[idx] = arr1[n + idx];
    }

    // Resize arr1 to original size
    arr1.resize(n);
}

//Optimal Approach(2) - Gap Method
- Use the gap method to compare and swap elements in both arrays
- Start with a gap of (n+m)/2 and reduce it to 1
- Compare elements at index i and i+gap in arr1 and arr2 and swap if they are out of order
- TC : O((N+M) log(N+M)) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

void mergeSortedArrays(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    int gap = (n + m + 1) / 2; // Initial gap

    while (gap > 0)
    {
        int i = 0, j = gap;

        while (j < n + m)
        {
            // Compare elements in arr1
            if (i < n && j < n)
            {
                if (arr1[i] > arr1[j])
                {
                    swap(arr1[i], arr1[j]);
                }
            }
            // Compare elements between arr1 and arr2
            else if (i < n && j >= n)
            {
                if (arr1[i] > arr2[j - n])
                {
                    swap(arr1[i], arr2[j - n]);
                }
            }
            // Compare elements in arr2
            else if (i >= n && j >= n)
            {
                if (arr2[i - n] > arr2[j - n])
                {
                    swap(arr2[i - n], arr2[j - n]);
                }
            }

            i++;
            j++;
        }

        if (gap == 1)
            break;
        gap = (gap + 1) / 2; // Reduce the gap
    }
}