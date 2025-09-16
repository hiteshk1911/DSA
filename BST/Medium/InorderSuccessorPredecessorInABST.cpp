Predecessor: Largest value smaller than key.
    If node has a left child → predecessor = max in left subtree.
    Else → keep track of last node < key while traversing from root.

Successor: Smallest value greater than key.

    If node has a right child → successor = min in right subtree.
    Else → keep track of last node > key while traversing from root.

//Complexity Analysis:
Time: O(H), where H = height of BST.
    Worst case (skewed): O(N).
    Balanced: O(log N).

Space: O(1) (iterative, only a few pointers).

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    TreeNode* findMax(TreeNode* node) {
        while (node && node->right) node = node->right;
        return node;
    }

public:
    pair<TreeNode*, TreeNode*> inorderPreSuc(TreeNode* root, int key) {
        TreeNode* predecessor = nullptr;
        TreeNode* successor = nullptr;
        TreeNode* curr = root;

        while (curr) {
            if (curr->val == key) {
                // Case 1: if left exists → predecessor = max in left subtree
                if (curr->left) {
                    predecessor = findMax(curr->left);
                }
                // Case 2: if right exists → successor = min in right subtree
                if (curr->right) {
                    successor = findMin(curr->right);
                }
                break;
            }
            else if (key < curr->val) {
                successor = curr;       // possible successor
                curr = curr->left;
            }
            else {
                predecessor = curr;     // possible predecessor
                curr = curr->right;
            }
        }
        return {predecessor, successor};
    }
};
