Problem Statement: Given the Preorder and Inorder traversal of a Binary Tree, construct the Unique Binary Tree represented by them.

// Complexity Analysis
- Time Complexity: O(N^2) where N is the number of nodes in the binary tree. This is because for each node, we are performing a linear search to find its position in the inorder traversal.
                   If we use a hash map to store the indices of inorder elements, we can reduce the time complexity to O(N).
- Space Complexity: O(N) where N is the number of nodes in the binary tree. This space is used to store the recursion stack and the tree nodes.

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
     //We can optimize the findPos function using a map to store the indices of inorder elements for O(1) access time.
     int findPos(vector<int> in,int element,int n){
        for(int i=0;i<n;i++){
            if(in[i]==element){
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int> in,vector<int> pre,int &index,int inOrderStart,int inOrderEnd,int n){
        if(index>=n || inOrderStart>inOrderEnd){
            return NULL;
        }

        int element=pre[index++];
        TreeNode* root=new TreeNode(element);
        int position=findPos(in,element,n);

        root->left=helper(in,pre,index,inOrderStart,position-1,n);
        root->right=helper(in,pre,index,position+1,inOrderEnd,n);

        return root;

    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int index=0;
        int n=pre.size();
        TreeNode* ans=helper(in,pre,index,0,n-1,n);
        return ans;
    }
};
