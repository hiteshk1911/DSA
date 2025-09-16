Problem Statement: Given a Binary Tree, return the Vertical Order Traversal of it starting from the Leftmost level to the Rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

// Complexity Analysis
Time Complexity: O(N * log2N * log2N * log2N) where N represents the number of nodes in the Binary Tree.

Postorder Traversal performed using BFS as a time complexity of O(N) as we are visiting each and every node once.
Multiset Operations to insert overlapping nodes at a specific vertical and horizontal level also takes O(log2N) complexity.
Map operations involve insertion and retrieval of nodes with their vertical and level as their keys. Since there are two nested maps, the total time complexity becomes O(log2N)*O(log2N).

Space Complexity: O(N + N/2) where N represents the number of nodes in the Binary Tree.

The map for storing nodes based on their vertical and level information occupies an additional space complexity of O(N) as it stores all N nodes of the Binary Tree.
The queue for breadth first traversal occupies a space proportional to the maximum level of the tree which can be O(N/2) in the worst case of a balanced tree.


//{vertical,{level,{[values]}}}
class Solution {
public:
    // Function to perform vertical order traversal
    // and return a 2D vector of node values
    vector<vector<int>> findVertical(Node* root){
        // Map to store nodes based on
        // vertical and level information
        map<int, map<int, multiset<int>>> nodes; // vertical -> {level -> [values]} //multiset ->  to ensure unique and sorted order of nodes

        // Queue for BFS traversal, each
        // element is a pair containing node
        // and its vertical and level information
        queue<pair<Node*, pair<int, int>>> todo;

        // Push the root node with initial vertical
        // and level values (0, 0)
        todo.push({root, {0, 0}});

        // BFS traversal
        while(!todo.empty()){
            // Retrieve the node and its vertical
            // and level information from
            // the front of the queue
            auto p = todo.front();
            todo.pop();
            Node* temp = p.first;

            // Extract the vertical and level information
            // x -> vertical
            int x = p.second.first;
            // y -> level
            int y = p.second.second;

            // Insert the node value into the
            // corresponding vertical and level
            // in the map
            nodes[x][y].insert(temp->data);

            // Process left child
            if(temp->left){
                todo.push({
                    temp->left,
                    {
                        // Move left in
                        // terms of vertical
                        x-1,
                        // Move down in
                        // terms of level
                        y+1
                    }
                });
            }

            // Process right child
            if(temp->right){
                todo.push({
                    temp->right,
                    {
                        // Move right in
                        // terms of vertical
                        x+1,
                        // Move down in
                        // terms of level
                        y+1
                    }
                });
            }
        }

        // Prepare the final result vector
        // by combining values from the map
        vector<vector<int>> ans;
        for(auto p: nodes){
            vector<int> col;
            for(auto q: p.second){
                // Insert node values
                // into the column vector
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            // Add the column vector
            // to the final result
            ans.push_back(col);
        }
        return ans;
    }
};

