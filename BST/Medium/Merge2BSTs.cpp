✅ Approach 1: Inorder Traversal + Merge

Do inorder traversal of both BSTs → gives two sorted arrays.
Merge the two sorted arrays (like merge step of merge sort).
Optionally, build a balanced BST from the merged array.

Steps:

Inorder of BST1 → O(n1)
Inorder of BST2 → O(n2)
Merge → O(n1 + n2)
Build balanced BST → O(n1 + n2)

Time Complexity: O(n1 + n2)
Space Complexity: O(n1 + n2) (for arrays)

class Solution {
    void inorder(TreeNode* root, vector<int>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    vector<int> mergeSorted(vector<int>& a, vector<int>& b) {
        vector<int> res;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) res.push_back(a[i++]);
            else res.push_back(b[j++]);
        }
        while (i < a.size()) res.push_back(a[i++]);
        while (j < b.size()) res.push_back(b[j++]);
        return res;
    }

    TreeNode* buildBST(vector<int>& arr, int l, int r) {
        if (l > r) return nullptr;
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = buildBST(arr, l, mid - 1);
        root->right = buildBST(arr, mid + 1, r);
        return root;
    }

public:
    TreeNode* mergeBSTs(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        inorder(root1, arr1);
        inorder(root2, arr2);

        vector<int> merged = mergeSorted(arr1, arr2);
        return buildBST(merged, 0, merged.size() - 1);
    }
};


✅ Approach 2: Iterative Inorder Traversal with Two Stacks

Instead of storing all elements, traverse both trees in sorted order simultaneously:
Maintain two stacks for the two BSTs.
Push left children of both roots.
Compare tops of stacks → whichever is smaller is the next element.
Pop it, add to result.
If it has a right child, push its right and all left descendants.
Repeat until both stacks are empty.

Time Complexity: O(n1 + n2)
Space Complexity: O(h1 + h2) (where h is height of trees)

class Solution {
public:
    vector<int> mergeBSTs(TreeNode* root1, TreeNode* root2) {
        vector<int> result;
        stack<TreeNode*> s1, s2;

        while (root1 || root2 || !s1.empty() || !s2.empty()) {
            // Push left chain of root1
            while (root1) {
                s1.push(root1);
                root1 = root1->left;
            }
            // Push left chain of root2
            while (root2) {
                s2.push(root2);
                root2 = root2->left;
            }

            // If one stack is empty, process the other
            if (s1.empty() || (!s2.empty() && s2.top()->val < s1.top()->val)) {
                root2 = s2.top(); s2.pop();
                result.push_back(root2->val);
                root2 = root2->right; // move to right subtree
            } else {
                root1 = s1.top(); s1.pop();
                result.push_back(root1->val);
                root1 = root1->right; // move to right subtree
            }
        }

        return result;
    }
};


✅ Approach 3: Convert to DLLs (Doubly Linked Lists) and Merge

Convert each BST to a sorted doubly linked list (inorder threaded).
Merge the two sorted DLLs.
Convert the merged DLL back to a balanced BST.

Time Complexity: O(n1 + n2)
Space Complexity: O(h1 + h2) (stack for recursion)

✅ Approach 4: Morris Traversal (O(1) space)

Use Morris inorder traversal on both BSTs simultaneously.
This avoids extra stack/recursion space, but implementation is quite tricky.
Only useful if the problem explicitly asks for O(1) extra space.