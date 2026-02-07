//L R N

//Iterative Solution
1) Using 2 stacks:
TC - O(2N)
SC - O(2N)
Algo -
    Step 1: Create two stacks: one for holding nodes and another for storing the final postorder traversal sequence. Initialise an array `postorder` to store the traversal sequence.
    Step 2: Push the root node to the first stack.
    Step 3: Process the nodes until the first stack is empty:
                Pop a node from the top of the first stack.
                Push this node onto the second stack.
                Push its left child (if it exists) onto the first stack.
                Push its right child (if it exists) onto the first stack.
    Step 4:Once the first stack is empty, retrieve the nodes in the postorder sequence by popping nodes from the second stack one by one and store them in the postorder array.

#include <iostream>
#include <vector>
#include <stack>

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

// Function to return the postOrder
// traversal of a binary tree using
// two stacks
vector<int> postOrder(Node* root) {
    // Vector to store
    // postorder traversal
    vector<int> postorder;

    // If the tree is empty,
    // return an empty traversal
    if(root == NULL){
        return postorder;
    }

    // Two stacks for
    // iterative traversal
    stack<Node*> st1, st2;

    // Push the root node
    // onto the first stack
    st1.push(root);

    // Iterative traversal to populate
    // st2 with nodes in postorder
    while(!st1.empty()){
        // Get the top node from st1
        root = st1.top();
        st1.pop();

        // Push the node onto st2
        st2.push(root);

        // Push left child onto st1 if exists
        if(root->left != NULL){
            st1.push(root->left);
        }

        // Push right child onto st1 if exists
        if(root->right != NULL){
            st1.push(root->right);
        }
    }

    // Populate the postorder traversal
    // vector by popping st2
    while(!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }

    // Return the
    // postorder traversal
    return postorder;
}

2) Using 1  stack:
- Traverse down left subtree, but keep track of whether you’ve already visited the right subtree
- TC - O(N)
- SC - O(H) H is height of tree

void postorder(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* curr = root;
    TreeNode* lastVisited = nullptr;

    while (curr != nullptr || !st.empty()) {
        if (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        } else {
            TreeNode* peekNode = st.top();
            // if right child exists and traversal hasn't visited it yet
            if (peekNode->right != nullptr && lastVisited != peekNode->right) {
                curr = peekNode->right;
            } else {
                cout << peekNode->val << " ";  // process
                lastVisited = peekNode;
                st.pop();
            }
        }
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

// Function to perform postorder
// traversal recursively
void postorder(Node* root, vector<int>& arr){
    // Base case: if root is null, return
    if(root==NULL){
        return;
    }
    // Traverse left subtree
    postorder(root->left, arr);
    // Traverse right subtree
    postorder(root->right, arr);
    // Visit the node
    // (append node's data to the array)
    arr.push_back(root->data);
}

// Function to get the postorder
// traversal of a binary tree
vector<int> postOrder(Node* root){
    // Create a vector to
    // store the traversal result
    vector<int> arr;
    // Perform postorder traversal
    // starting from the root
    postorder(root, arr);
    // Return the postorder
    // traversal result
    return arr;
}

// Function to print the
// elements of a vector
void printVector(const vector<int>& vec) {
    // Iterate through the vector
    // and print each element
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

//Iterative Solution

void postOrder(Node* root){
    if(!root){
        return ;
    }

    stack<Node*> st;

    Node* curr = root;
    Node* lastVisited = NULL;
    while(curr || !st.empty()){
        if(curr){
            st.push(curr);
            curr = curr->left;
        }else{
            Node* peekNode = st.top();
            if(peekNode->right && peekNode->right != lastVisited){
                curr = peekNode->right;
            }else{
                cout<<peekNode->data<<" ";
                lastVisited = peekNode;
                st.pop();
            }
        }
    }
}
