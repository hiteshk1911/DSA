Given an integer array arr, find the contiguous subarray (containing at least one number) which
has the largest sum and returns its sum and prints the subarray.

//Brute Force Approach
- Generate all possible subarrays and calculate their sums
- Keep track of the maximum sum and the corresponding subarray
- TC : O(N^3) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> maxSubArrayBruteForce(vector<int> &arr) {
    int n = arr.size();
    int maxSum = INT_MIN;
    vector<int> maxSubarray;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int currentSum = 0;
            vector<int> currentSubarray;
            for (int k = i; k <= j; k++) {
                currentSum += arr[k];
                currentSubarray.push_back(arr[k]);
            }
            if (currentSum > maxSum) {
                maxSum = currentSum;
                maxSubarray = currentSubarray;
            }
        }
    }

    return {maxSum, maxSubarray};
}

//Better Approach
- Use prefix sums to calculate the sum of subarrays in O(1) time
- TC : O(N^2) SC : O(N)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> maxSubArrayBetter(vector<int> &arr) {
    int n = arr.size();
    vector<int> prefixSum(n + 1, 0);
    int maxSum = INT_MIN;
    vector<int> maxSubarray;

    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int currentSum = prefixSum[j + 1] - prefixSum[i];
            if (currentSum > maxSum) {
                maxSum = currentSum;
                maxSubarray = vector<int>(arr.begin() + i, arr.begin() + j + 1);
            }
        }
    }

    return {maxSum, maxSubarray};
}

//Better Approach(2) - Without Prefix Sum
- Use two nested loops to calculate the sum of subarrays
- TC : O(N^2) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> maxSubArrayBetter2(vector<int> &arr) {
    int n = arr.size();
    int maxSum = INT_MIN;
    vector<int> maxSubarray;

    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += arr[j];
            if (currentSum > maxSum) {
                maxSum = currentSum;
                maxSubarray = vector<int>(arr.begin() + i, arr.begin() + j + 1);
            }
        }
    }

    return {maxSum, maxSubarray};
}

//Optimal Approach (Kadane's Algorithm)
- Use a single loop to keep track of the current sum and maximum sum
- If the current sum becomes negative, reset it to zero
- Explanation Of tempStart, start and end variables:
    - tempStart is used to mark the potential starting index of a new subarray when the current sum drops below zero.
    - start and end are used to store the starting and ending indices of the maximum sum subarray found so far.
    - When we find a new maximum sum, we update start to tempStart (the beginning of the current subarray) and end to the current index i (the end of the current subarray).
    - This way, we can later extract the maximum sum subarray from the original array using these indices.
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> maxSubArrayOptimal(vector<int> &arr) {
    int n = arr.size();
    int maxSum = INT_MIN;
    int currentSum = 0;
    int start = 0, end = 0, tempStart = 0;

    for (int i = 0; i < n; i++) {
        currentSum += arr[i];

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }

        if (currentSum < 0) {
            currentSum = 0;
            tempStart = i + 1;
        }
    }

    vector<int> maxSubarray(arr.begin() + start, arr.begin() + end + 1);
    return {maxSum, maxSubarray};
}