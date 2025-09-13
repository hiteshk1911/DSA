Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated.

- If the array is not rotated, return 0.
- Approach:
    1. Find the pivot point where the array is rotated.
    2. The number of rotations is equal to the index of the pivot point.
- TC : O(log N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int findRotationCount(vector<int>& nums) {
        int n=nums.size();

        int low=0,high=n-1;

        //find pivot index
        int pivot=-1;
        if(nums[low]<nums[high]) return 0; //array is not rotated
        while(low<high){
            int mid=low+(high-low)/2;

            if(nums[mid]>=nums[0]){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        pivot=low;

        return pivot;
}