You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

- Observation:
    - odd even -> even odd => single element changes the pattern
    - In a sorted array where every element appears twice except for one, the pairs of elements will occupy even-odd index positions until the single element is encountered.
    - If the single element is on the left side of mid, the left side will have an odd number of elements, and the right side will have an even number of elements.
    - If the single element is on the right side of mid, the left side will have an even number of elements, and the right side will have an odd number of elements.
    - This property can be used to determine which side of the array to continue searching in.
    - If mid is even and nums[mid] == nums[mid + 1], the single element is on the right side.
    - If mid is odd and nums[mid] == nums[mid - 1], the single element is on the right side.
    - Otherwise, the single element is on the left side.
    - If mid is at the boundaries (0 or n-1), we need to handle those cases separately to avoid out-of-bound errors.
    - If the array has only one element, that element is the single element.
    - If the single element is at the start or end of the array, we can directly return it without further checks.

- Approach:
    1. Use binary search to find the single element.
    2. Check the mid index and its neighbors to determine which side to search next.
    3. Adjust the search boundaries based on the properties of the sorted array with pairs.
- TC : O(log N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();

        if(n==1){
            return arr[0];
        }
        if(arr[0]!=arr[1]){
            return arr[0];
        }
        if(arr[n-1]!=arr[n-2]){
            return arr[n-1];
        }

        int low = 1,high =n-2;
        while(low<=high){
            int mid = low+(high-low)/2;

            if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
                return arr[mid];
            }

            //we are in left half
            if((mid%2==1 && arr[mid]==arr[mid-1]) || (mid%2==0 && arr[mid]==arr[mid+1])){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return -1;
    }
};