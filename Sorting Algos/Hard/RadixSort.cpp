//Radix Sort Algorithm
- How it works:
  1. Find the maximum number to know the number of digits.
  2. Do counting sort for every digit. The digit is represented by exp (10^i where i is the current digit number).
- The radix sort algorithm processes each digit of the numbers starting from the least significant digit to the most significant digit.
- Time Complexity: O(d * (N + k)) where d is the number of digits in the maximum number, N is the number of elements in the array, and k is the range of the input (for decimal numbers, k is 10).
- Space Complexity: O(N + k) due to the additional space required for the output array and count array used in counting sort.
- Stable: Yes, it maintains the relative order of records with equal keys.
- Adaptive: No, it does not take advantage of existing order in the array.
- Code CPP:

#include <bits/stdc++.h>
using namespace std;

int getMax(const vector<int> &arr)
{
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}
void countingSort(vector<int> &arr, int exp)
{
    int n = arr.size();
    vector<int> output(n); // Output array
    int count[10] = {0};   // Count array for digits (0-9)

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that it now contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to the current digit
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}
void radixSort(vector<int> &arr)
{
    // Find the maximum number to know the number of digits
    int maxVal = getMax(arr);

    // Do counting sort for every digit. exp is 10^i where i is the current digit number
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
    {
        countingSort(arr, exp);
    }
}

