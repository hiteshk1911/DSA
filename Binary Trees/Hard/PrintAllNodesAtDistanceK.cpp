Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
You can return the answer in any order.

// Complexity Analysis
Time Complexity: O(n)
Space Complexity: O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void helper(TreeNode* target,vector<int> &ans,int k,int distance,unordered_map<TreeNode*,bool> &visited,unordered_map<TreeNode*,TreeNode*> &parentMap){

    if(target==NULL){
        return ;
    }

    if(distance==k){
        ans.push_back(target->val);
        return ;
    }

    visited[target]=true;

    //upward
    TreeNode* parent = parentMap[target];
    if(parent!=NULL && visited[parent]==false){
        helper(parent,ans,k,distance+1,visited,parentMap);
    }

    //downward
    if(visited[target->left]==false){
        helper(target->left,ans,k,distance+1,visited,parentMap);
    }

    if(visited[target->right]==false){
        helper(target->right,ans,k,distance+1,visited,parentMap);
    }


}
vector<int> printNodesAtDistanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> ans;

    if(!root){
        return ans;
    }
    //step1 - level order traversal to mark parents
    unordered_map<TreeNode*,TreeNode*> parentMap;

    queue<TreeNode*> q;

    q.push(root);
    parentMap[root]=NULL;

    while(!q.empty()){
        TreeNode* frontNode = q.front();
        q.pop();

        if(frontNode->left){
            q.push(frontNode->left);
            parentMap[frontNode->left]=frontNode;
        }
        if(frontNode->right){
            q.push(frontNode->right);
            parentMap[frontNode->right]=frontNode;
        }
    }

    //step 2 - bfs from target node
    unordered_map<TreeNode*,bool> visited;


     helper(target,ans,k,0,visited,parentMap);
    return ans;
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        return printNodesAtDistanceK(root,target,k);
    }
};