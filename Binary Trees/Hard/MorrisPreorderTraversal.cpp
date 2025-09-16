Problem Statement: Given a Binary Tree, implement Morris Preorder Traversal and return the array containing its preorder sequence.

Morris Preorder Traversal is a tree traversal algorithm aiming to achieve a space complexity of O(1) without recursion or an external data structure.
The algorithm should efficiently visit each node in the binary tree in preorder sequence, printing or processing the node values as it traverses, without using a stack or recursion.

//Complexity Analysis
Time Complexity: O(2N) where N is the number of nodes in the Binary Tree.
The time complexity is linear, as each node is visited at most twice (once for establishing the temporary link and once for reverting it).

Space Complexity: O(1) The space complexity is constant, as the algorithm uses only a constant amount of extra space irrespective of the input size.

class Solution {
public:
    // Function to perform iterative Morris
    // preorder traversal of a binary tree
    vector<int> getPreorder(TreeNode* root) {
        // Vector to store the
        // preorder traversal result
        vector<int> preorder;

        // Pointer to the current node,
        // starting with the root
        TreeNode* cur = root;

        // Iterate until the
        // current node becomes NULL
        while (cur != NULL) {
            // If the current node
            // has no left child
            if (cur->left == NULL) {
                // Add the value of the
                // current node to the preorder vector
                preorder.push_back(cur->val);

                // Move to the right child
                cur = cur->right;
            } else {
                // If the current node has a left child
                // Create a pointer to traverse to the
                // rightmost node in the left subtree
                TreeNode* prev = cur->left;

                // Traverse to the rightmost node in the
                // left subtree or until we find a node
                // whose right child is not yet processed
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }

                // If the right child of the
                // rightmost node is NULL
                if (prev->right == NULL) {

                    preorder.push_back(cur->val); // 🔥 process here (first time)
                    // Set the right child of the
                    // rightmost node to the current node
                    prev->right = cur;

                    // Move to the left child
                    cur = cur->left;
                } else {
                    // If the right child of the
                    // rightmost node is not NULL
                    // Reset the right child to NULL
                    prev->right = NULL;



                    // Move to the right child
                    cur = cur->right;
                }
            }
        }

        // Return the resulting
        //preorder traversal vector
        return preorder;
    }
};
