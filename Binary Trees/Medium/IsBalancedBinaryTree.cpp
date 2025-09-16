Problem Statement: Given a Binary Tree, return true if it is a Balanced Binary Tree else return false.
A Binary Tree is balanced if, for all nodes in the tree, the difference between left and right subtree height is not more than 1.

//Brute Force Approach
- TC : O(N^2) SC : O(H) , H is the height of the tree

bool isBalanced(Node* root) {
        // If the tree is empty, it's balanced
        if (root == nullptr) {
            return true;
        }

        // Calculate the height of left and right subtrees
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        // Check if the absolute difference in heights
        // of left and right subtrees is <= 1
        if (abs(leftHeight - rightHeight) <= 1 &&
            isBalanced(root->left) &&
            isBalanced(root->right)) {
            return true;
        }

        // If any condition fails, the tree is unbalanced
        return false;
}

//Optimal Approach
- TC : O(N) SC : O(H) , H is the height of the tree

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
    pair<bool,int> helper(TreeNode* root){
        if(!root){
            return {true,0};
        }

        pair<bool,int> leftAns = helper(root->left);
        pair<bool,int> rightAns = helper(root->right);

        pair<bool,int> ans;
        if(leftAns.first && rightAns.first && abs(leftAns.second-rightAns.second)<=1){
            ans.first = true;
            ans.second = max(leftAns.second,rightAns.second)+1;
        }else{
            ans.first = false;
        }
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }

        return helper(root).first;
    }
};