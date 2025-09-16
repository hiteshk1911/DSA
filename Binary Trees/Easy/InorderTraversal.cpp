//L N R

//Iterative Solution
- Push root then move all the way to the leftmost node, pushing all left nodes onto the stack
- When a null is reached, pop from the stack, process the node, and then move to its right child

void inorder(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr != nullptr || !st.empty()) {
        // Go to leftmost node
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }

        // Visit node
        curr = st.top();
        st.pop();
        cout << curr->val << " ";  // process the node

        // Now visit right subtree
        curr = curr->right;
    }
}



//Recursive Solution
Complexity Analysis

Time Complexity: O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once.
Space Complexity: O(H) where H is the height of the binary tree. This space is used to store the function call stack during the recursion. In the worst case (for a skewed tree), the height of the tree can be N, leading to O(N) space complexity. In the best case (for a balanced tree), the height of the tree is log(N), leading to O(log N) space complexity.

#include <iostream>
#include <vector>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform inorder traversal
// of the tree and store values in 'arr'
void inorder(Node* root, vector<int> &arr){
    // If the current node is NULL
    // (base case for recursion), return
    if(root == nullptr){
        return;
    }
    // Recursively traverse the left subtree
    inorder(root->left, arr);
    // Push the current node's
    // value into the vector
    arr.push_back(root->data);
    // Recursively traverse
    // the right subtree
    inorder(root->right, arr);
}

// Function to initiate inorder traversal
// and return the resulting vector
vector<int> inOrder(Node* root){
    // Create an empty vector to
    // store inorder traversal values
    vector<int> arr;
    // Call the inorder traversal function
    inorder(root, arr);
    // Return the resulting vector
    // containing inorder traversal values
    return arr;
}

