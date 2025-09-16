Problem Statement: Given the Postorder and Inorder traversal of a Binary Tree, construct the Unique Binary Tree represented by them.

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
    //We can optimize the findIndex function using a map to store the indices of inorder elements for O(1) access time.
    int findIndex(vector<int> &inorder,int n,int element){
        for(int i=0;i<n;i++){
            if(inorder[i]==element){
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int n,int inStart,int inEnd,int &postIndex){
        if(inStart<=inEnd && postIndex>=0){
            int element = postorder[postIndex--];

            int index = findIndex(inorder,n,element);

            TreeNode* root=new TreeNode(element);

            root->right = helper(inorder,postorder,n,index+1,inEnd,postIndex);
            root->left = helper(inorder,postorder,n,inStart,index-1,postIndex);


            return root;
        }else{
            return NULL;
        }
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int postIndex=n-1;
        return helper(inorder,postorder,n,0,n-1,postIndex);
    }
};