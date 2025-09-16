In a Binary Search Tree (BST):

    - Minimum value is always the leftmost node (keep going left until NULL).

    - Maximum value is always the rightmost node (keep going right until NULL).

//Complexity Analysis:
Time Complexity: O(h) where h is the height of the BST
(best case O(1) if root is min/max, worst case O(N) for skewed BST).

Space Complexity: O(1) (iterative, no extra space).

int findMin(TreeNode* root) {
    if (!root) return -1; // or throw exception if tree is empty
    while (root->left) {
        root = root->left;
    }
    return root->val;
}

int findMax(TreeNode* root) {
    if (!root) return -1; // or throw exception if tree is empty
    while (root->right) {
        root = root->right;
    }
    return root->val;
}
