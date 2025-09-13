//Brute Force Approach
- Sort the array & return the second last element
- TC : O(N log N) ; SC : O(1)

//Opimal Approach
- Traverse the array & keep track of the maximum & second maximum element
- TC : O(N) ; SC : O(1)
- CPP Code :

#include <bits/stdc++.h>
using namespace std;

int secondLargest(int arr[], int n) {
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) { // to handle duplicate largest elements
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}
