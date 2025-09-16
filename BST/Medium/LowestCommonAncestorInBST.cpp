Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that
has both p and q as descendants (where we allow a node to be a descendant of itself).”

//Complexity Analysis
Time Complexity: O(h) (O(log n) for balanced, O(n) worst case)
Space Complexity: O(h) recursion (O(1) if iterative)

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

        if(root->val >p->val && root->val >q->val){
            return lowestCommonAncestor(root->left,p,q);
        }

        if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else{
            return root;
        }
    }
};