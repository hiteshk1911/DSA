Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

//Complexity Analysis:
TC: O(n)
SC: O(1)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
          int left = 0, max_length = 0, zero_count = 0;

        for (int right = 0; right < nums.size(); right++) {
            // Count the zeros in the current window
            if (nums[right] == 0) {
                zero_count++;
            }

            // If zeros exceed k, shrink the window from the left
            while (zero_count > k) {
                if (nums[left] == 0) {
                    zero_count--;
                }
                left++;
            }

            // Calculate the maximum length of the window
            max_length = max(max_length, right - left + 1);
        }

        return max_length;

    }
};