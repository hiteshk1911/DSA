Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.

| Approach                         | Time per `next()` | Space | Notes                                 |
| -------------------------------- | ----------------- | ----- | ------------------------------------- |
| **Stack-based (lazy traversal)** | Amortized O(1)    | O(H)  | More memory efficient for large trees |
| **Precompute inorder (array)**   | O(1)              | O(N)  | Simpler, but uses more memory         |


//Approach 1
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
class BSTIterator {
    TreeNode* root;
    vector<int> inorder;
    int index ;
    void inorderTraversal(TreeNode* root){
        if(!root){
            return ;
        }

        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        this->root=root;
        index = -1;
        inorderTraversal(root);
    }

    int next() {
        if(index+1<inorder.size()){
            index++;
            return inorder[index];

        }
        return -1;
    }

    bool hasNext() {
        return (index+1 < inorder.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

 //Approach 2 - Using Stack (Iterative Inorder Traversal)

We simulate inorder traversal with a stack:
Push all left children of root onto the stack.

next() pops from stack, and if popped node has a right child, push all its left children.

hasNext() checks if stack is non-empty.

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

class BSTIterator {
private:
    stack<TreeNode*> st;

    // helper: push all left children
    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        // if right child exists → push its left subtree
        if (node->right) {
            pushLeft(node->right);
        }
        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};
