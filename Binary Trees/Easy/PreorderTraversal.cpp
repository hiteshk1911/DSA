//N L R

//Iterative Solution
Algorithm / Intuition: (Push Node , then right child , then left child in stack)
The preorder traversal of a Binary Tree follows the order: Root, Left then Right.
An iterative approach maintains a stack structure to simulate the recursive nature of the traversal without using actual recursion.
Initially the root node is pushed into the stack. While the stack is not empty, we continuously pop nodes from the stack and for each popped node, we add its value to the resultant traversal vector,
push its right child onto the stack followed by its left child.This sequence ensures that the left child, which should be processed first in the preorder traversal, is visited before the right child due to the Last In, First Out behaviour of the stack.
This process continues until all nodes are traversed.

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Define the TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to perform preorder traversal
    // of a binary tree iteratively
    vector<int> preorderTraversal(TreeNode* root) {
        // Initialize vector to store
        // the preorder traversal result
        vector<int> preorder;

        // If the root is null, return
        // an empty traversal result
        if(root == nullptr) {
            return preorder;
        }

        // Create a stack to store
        // nodes during traversal
        stack<TreeNode*> st;
        // Push the root node
        // onto the stack
        st.push(root);

        // Perform iterative preorder traversal
        while(!st.empty()) {
            // Get the current node
            // from the top of the stack
            root = st.top();
            // Remove the node
            // from the stack
            st.pop();

            // Add the node's value to
            // the preorder traversal result
            preorder.push_back(root->val);

            // Push the right child
            // onto the stack if exists
            if(root->right != nullptr) {
                st.push(root->right);
            }

            // Push the left child onto
            // the stack if exists
            if(root->left != nullptr) {
                st.push(root->left);
            }
        }

        // Return the preorder
        // traversal result
        return preorder;
    }
};


//Recursive Solution
Complexity Analysis

Time Complexity: O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once.
Space Complexity: O(H) where H is the height of the binary tree. This space is used to store the function call stack during the recursion. In the worst case (for a skewed tree), the height of the tree can be N, leading to O(N) space complexity. In the best case (for a balanced tree), the height of the tree is log(N), leading to O(log N) space complexity.

#include <iostream>
#include <vector>

using namespace std;

// Node structure for
// the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform preorder traversal
// of the tree and store values in 'arr'
void preorder(Node* root, vector<int> &arr){
    // If the current node is NULL
    // (base case for recursion), return
    if(root == nullptr){
        return;
    }
    // Push the current node's
    // value into the vector
    arr.push_back(root->data);
    // Recursively traverse
    // the left subtree
    preorder(root->left, arr);
    // Recursively traverse
    // the right subtree
    preorder(root->right, arr);
}

// Function to initiate preorder traversal
// and return the resulting vector
vector<int> preOrder(Node* root){
    // Create an empty vector to
    // store preorder traversal values
    vector<int> arr;
    // Call the preorder traversal function
    preorder(root, arr);
    // Return the resulting vector
    // containing preorder traversal values
    return arr;
}

// Main function
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting preorder traversal
    vector<int> result = preOrder(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    // Output each value in the
    // preorder traversal result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}

//Iterative Solution

void preOrder(Node* root){
    if(!root){
        return ;
    }

    stack<Node*> st;

    Node* curr = root;
    while(curr || !st.empty()){
        if(curr){
            cout<<curr->data<<" ";
            st.push(curr);
            curr = curr->left;
        }else{
            curr = st.top();
            st.pop();
            curr = curr->right;
        }
    }
}
