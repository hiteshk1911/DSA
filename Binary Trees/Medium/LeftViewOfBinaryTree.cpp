Problem Statement: Given a Binary Tree, return its left view.

The Left View of a Binary Tree is a list of nodes that can be seen when the tree is viewed from the left side.

//Complexity Analysis


1) BFS (Level Order Traversal) Approach
- TC : O(N) SC : O(H) , H is the height of the tree

vector<int> leftView(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();
            if (i == 0) res.push_back(node->val); // first node of this level

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return res;
}

2) DFS (Preorder Traversal) Approach
- TC : O(N) SC : O(H) , H is the height of the tree

class Solution {
public:

    // Function to return the Left view of the binary tree
    vector<int> leftsideView(Node* root){
        // Vector to store the result
        vector<int> res;

        // Call the recursive function
        // to populate the left-side view
        recursionLeft(root, 0, res);

        return res;
    }

private:
    // Recursive function to traverse the
    // binary tree and populate the left-side view
    void recursionLeft(Node* root, int level, vector<int>& res){
        // Check if the current node is NULL
        if(root == NULL){
            return;
        }

        // Check if the size of the result vector
        // is equal to the current level
        if(res.size() == level){
            // If equal, add the value of the
            // current node to the result vector
            res.push_back(root->data);
        }

        // Recursively call the function for the
        // left child with an increased level
        recursionLeft(root->left, level + 1, res);

        // Recursively call the function for the
        // right child with an increased level
        recursionLeft(root->right, level + 1, res);
    }

};




