Leetcode 687 :
Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.

The length of the path between two nodes is represented by the number of edges between them.

//TC: O(N) where N is the number of nodes in the tree
//SC: O(H) where H is the height of the tree
class Solution {
public:
    int ans = 0;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);

        int leftPath = 0, rightPath = 0;

        if (node->left && node->left->val == node->val)
            leftPath = left + 1;

        if (node->right && node->right->val == node->val)
            rightPath = right + 1;

        // Update global answer (can take both sides)
        ans = max(ans, leftPath + rightPath);

        // Return only ONE side upward
        return max(leftPath, rightPath);
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
