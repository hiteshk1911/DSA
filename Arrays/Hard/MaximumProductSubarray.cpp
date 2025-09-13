Given an array that contains both negative and positive integers, find the maximum product subarray.

//Brute Force Approach
- Use three nested loops to check all possible subarrays and calculate their products
- Keep track of the maximum product found
- TC : O(N^3) SC : O(1)

//Better Approach(1)
- Use two nested loops to check all possible subarrays and calculate their products
- Keep track of the maximum product found
- TC : O(N^2) SC : O(1)

//Better Approach(2)
- Traverse the array while keeping track of the maximum and minimum products ending at the current position
- Update the maximum product found so far
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int maxProductSubarray(vector<int> &arr)
{
    int n = arr.size();
    int maxProduct = arr[0];
    int currentMax = arr[0];
    int currentMin = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap(currentMax, currentMin); // Swap when a negative number is encountered
        }

        currentMax = max(arr[i], currentMax * arr[i]);
        currentMin = min(arr[i], currentMin * arr[i]);

        maxProduct = max(maxProduct, currentMax);
    }

    return maxProduct;
}

//Better Approach(3)
- Traverse the array twice, once from left to right and once from right to left
- Keep track of the maximum product found in both traversals
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int maxProductSubarray(vector<int> &arr)
{
    int n = arr.size();
    int maxProduct = arr[0];
    int product = 1;

    // Traverse from left to right
    for (int i = 0; i < n; i++)
    {
        product *= arr[i];
        maxProduct = max(maxProduct, product);
        if (product == 0)
            product = 1; // Reset product when a zero is encountered
    }

    product = 1; // Reset product for the next traversal

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        product *= arr[i];
        maxProduct = max(maxProduct, product);
        if (product == 0)
            product = 1; // Reset product when a zero is encountered
    }

    return maxProduct;
}

//Optimal Approach - Striver's Observation
- Prefix and Suffix Product Method
- Traverse the array while keeping track of the prefix and suffix products
- Update the maximum product found so far
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int maxProductSubarray(vector<int> &arr)
{
    int n = arr.size();
    int maxProduct = INT_MIN;
    int prefixProduct = 1;
    int suffixProduct = 1;

    for (int i = 0; i < n; i++)
    {
        prefixProduct *= arr[i];
        suffixProduct *= arr[n - 1 - i];

        maxProduct = max(maxProduct, max(prefixProduct, suffixProduct));

        if (prefixProduct == 0)
            prefixProduct = 1; // Reset prefix product when a zero is encountered
        if (suffixProduct == 0)
            suffixProduct = 1; // Reset suffix product when a zero is encountered
    }

    return maxProduct;
}