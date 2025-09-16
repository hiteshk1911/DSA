Problem Statement: Given a Binary Search Tree and a key value return the node in the BST having data equal to ‘key’ otherwise return nullptr.

//Complexity Analysis

Time Complexity: O(log2N) where N is the number of nodes in the Binary Search Tree. In the best case scenario, where the tree is balanced, the time complexity is the height of the tree ie. log2N. In the worst-case scenario, where the tree is degenerate (linear), the time complexity becomes O(n), as it would require traversing all nodes along the path from the root to the leaf.

Space Complexity: O(1) since the algorithm does not use any additional space or data structures. The algorithm does use auxiliary stack space from recursion. In the average and worst-case scenarios, the space complexity for recursive stack space is O(h), where 'h' represents the height of the tree.

class Solution {
public:
    // This function searches for a node with
    // a specified value in a Binary Search Tree (BST).
    TreeNode* searchBST(TreeNode* root, int val){
        // Loop until either the tree is
        // exhausted (NULL) or the value is found.
        while(root != NULL && root->val != val){
            // Check if the target value is
            // less than the current node's value.
            // If so, move to the left subtree
            // (values smaller than the current node).
            // Otherwise, move to the right subtree
            // (values larger than the current node).
            root = val < root->val ? root->left : root->right;
        }
        // Return the node containing the target value,
        // if found; otherwise, return NULL.
        return root;
    }
};
