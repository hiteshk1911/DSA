A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

//Brute Force Approach
- Traverse the array and check if the current element is greater than its neighbors
- If yes, return the index of the current element
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return 0;
    if(nums[0]>nums[1]) return 0;
    if(nums[n-1]>nums[n-2]) return n-1;

    for(int i=1;i<n-1;i++){
        if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
            return i;
        }
    }

    return -1;
}
//Optimal Approach
- Use binary search to find the peak element
- Compare the middle element with its neighbors to determine the direction of the peak
- If the middle element is greater than its right neighbor, the peak lies on the left side (including mid)
- If the middle element is less than its right neighbor, the peak lies on the right side
- TC : O(log N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
        int n=nums.size();

        int low=0,high=n-1;

        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]<=nums[mid+1]){
                low= mid+1;
            }else{
                high=mid;
            }
        }

        return low;
}