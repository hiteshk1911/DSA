You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.



Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2


Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].

//Brute Force
- Recursive Approach

//DP Solution
class Solution {
    int helper(vector<int>& nums, int index, int n, vector<int>& dp) {
        if (index >= n - 1) return 0;              // reached or passed end
        if (dp[index] != -1) return dp[index];     // already computed

        int k = nums[index];
        int mini = INT_MAX;

        for (int i = 1; i <= k; i++) {
            if (index + i < n) {
                int next = helper(nums, index + i, n, dp);
                if (next != INT_MAX) {             // only add if valid
                    mini = min(mini, 1 + next);
                }
            }
        }

        return dp[index] = mini;
    }

public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = helper(nums, 0, n, dp);
        return ans == INT_MAX ? 0 : ans;
    }
};

//Greedy Approach
🚀 Intuition

We don’t need to explore all paths.
We just track:

The current range we can reach (currentEnd)

The farthest point we can reach so far (farthest)

When we reach the end of the current range, we must jump, and we update currentEnd to farthest.

✅ Greedy Code
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0;
        int farthest = 0;
        int currentEnd = 0;

        for (int i = 0; i < n - 1; i++) {
            // find the farthest reachable index from this range
            farthest = max(farthest, i + nums[i]);

            // if we've reached the end of the current range,
            // we need to make a jump
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};

🧠 Complexity
Type	Value
Time	O(n)
Space	O(1)

//Greedy Striver
- TC: O(n^2) -> worst case
class Solution {

public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, l = 0, r = 0;

        while(r<n-1){
            int farthest = 0;
            for(int i=l;i<=r;i++){
                farthest = max(farthest, i+nums[i]);
            }

            jumps++;
            l = r+1;
            r= farthest;
        }

        return jumps;
    }
};
