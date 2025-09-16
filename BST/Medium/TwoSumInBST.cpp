
//Approach 1: Inorder + Two Pointers
Do inorder traversal → get sorted array of BST values.
Use two pointers (l=0, r=n-1) to find if any two numbers sum to k.

Approach 2: Two Pointers without Extra Space

Use two iterative inorder traversals:
Normal inorder → gives next smallest element (left → right)
Reverse inorder → gives next largest element (right → left)

Simulate two pointers using two stacks, without storing the entire array.
Compare sum of the two pointers like two-sum in sorted array.

Time: O(N)
Space: O(H1 + H2) → stack for leftmost/rightmost paths

class BSTIterator {
    stack<TreeNode*> st;
    bool reverse; // false = normal inorder, true = reverse inorder

public:
    BSTIterator(TreeNode* root, bool rev) : reverse(rev) {
        pushAll(root);
    }

    int next() {
        TreeNode* node = st.top(); st.pop();
        if (!reverse) pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }

private:
    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            node = reverse ? node->right : node->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        BSTIterator l(root, false); // inorder
        BSTIterator r(root, true);  // reverse inorder

        int i = l.next();
        int j = r.next();

        while (i < j) {
            int sum = i + j;
            if (sum == k) return true;
            else if (sum < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};
