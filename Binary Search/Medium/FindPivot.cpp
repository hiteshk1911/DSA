Find minimum/pivot in rotated sorted array

-CPP Code:

#include<bits/stdc++.h>
using namespace std;

int findPivotIndex(vector<int>& nums) {
        int start=0,end=nums.size()-1,mid=start+(end-start)/2;

        if(nums[start]<nums[end]){
            return nums[start];
        }
        while(start<end){
            if(nums[mid]>=nums[0]){
                start=mid+1;
            }else{
                end=mid;
            }
            mid=start+(end-start)/2;
        }

        return start;
}

//better approach - also helps in case of duplicates
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            // If mid element is greater than end,
            // the min is in the right half
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            }
            // Otherwise, min is in the left half (including mid)
            else {
                end = mid;
            }
        }

        return nums[start];
    }
};
