 Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.

- You may assume no duplicate exists in the array.
- Approach:
    1. Find the pivot point where the array is rotated.
    2. If the pivot point is -1, it means the array is not rotated. Perform a standard binary search on the entire array.
    3. If the pivot point is found, check if the target is at the pivot point. If yes, return the pivot index.
    4. If the target is greater than or equal to the first element of the array, perform a binary search on the left subarray (from start to pivot-1).
    5. If the target is less than the first element of the array, perform a binary search on the right subarray (from pivot+1 to end).
- TC : O(log N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums,int target,int low ,int high){

       while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return -1;
}
int search(vector<int>& nums, int target) {
        int n=nums.size();

        int low=0,high=n-1;

        //find pivot index
        int pivot=-1;
        while(low<high){
            int mid=low+(high-low)/2;

            if(nums[mid]>=nums[0]){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        pivot=low;

        //apply bs
        if(nums[pivot]<=target && target<=nums[n-1]){
            return binarySearch( nums,target,pivot,n-1);
        }else{
            return binarySearch( nums,target,0,pivot-1);
        }
}