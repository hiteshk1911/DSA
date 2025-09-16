Problem Statement: Given a Complete Binary Tree, count and return the number of nodes in the given tree.
A Complete Binary Tree is a binary tree in which all levels are completely filled, except possibly for the last level, and all nodes are as left as possible.

//Brute Force Approach
- Traverse the tree and count the nodes
- TC : O(N) SC : O(H) , H is the height of the tree

//Optimal Approach
The relationship between the height of the binary tree (h) and the maximum number of nodes it can have, denoted by the formula: Maximum Number of Nodes: 2^h-1
If the last level of a binary tree is perfectly filled, known as a perfect binary tree, the count of nodes can be determined by the formula: 2h-1, where h is the height. To check if the last level of the Binary Tree is filled or not we can compare the left and right heights of the tree.
If the left height equals right height, it indicates that the last level is completely filled.
If the left height does not equal right height, the last level is not completely filled.
In the case where left height and right height differ, we can employ a recursive approach. We recursively calculate the number of nodes in the left subtree and in the right subtree , and then return the total count as 1 + leftNodes + rightNodes. If the height of the left subtree is equal to the height of the right subtree, we can directly calculate using the 2h-1 formula.

//Complexity Analysis

Time Complexity: O(log N * log N) where N is the number of nodes in the Binary Tree.

The calculation of leftHeight and rightHeight takes O(log N) time.
In the worst case, when encountering the second case (leftHeight != rightHeight), the recursive calls are made at most log N times (the height of the tree).

Therefore, the total time complexity is O(log N * log N).
Space Complexity : O(H) ~ O(N) where N is the number of nodes in the Binary Tree.

The space complexity is determined by the maximum depth of the recursion stack, which is equal to the height of the binary tree.
Since the given tree is a complete binary tree, the height will always be log N.
Therefore, the space complexity is O(log N).


class Solution {
public:
    // Function to count nodes
    // in a binary tree
    int countNodes(TreeNode* root) {
        // Base case: If the root
        // is NULL, there are no nodes
        if (root == NULL) {
            return 0;
        }

        // Find the left height and
        // right height of the tree
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        // Check if the last level
        // is completely filled
        if (lh == rh) {
            // If so, use the formula for
            // total nodes in a perfect
            // binary tree ie. 2^h - 1
            return (1 << lh) - 1;
        }

        // If the last level is not completely
        // filled, recursively count nodes in
        // left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Function to find the left height of a tree
    int findHeightLeft(TreeNode* node) {
        int height = 0;
        // Traverse left child until
        // reaching the leftmost leaf
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }

    // Function to find the right height of a tree
    int findHeightRight(TreeNode* node) {
        int height = 0;
        // Traverse right child until
        // reaching the rightmost leaf
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }
};

