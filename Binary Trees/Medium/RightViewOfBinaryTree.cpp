Problem Statement: Given a Binary Tree, return its right view.

The Right View of a Binary Tree is a list of nodes that can be seen when the tree is viewed from the right side.

//Complexity Analysis
Time Complexity: O(log2N) where N is the number of nodes in the Binary Tree. This complexity arises as we travel along the height of the Binary Tree. For a balanced binary tree, the height is log2N but in the worst case when the tree is skewed, the complexity becomes O(N).

Space Complexity : O(log2N) where N is the number of nodes in the Binary Tree. This complexity arises because we store the leftmost and rightmost nodes in an additional vector. The size of this result vector is proportional to the height of the Binary Tree which will be log2N when the tree is balanced and O(N) in the worst case of a skewed tree.

O(H): Recursive Stack Space is used to calculate the height of the tree at each node which is proportional to the height of the tree.
The recursive nature of the getHeight function, which incurs space on the call stack for each recursive call until it reaches the leaf nodes or the height of the tree.

1) BFS (Level Order Traversal) Approach
- TC : O(N) SC : O(H) , H is the height of the tree

vector<int> rightView(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();
            if (i == size - 1) res.push_back(node->val); // last node of this level

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
    // Function to return the Right view of the binary tree
    vector<int> rightsideView(Node* root){
        // Vector to store the result
        vector<int> res;

        // Call the recursive function
        // to populate the right-side view
        recursionRight(root, 0, res);

        return res;
    }


private:

    // Recursive function to traverse the
    // binary tree and populate the right-side view
    void recursionRight(Node* root, int level, vector<int> &res){
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
        // right child with an increased level
        recursionRight(root->right, level + 1, res);

        // Recursively call the function for the
        // left child with an increased level
        recursionRight(root->left, level + 1, res);

    }
};




