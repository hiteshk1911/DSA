- With duplicates allowed

- Explanation: This code implements a modified binary search algorithm to find a target value in a rotated sorted array that may contain duplicates.
               The algorithm handles the presence of duplicates by adjusting the search boundaries when necessary.
- Time Complexity: O(log n) in average case, O(n) in worst case


#include<bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int k) {
         int low =0, high = nums.size()-1;

        while(low<=high){

            int mid = low + (high-low)/2;

            if(nums[mid]==k) return true;

            if(nums[low]==nums[mid]&& nums[mid]==nums[high]) { // Handling duplicates -> How ? If low, mid, and high are equal, we cannot determine which side is sorted, so we shrink the search space by moving both pointers inward.
                low++;
                high--;
                continue;
            }

            else if (nums[low]<= nums[mid]){

                if(k>=nums[low] && k<= nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{

                if(k>=nums[mid] && k<=nums[high]){
                    low= mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return false;
}