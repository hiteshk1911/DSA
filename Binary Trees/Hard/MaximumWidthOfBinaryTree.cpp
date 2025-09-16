Given the root of a binary tree, return the maximum width of the given tree.
The maximum width of a tree is the maximum width among all levels.
The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes),
where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

//Complexity Analysis
Time Complexity: O(N) where N is the number of nodes in the binary tree. Each node of the binary tree is enqueued and dequeued exactly once, hence all nodes need to be processed and visited. Processing each node takes constant time operations which contributes to the overall linear time complexity.
Space Complexity: O(N) where N is the number of nodes in the binary tree. In the worst case, the queue has to hold all the nodes of the last level of the binary tree, the last level could at most hold N/2 nodes hence the space complexity of the queue is proportional to O(N).

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
class Solution {
public:

   int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long maxWidth = 0;
        queue<pair<TreeNode*, long long>> q; // Queue to store nodes and their position
        q.push({root, 1});

        while (!q.empty()) {
            long long size = q.size();
            long long min = q.front().second; // Normalize the index to prevent overflow
            long long first = 0, last = 0;

            for (long long i = 0; i < size; ++i) {
                auto [node, pos] = q.front();
                q.pop();
                pos -= min; // Normalize position
                if (i == 0) first = pos;
                if (i == size - 1) last = pos;

                if (node->left) q.push({node->left, 2 * pos});
                if (node->right) q.push({node->right, 2 * pos + 1});
            }

            maxWidth = std::max(maxWidth, last - first + 1);
        }

        return maxWidth;
    }
};

