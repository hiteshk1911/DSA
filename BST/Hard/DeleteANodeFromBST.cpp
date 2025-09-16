//Algorithm Explanation (Delete Node in BST)

We want to delete a node with a given key in a Binary Search Tree (BST).

1)Search for the node

    If key < root->val, go left.

    If key > root->val, go right.

    If key == root->val, this is the node we want to delete.

2)Cases when deleting the node

    Case 1: Node has no children (leaf node)
    → Simply delete it and return nullptr.

    Case 2: Node has one child
    → Return the non-null child to replace the node.

    Case 3: Node has two children
    → We need to preserve BST properties.

        Find the inorder successor (findMin(root->right) = smallest node in right subtree).
        Copy its value into the current node.
        Recursively delete the inorder successor from the right subtree.

3)Return the root after modifications.

//Complexity Analysis
Time Complexity

    Searching for the node: O(h) where h = height of tree.
    Deletion itself:

        Case 1 & 2: Constant work = O(1).

        Case 3: We also find the inorder successor (findMin) which takes O(h) in worst case.

    Total = O(h)

👉 In terms of n (number of nodes):

    Average (Balanced BST): O(log n)
    Worst (Skewed BST): O(n)

Space Complexity

Because it’s recursive, the recursive call stack can go as deep as the height of the tree (h).

So:

    Average: O(log n)
    Worst: O(n)

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
    private:
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }
public:
     TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        // Locate the node to be deleted
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node with the key is found

            // Case 1: Node has no child (leaf node)
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }

            // Case 2: Node has only one child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Node has two children
            TreeNode* temp = findMin(root->right); // Find the in-order successor (smallest in the right subtree)
            root->val = temp->val; // Replace root value with successor's value
            root->right = deleteNode(root->right, temp->val); // Delete the in-order successor
        }

        return root;
     }
};