Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

//Solution 1
 class Solution {
 public:
     int numSubarraysWithSum(vector<int>& nums, int goal) {
         unordered_map<int,int> prefixCount;
         prefixCount[0] = 1; // empty prefix

         int curSum = 0, count = 0;
         for(int num : nums){
             curSum += num;
             if(prefixCount.find(curSum - goal) != prefixCount.end()){
                 count += prefixCount[curSum - goal];
             }
             prefixCount[curSum]++;
         }
         return count;
     }
 };

//Solution 2
class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int left = 0, sum = 0, count = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum > goal) {
                sum -= nums[left++];
            }
            count += (right - left + 1);
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};
