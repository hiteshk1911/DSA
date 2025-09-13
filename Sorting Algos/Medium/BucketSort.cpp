//Bucket Sort Algorithm
- How it works:
 1. Create a number of empty "buckets" (sub-arrays).
 2. Distribute the elements of the input array into these buckets based on a certain criterion (e.g., range of values).
 3. Sort each bucket individually using a different sorting algorithm (like insertion sort or quicksort).
 4. Concatenate all the sorted buckets to get the final sorted array.
- The bucket sort algorithm is particularly useful when the input is uniformly distributed over a range.
- Time Complexity: O(N + K) on average, where N is the number of elements in the input array and K is the number of buckets. In the worst case, it can degrade to O(N^2) if all elements are placed in a single bucket.
- Space Complexity: O(N + K) due to the additional space required for the buckets.
- Stable: Yes, if the sorting algorithm used for individual buckets is stable.
- Adaptive: No, it does not take advantage of existing order in the array.
- Code CPP:

#include <bits/stdc++.h>
using namespace std;

void bucketSort(vector<float> &arr)
{
    int n = arr.size();
    if (n <= 0)
        return;

    // Create n empty buckets
    vector<vector<float>> buckets(n);

    // Distribute input array values into buckets
    for (int i = 0; i < n; i++)
    {
        int bucketIndex = n * arr[i]; // Assuming arr[i] is in the range [0, 1)
        if (bucketIndex >= n)          // Handle the case when arr[i] is 1
            bucketIndex = n - 1;
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort individual buckets and concatenate
    arr.clear(); // Clear the original array to store sorted elements
    for (int i = 0; i < n; i++)
    {
        sort(buckets[i].begin(), buckets[i].end()); // You can use any sorting algorithm here
        arr.insert(arr.end(), buckets[i].begin(), buckets[i].end());
    }
}
// Note: This implementation assumes that the input array contains floating-point numbers in the range [0, 1).
// If the input array contains integers or numbers in a different range, you may need to adjust the bucket index calculation accordingly.