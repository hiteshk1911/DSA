Problem Statement: Given a Binary Search Tree and a key, return the floor of the given key in the Binary Search Tree.

Floor of a value refers to the value of the largest node in the Binary Search Tree that is smaller than or equal to the given key.
If the floor node does not exist, return nullptr.

NOTE: floor ≠ inorder predecessor always.
         They only coincide when:

            1) k exists in BST, and
            2) We want the prev smaller element (not equal).

// Complexity Analysis
Time Complexity: O(log2N) where N is the number of nodes in the Binary Search Tree. In the best case scenario, where the tree is balanced, the time complexity is the height of the tree ie. log2N. In the worst-case scenario, where the tree is degenerate (linear), the time complexity becomes O(n), as it would require traversing all nodes along the path from the root to the leaf.

Space Complexity: O(1) since the algorithm does not use any additional space or data structures.

class Solution {
public:
    // Function to find the floor of a key
    // in a Binary Search Tree (BST)
    int floorInBST(TreeNode* root, int key){
        // Initialize the floor variable
        // to store the floor value
        int floor = -1;

        // Traverse the BST until reaching
        // the endor finding the key
        while(root){
            // If the key is found, assign it
            // as the floor value and return
            if(root->val == key){
                floor = root->val;
                return floor;
            }

            // If the key is greater than the current
            // node's value, move to the right subtree
            if(key > root->val){
                // Update the floor with the current node's
                // value and move to the right subtree
                floor = root->val;
                root = root->right;
            }
            else{
                // If the key is smaller than the current
                // node's value, move to the left subtree
                root = root->left;
            }
        }
        // Return the computed floor value
        return floor;
    }
};

