Problem Statement: Given a Binary Tree, determine whether the given tree is symmetric or not. A Binary Tree would be Symmetric, when its mirror image is exactly the same as the original tree. If we were to draw a vertical line through the centre of the tree, the nodes on the left and right side would be mirror images of each other.

//Solution
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
    bool helper(TreeNode* p,TreeNode* q){
        if(!p && !q){
            return true;
        }else if(!p || !q){
            return false;
        }

        if(p->val!=q->val){
            return false;
        }

        return helper(p->left,q->right) && helper(p->right,q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }

        return helper(root->left,root->right);
    }
};