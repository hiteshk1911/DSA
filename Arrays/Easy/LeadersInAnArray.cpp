Given an array, print all the elements which are leaders.
A Leader is an element that is greater than all of the elements on its right side in the array.

//Brute Force Approach
- For each element, check all the elements to its right to see if it is a leader
- TC : O(N^2) ; SC : O(1)

//Optimal Approach
- Traverse the array from right to left, keeping track of the maximum element seen so far
- If the current element is greater than the maximum element, it is a leader
- TC : O(N) ; SC : O(1)
- CPP Code :

#include <bits/stdc++.h>
using namespace std;

vector<int> findLeaders(vector<int> &arr) {
    int n = arr.size();
    vector<int> leaders;
    int maxFromRight = INT_MIN;

    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > maxFromRight) {
            leaders.push_back(arr[i]);
            maxFromRight = arr[i];
        }
    }

    reverse(leaders.begin(), leaders.end()); // To maintain the order of leaders as in the original array
    return leaders;
}