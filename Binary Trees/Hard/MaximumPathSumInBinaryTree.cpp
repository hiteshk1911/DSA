Problem Statement: Given a Binary Tree, determine the maximum sum achievable along any path within the tree.
A path in a binary tree is defined as a sequence of nodes where each pair of adjacent nodes is connected by an edge.
Nodes can only appear once in the sequence, and the path is not required to start from the root.
dentify and compute the maximum sum possible along any path within the given binary tree.

//Solution
- TC : O(N) SC : O(H) , H is the height of the tree

class Solution {
public:
    // Recursive function to find the maximum path sum
    // or a given subtree rooted at 'root'
    // The variable 'maxi' is a reference parameter
    // updated to store the maximum path sum encountered
    int findMaxPathSum(Node* root, int &maxi) {
        // Base case: If the current node is null, return 0
        if (root == nullptr) {
            return 0;
        }

        // Calculate the maximum path sum
        // for the left and right subtrees
        int leftMaxPath = max(0, findMaxPathSum(root->left, maxi));
        int rightMaxPath = max(0, findMaxPathSum(root->right, maxi));

        // Update the overall maximum
        // path sum including the current node
        maxi = max(maxi, leftMaxPath + rightMaxPath + root->data);

        // Return the maximum sum considering
        // only one branch (either left or right)
        // along with the current node
        return max(leftMaxPath, rightMaxPath) + root->data;
    }

    // Function to find the maximum
    // path sum for the entire binary tree
    int maxPathSum(Node* root) {
        // Initialize maxi to the
        // minimum possible integer value
        int maxi = INT_MIN;
         // Call the recursive function to
         // find the maximum path sum
        findMaxPathSum(root, maxi);
        // Return the final maximum path sum
        return maxi;
    }
};