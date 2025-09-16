Problem Statement: Given a binary tree, determine if it is a valid binary search tree (BST).

//Brute Force Approach
- Find min/max for each subtree & check if it satisfies the BST properties
- TC : O(N^2) SC : O(H) , H is the height of the tree

//Better Approach
- Perform an inorder traversal of the tree to get a sorted array of elements
- Check if the array is sorted in ascending order
- TC : O(N) SC : O(N)

//Optimal Approach
Time: O(n) (each node checked once).
Space: O(h) recursion stack.

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
    bool checkBST(TreeNode* root,long mini,long maxi){
        if(!root){
            return true;
        }

        if(root->val<=mini || root->val>=maxi){
            return false;
        }else{
            return checkBST(root->left,mini,root->val) && checkBST(root->right,root->val,maxi);
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        return checkBST(root,LONG_MIN,LONG_MAX);
    }
};