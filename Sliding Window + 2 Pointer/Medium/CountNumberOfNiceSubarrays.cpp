Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.



Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16

//Brute Force
- Find all the subarrays with at most k odd numbers and subtract from it the subarrays with at most k-1 odd numbers

//Better Approach

class Solution {
    int atMostKOdd(vector<int>& nums, int k){
        int n = nums.size();
        int left = 0,right = 0,countOdd = 0,ans = 0;

        while(right<n){
            if(nums[right]&1){
                countOdd++;
            }

            while(countOdd>k){
                if(nums[left]&1){
                    countOdd--;
                }
                left++;
            }

            ans = ans + (right-left+1);
            right++;
        }
        return ans;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostKOdd(nums,k)-atMostKOdd(nums,k-1);
    }
};

//Optimal Approach
- prefixEven - count of even numbers before the first odd number in the current window
- Working of prefixEven:
    - When we encounter an odd number, we reset prefixEven to 0.
    - When we encounter an even number, we increment prefixEven by 1.
    - When we have exactly k odd numbers in the window, the number of nice subarrays that can be formed with the current window is equal to prefixEven + 1 (the +1 accounts for the subarray that starts right after the last odd number).

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0, countOdd = 0, ans = 0, prefixEven = 0;

        while (right < n) {
            if (nums[right] % 2 == 1) {
                countOdd++;
                prefixEven = 0;  // reset when we add a new odd
            }

            while (countOdd == k) {
                if (nums[left] % 2 == 1) countOdd--;
                left++;
                prefixEven++;
            }

            ans += prefixEven;
            right++;
        }

        return ans;
    }
};