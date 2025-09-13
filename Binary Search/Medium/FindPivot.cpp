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
