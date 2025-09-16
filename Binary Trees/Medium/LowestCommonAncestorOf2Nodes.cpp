Problem Statement: Given a binary tree, Find the Lowest Common Ancestor for two given Nodes (x,y).

Lowest Common Ancestor(LCA): The lowest common ancestor is defined between two nodes x and y as the lowest node in T that has both x and y as descendants (where we allow a node to be a descendant of itself.

//Complexity Analysis
Time complexity: O(N) where n is the number of nodes.
Space complexity: O(N), auxiliary space

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }

        if(root->val==p->val || root->val==q->val){
            return root;
        }

        TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);

        if(leftAns && rightAns){
            return root;
        }else if(leftAns){
            return leftAns;
        }else if(rightAns){
            return rightAns;
        }else{
            return NULL;
        }


    }
};