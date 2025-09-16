Problem Statement: Given a Binary Search Tree and a key, return the ceiling of the given key in the Binary Search Tree.

Ceiling of a value refers to the value of the smallest node in the Binary Search Tree that is greater than or equal to the given key.
If the ceiling node does not exist, return nullptr.

NOTE: ceil ≠ inorder successor always.
         They only coincide when:

            1) k exists in BST, and
            2) We want the next greater element (not equal).

// Complexity Analysis
Time Complexity: O(log2N) where N is the number of nodes in the Binary Search Tree. In the best case scenario, where the tree is balanced, the time complexity is the height of the tree ie. log2N. In the worst-case scenario, where the tree is degenerate (linear), the time complexity becomes O(n), as it would require traversing all nodes along the path from the root to the leaf.

Space Complexity: O(1) since the algorithm does not use any additional space or data structures.

class Solution {
public:
    // Function to find the ceiling of
    // a key in a Binary Search Tree (BST)
    int findCeil(TreeNode* root, int key){
        // Initialize the variable
        // to store the ceiling value
        int ceil = -1;

        // Traverse the BST until reaching
        // the end or finding the key
        while(root){
             // If the key is found, assign it
             // as the ceiling and return
            if(root->val == key){
                ceil = root->val;
                return ceil;
            }

             // If the key is greater,
             // move to the right subtree
            if(key > root->val){
                root = root->right;
            }
            else{
                // If the key is smaller, update ceil
                // and move to the left subtree
                ceil = root->val;
                root = root->left;
            }
        }
         // Return the computed ceiling value
        return ceil;
    }
};
