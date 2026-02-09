Problem Statement: Given a Binary Search Tree and an integer ‘K’. Find and return the ‘K-th’ smallest and ‘K-th’ largest element in the given Binary Search Tree.

//Brute Force Approach
- Perform an inorder traversal of the BST to get a sorted array of elements
- Return the K-th smallest element as the (K-1)th index and K-th largest element as the (n-K)th index of the sorted array
- TC : O(N) SC : O(N)

//Optimal Approach
Time Complexity: O(N) where N is the number of nodes in the Binary Search Tree as we traverse in inorder and reverse inorder fashion to get to the required nodes. We visit each node once resulting in time complexity proportional to the number of nodes in the BST.

Space Complexity : as no additional space is allocated or data structures used to store any values.


class Solution {
private:
    // Helper function to perform reverse inorder
    // traversal to find Kth largest element
    void reverseInorder(TreeNode* node, int& counter, int k, int& kLargest) {
        if (!node || counter >= k) return;

        // Traverse right subtree
        reverseInorder(node->right, counter, k, kLargest);

        // Increment counter after
        // visiting right subtree
        counter++;

        // Check if current node
        // is the Kth largest
        if (counter == k) {
            kLargest = node->val;
            return;
        }

        // Traverse left subtree if
        // Kth largest is not found yet
        reverseInorder(node->left, counter, k, kLargest);
    }

    // Helper function to perform inorder
    // traversal to find Kth smallest element
    void inorder(TreeNode* node, int& counter, int k, int& kSmallest) {
        if (!node || counter >= k) return;

        // Traverse left subtree
        inorder(node->left, counter, k, kSmallest);

        // Increment counter after visiting left subtree
        counter++;

        // Check if current node is the Kth smallest
        if (counter == k) {
            kSmallest = node->val;
            return;
        }

        // Traverse right subtree if
        // Kth smallest is not found yet
        inorder(node->right, counter, k, kSmallest);
    }

public:
    pair<int, int> findKth(TreeNode* root, int k) {
        int kSmallest = INT_MIN, kLargest = INT_MIN;
        // Counter to track visited nodes
        int counter = 0;

        // Find Kth smallest element
        // (perform inorder traversal)
        inorder(root, counter, k, kSmallest);

        // Reset counter for Kth largest element
        counter = 0;
        // Find Kth largest element
        // (perform reverse inorder traversal)
        reverseInorder(root, counter, k, kLargest);

        return make_pair(kSmallest, kLargest);
    }
};

//Optimal Approach(2)
class Solution {
private:
    void countNodes(TreeNode* node, int& total) {
        if (!node) return;
        countNodes(node->left, total);
        total++;
        countNodes(node->right, total);
    }

    void inorder(TreeNode* node, int& counter, int k, int totalNodes, int& kSmallest, int& kLargest) {
        if (!node) return;

        inorder(node->left, counter, k, totalNodes, kSmallest, kLargest);

        counter++;
        if (counter == k) kSmallest = node->val;
        if (counter == totalNodes - k + 1) kLargest = node->val;

        inorder(node->right, counter, k, totalNodes, kSmallest, kLargest);
    }

public:
    pair<int,int> kthSmallestAndLargest(TreeNode* root, int k) {
        int totalNodes = 0;
        countNodes(root, totalNodes);

        int counter = 0, kSmallest = -1, kLargest = -1;
        inorder(root, counter, k, totalNodes, kSmallest, kLargest);

        return {kSmallest, kLargest};
    }
};

//Optimal Approach(3) - Without extra parameters
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
    int helper(TreeNode* root,int& k){
         if(!root){
            return -1;
        }

        int leftAns = helper(root->left,k);
        if(leftAns!=-1){
            return leftAns;
        }

        k--;
        if(k==0){
            k = INT_MAX;
            return root->val;
        }

        return helper(root->right,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
       return helper(root,k);
    }
};

//Optimal Solution => use morris inorder traversal