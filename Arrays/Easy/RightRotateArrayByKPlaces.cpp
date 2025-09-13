//Brute Force Approach
- Rotate the array k times by shifting elements one by one
- TC : O(N*K) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

void rightRotate(vector<int> &arr, int k)
{
    int n = arr.size();
    k = k % n; // In case k is greater than n

    for (int i = 0; i < k; i++)
    {
        int last = arr[n - 1];
        for (int j = n - 1; j > 0; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[0] = last;
    }
}


//Better Approach(1)
- Use a temporary array to store the array elements
- Use the formula (i + k) % n to place elements in the correct position
- TC : O(N) SC : O(N)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

void rightRotate(vector<int> &arr, int k)
{
    int n = arr.size();
    k = k % n; // In case k is greater than n
    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

//Better Approach(2)
- Use a temporary array to store the last k elements
- Shift the remaining elements to the right by k positions
- Copy the elements from the temporary array to the start of the original array
- TC : O(N) SC : O(K)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

void rightRotate(vector<int> &arr, int k)
{
    int n = arr.size();
    k = k % n; // In case k is greater than n
    vector<int> temp(k);

    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[n - k + i];
    }

    for (int i = n - 1; i >= k; i--)
    {
        arr[i] = arr[i - k];
    }

    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }
}

//Optimal Approach (1)
- Reverse the entire array
- Reverse the first k elements
- Reverse the remaining n-k elements
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
void rightRotate(vector<int> &arr, int k)
{
    int n = arr.size();
    if(n == 0) return;

    k = k % n; // In case k is greater than n

    reverse(arr, 0, n - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
}