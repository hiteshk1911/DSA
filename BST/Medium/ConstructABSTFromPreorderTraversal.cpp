//Approach1 - Normal insert into BST
TC : O(N^2`) SC : O(H)

//Approach2 - Using inorder and preorder
TC : O(N) SC : O(N)

//Approach3 - Using bounds
// TC : O(N) SC : O(H)

class Solution {
public:
    TreeNode* helper(vector<int> pre,int mini,int maxi,int &i){
        if(i>=pre.size()){
            return NULL;
        }
        if(pre[i]<mini || pre[i]>maxi){
            return NULL;
        }

        TreeNode* root=new TreeNode(pre[i++]);
        root->left=helper(pre,mini,root->val,i);
        root->right=helper(pre,root->val,maxi,i);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return helper(preorder,INT_MIN,INT_MAX,index);
    }
};