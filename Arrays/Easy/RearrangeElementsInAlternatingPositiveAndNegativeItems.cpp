There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements.
Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.
Note: Start the array with positive elements.

//Brute Force Approach
- Use extra space to store positive and negative elements separately
- Merge the two arrays by alternating elements from each
- TC : O(N) SC : O(N)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &arr) {
    int n = arr.size();
    vector<int> positive;
    vector<int> negative;
    vector<int> result;

    // Separate positive and negative elements
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            positive.push_back(arr[i]);
        } else {
            negative.push_back(arr[i]);
        }
    }

    // Merge the two arrays by alternating elements
    for (int i = 0; i < n / 2; i++) {
        result.push_back(positive[i]);
        result.push_back(negative[i]);
    }

    return result;
}

//Optimal Approach
- Use two pointers to keep track of the position of positive and negative elements
- Iterate through the array and whenever a positive element is found, swap it with the element at the positive pointer and move the pointer forward
- Do the same for negative elements
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &arr) {
    int n = arr.size();
    vector<int> result(n);
    int posIndex = 0; // Pointer for positive elements
    int negIndex = 1; // Pointer for negative elements

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            result[posIndex] = arr[i];
            posIndex += 2; // Move to the next even index
        } else {
            result[negIndex] = arr[i];
            negIndex += 2; // Move to the next odd index
        }
    }

    return result;
}