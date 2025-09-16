✅ Approach: Post-order Traversal (Bottom-Up)

Key idea:
For each node, gather information from its left and right subtrees:
        isBST → whether the subtree rooted at this node is a BST
        size → number of nodes in the subtree if it is BST
        minVal → minimum value in the subtree
        maxVal → maximum value in the subtree

Using these, we can determine if the current node forms a BST.

struct Info {
    bool isBST;
    int size;
    int minVal;
    int maxVal;
};

class Solution {
    int maxSize = 0;

    Info largestBST(TreeNode* root) {
        if (!root) return {true, 0, INT_MAX, INT_MIN};

        Info left = largestBST(root->left);
        Info right = largestBST(root->right);

        Info curr;
        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            curr.isBST = true;
            curr.size = left.size + right.size + 1;
            curr.minVal = min(root->val, left.minVal);
            curr.maxVal = max(root->val, right.maxVal);

            maxSize = max(maxSize, curr.size);
        } else {
            curr.isBST = false;
            curr.size = 0; // current subtree is not BST
        }

        return curr;
    }

public:
    int largestBSTSubtree(TreeNode* root) {
        largestBST(root);
        return maxSize;
    }
};
