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
public:
     class Tree{
        public:
            int maxi;
            int mini;
            bool isBst;
            int sum;

    };
    Tree helper(TreeNode* root,int &maxSum){
        if(!root){
            return {INT_MIN,INT_MAX,true,0};
        }

        Tree leftAns=helper(root->left,maxSum);
        Tree rightAns=helper(root->right,maxSum);

        Tree ans;

        if(leftAns.isBst && rightAns.isBst && (root->val > leftAns.maxi && root->val < rightAns.mini)){
            ans.isBst=true;
        }else{
            ans.isBst=false;
        }
        ans.maxi=max(root->val,rightAns.maxi);
        ans.mini=min(root->val,leftAns.mini);
        ans.sum=leftAns.sum+rightAns.sum+root->val;

        if(ans.isBst){
            maxSum=max(maxSum,ans.sum);
        }

        return ans;
    }
    int maxSumBST(TreeNode* root) {
        	if(!root){
    	    return 0;
    	}
    	int maxSum=0;
    	Tree ans=helper(root,maxSum);
    	return maxSum;
    }
};