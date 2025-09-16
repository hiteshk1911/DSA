Problem Statement: Given a Binary Tree, return its Bottom View. The Bottom View of a Binary Tree is the set of nodes visible when we see the tree from the bottom.

//Complexity Analysis
Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the BFS traversal.

Space Complexity: O(N/2 + N/2) where N represents the number of nodes in the Binary Tree.

The main space consuming data structure is the queue used for BFS traversal. It acquires space proportional to the number of nodes in the level it is exploring hence in the worst case of a balanced binary tree, the queue will have at most N/2 nodes which is the maximum width.
Additionally, the map is used to store the top view nodes based on their vertical positions hence its complexity will also be proportional to the greatest width level. In the worst case, it may have N/2 entries as well.


//{vertical, node}
class Solution{
public:
    // Function to return the
    // bottom view of the binary tree
    vector<int> bottomView(Node* root){
        // Vector to store the result
        vector<int> ans;

        // Check if the tree is empty
        if(root == NULL){
            return ans;
        }

        // Map to store the bottom view nodes
        // based on their vertical positions
        map<int, int> mpp;

        // Queue for BFS traversal, each
        // element is a pair containing node
        // and its vertical position
        queue<pair<Node*, int>> q;

        // Push the root node with its vertical
        // position (0) into the queue
        q.push({root, 0});

        // BFS traversal
        while(!q.empty()){
            // Retrieve the node and its vertical
            // position from the front of the queue
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;

            // Update the map with the node's data
            // for the current vertical position
            mpp[line] = node->data;

            // Process left child
            if(node->left != NULL){
                // Push the left child with a decreased
                // vertical position into the queue
                q.push({node->left, line - 1});
            }

            // Process right child
            if(node->right != NULL){
                // Push the right child with an increased
                // vertical position into the queue
                q.push({node->right, line + 1});
            }
        }

        // Transfer values from the
        // map to the result vector
        for(auto it : mpp){
            ans.push_back(it.second);
        }

        return ans;
    }
};

