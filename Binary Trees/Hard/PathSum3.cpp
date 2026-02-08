Leetcode 437:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//TC -> O(n2) worst , SC -> O(h)
class Solution {
public:
    void helper(TreeNode* root, int k, int &count, vector<long long>& v) {
        if (!root) return;

        v.push_back(root->val);

        long long sum = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            sum += v[i];
            if (sum == k)
                count++;
        }

        helper(root->left, k, count, v);
        helper(root->right, k, count, v);

        v.pop_back(); // backtrack
    }

    int pathSum(TreeNode* root, int k) {
        int count = 0;
        vector<long long> v;
        helper(root, k, count, v);
        return count;
    }
};



//Optimised - prefix sum approach (similar to subarray sum equals k)
//TC -> O(n) , SC -> O(n)
class Solution {
public:
    unordered_map<long long, int> mp;
    int count = 0;

    void dfs(TreeNode* node, long long currSum, int target) {
        if (!node) return;

        currSum += node->val;

        if (mp.count(currSum - target))
            count += mp[currSum - target];

        mp[currSum]++;
        dfs(node->left, currSum, target);
        dfs(node->right, currSum, target);
        mp[currSum]--;   // backtrack
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;       // base case -> to handle the case when currSum itself is equal to target
        dfs(root, 0, targetSum);
        return count;
    }
};
