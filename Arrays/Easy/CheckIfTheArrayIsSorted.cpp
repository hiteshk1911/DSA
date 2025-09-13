//Brute Force Approach
- Compare each element with all other elements
- TC : O(N^2) ; SC : O(1)

//Optimal Approach
- Traverse the array & check if each element is less than or equal to the next element
- TC : O(N) ; SC : O(1)
- CPP Code :

#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}
