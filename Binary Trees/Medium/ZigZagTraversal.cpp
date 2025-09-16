Problem Statement: Given a Binary Tree, print the zigzag traversal of the Binary Tree.
Zigzag traversal of a binary tree is a way of visiting the nodes of the tree in a zigzag pattern, alternating between left-to-right and right-to-left at each level.

//Complexity Analysis
Complexity Analysis

Time Complexity: O(N) where N is the number of nodes in the binary tree. Each node of the binary tree is enqueued and dequeued exactly once, hence all nodes need to be processed and visited. Processing each node takes constant time operations which contributes to the overall linear time complexity.
Space Complexity: O(N) where N is the number of nodes in the binary tree. In the worst case, the queue has to hold all the nodes of the last level of the binary tree, the last level could at most hold N/2 nodes hence the space complexity of the queue is proportional to O(N). The resultant vector answer also stores the values of the nodes level by level and hence contains all the nodes of the tree contributing to O(N) space as well.



class Solution {
public:
    // Function to perform zigzag level
    // order traversal of a binary tree
    vector<vector<int>> ZigZagLevelOrder(Node* root){
        // Vector to store the
        // result of zigzag traversal
        vector<vector<int>> result;

        // Check if the root is NULL,
        // return an empty result
        if(root == NULL){
            return result;
        }

        // Queue to perform
        // level order traversal
        queue<Node*> nodesQueue;
        nodesQueue.push(root);

        // Flag to determine the direction of
        // traversal (left to right or right to left)
        bool leftToRight = true;

        // Continue traversal until
        // the queue is empty
        while(!nodesQueue.empty()){
            // Get the number of nodes
            // at the current level
            int size = nodesQueue.size();

            // Vector to store the values
            // of nodes at the current level
            vector<int> row(size);

            // Traverse nodes at
            // the current level
            for(int i = 0; i < size; i++){
                // Get the front node
                // from the queue
                Node* node = nodesQueue.front();
                nodesQueue.pop();

                // Determine the index to insert the node's
                // value based on the traversal direction
                int index = leftToRight ? i : (size - 1 - i);

                // Insert the node's value at
                // the determined index
                row[index] = node->data;

                // Enqueue the left and right
                // children if they exist
                if(node->left){
                    nodesQueue.push(node->left);
                }
                if(node->right){
                    nodesQueue.push(node->right);
                }
            }

            // Switch the traversal
            // direction for the next level
            leftToRight = !leftToRight;

            // Add the current level's
            // values to the result vector
            result.push_back(row);
        }

        // Return the final result of
        // zigzag level order traversal
        return result;
    }
};

