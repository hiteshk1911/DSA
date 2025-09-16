//Diameter Of A Binary Tree
- The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
- The length of a path between two nodes is represented by the number of edges between them.

//Brute Force Approach
- For each node, calculate the height of its left and right subtrees.
- The diameter at that node is the sum of the heights of its left and right subtrees.
- The overall diameter is the maximum diameter found at any node.
- TC : O(N^2) SC : O(H) , H is the height of the tree

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
    int height(TreeNode* root){
        if(!root){
            return 0;
        }

        return max(height(root->left),height(root->right))+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
      if(!root){
            return 0;
        }

        int option1=diameterOfBinaryTree(root->left);
        int option2=diameterOfBinaryTree(root->right);
         //subtracted 1 bcs we are count edges not nodes
        int option3=height(root->left)+height(root->right);


        return max(option1,max(option2,option3));
    }
};

//Optimal Approach
- Use a single traversal to calculate both the height and diameter of the tree.
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
    //{diameter,height}
    pair<int,int> helper(TreeNode* root){
        if(!root){
            return {0,0};
        }

        pair<int,int> leftAns = helper(root->left);
        pair<int,int> rightAns = helper(root->right);

        pair<int,int> ans;

        ans.first = max(leftAns.first,max(rightAns.first,leftAns.second + rightAns.second));
        ans.second = max(leftAns.second , rightAns.second) + 1;

        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).first;
    }
};