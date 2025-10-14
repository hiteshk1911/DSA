class Solution {
public:
    // In-order traversal to get sorted node values
    void inorder(TreeNode* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    // Build balanced BST from sorted array
    TreeNode* buildBalancedBST(vector<int>& v, int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(v[mid]);
        node->left = buildBalancedBST(v, start, mid - 1);
        node->right = buildBalancedBST(v, mid + 1, end);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sorted;
        inorder(root, sorted);
        return buildBalancedBST(sorted, 0, sorted.size() - 1);
    }
};

🧠 Why the Current Approach Doesn't Fully Use the BST Property

Your current approach:

In-order traversal → gives a sorted list of node values

Rebuilds the tree from scratch using those values to create a balanced BST

But what it doesn't do is:

Preserve original tree nodes

Avoid creating new nodes

Avoid extra memory where possible

This means you're treating the BST like a sorted array — ignoring the fact that it's already a tree and its nodes already exist in memory.

🔄 So What Could Be Done Instead?

There are two improvements, depending on what you're optimizing for:

✅ Option 1: Rebuild Using BST Node Pointers (Avoid New Allocations)

Instead of storing just the values in the vector<int>, you can store pointers to the original nodes in a vector<TreeNode*>, and then rebuild the balanced BST reusing those nodes.

This:

Keeps the same node identities

Avoids unnecessary memory allocations

✔ Updated Plan:

Do an in-order traversal of the BST and store pointers: vector<TreeNode*>

Use the same buildBalancedBST() logic, but set left and right pointers directly on the existing nodes.

✅ Option 2: Balance the BST in-place Without Array

This is more complex. To do it truly in-place, you'd need to:

Convert the BST into a sorted doubly linked list

Then build a balanced BST using slow/fast pointers or count-based recursion

But that adds code complexity and is rarely required unless:

Memory allocations are expensive

You must preserve the original node structure exactly

✅ Optimized Version: Reuse Nodes Instead of Recreating
class Solution {
public:
    void inorder(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }

    TreeNode* buildBalancedTree(vector<TreeNode*>& nodes, int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* root = nodes[mid];

        root->left = buildBalancedTree(nodes, start, mid - 1);
        root->right = buildBalancedTree(nodes, mid + 1, end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        inorder(root, nodes);
        return buildBalancedTree(nodes, 0, nodes.size() - 1);
    }
};

✅ Advantages of This Version

Fully utilizes the BST property (in-order gives sorted nodes)

Preserves original node identity (TreeNode*)

No need to create new nodes → saves time and memory

Time: O(n), Space: O(n) for vector, O(log n) recursion stack

🧩 Summary
Approach	Uses BST Property?	Reuses Nodes?	Time	Space
Original (with values)	✔️ (in-order only)	❌ No	O(n)	O(n)
With node pointers	✔️ Yes	✔️ Yes	O(n)	O(n)
In-place (DLL to BST)	✔️ Yes	✔️ Yes	O(n)	O(1)*

*DLL method reduces array space but increases code complexity.

🧠 High-Level Strategy: In-place BST → Balanced BST

We'll use a two-step method:

Step 1: Convert BST to a Sorted Doubly Linked List (DLL)

Do in-order traversal

Link nodes into a doubly linked list:

left → prev

right → next

Step 2: Convert Sorted DLL to Balanced BST

Use a recursive method with a count of nodes

At each recursive step:

Build left subtree from first n/2 nodes

Use current node as root

Build right subtree from remaining nodes

✅ Step-by-Step Code
class Solution {
public:
    TreeNode* prev = nullptr;

    // Step 1: Convert BST to Doubly Linked List (left = prev, right = next)
    void bstToDLL(TreeNode* root, TreeNode*& head) {
        if (!root) return;

        bstToDLL(root->left, head);

        if (!prev) {
            head = root;  // First node becomes head of DLL
        } else {
            prev->right = root;
            root->left = prev;
        }
        prev = root;

        bstToDLL(root->right, head);
    }

    // Step 2: Convert Sorted DLL to Balanced BST
    TreeNode* sortedDLLToBST(TreeNode*& head, int n) {
        if (n <= 0) return nullptr;

        // Recursively build left subtree
        TreeNode* leftSubtree = sortedDLLToBST(head, n / 2);

        // Root node is current head
        TreeNode* root = head;
        root->left = leftSubtree;

        // Move head forward
        head = head->right;

        // Recursively build right subtree
        root->right = sortedDLLToBST(head, n - n / 2 - 1);

        return root;
    }

    // Count total nodes in DLL
    int countNodes(TreeNode* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->right;
        }
        return count;
    }

    TreeNode* balanceBST(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode* head = nullptr;
        prev = nullptr;

        // Step 1: Convert BST to DLL
        bstToDLL(root, head);

        // Step 2: Convert sorted DLL to Balanced BST
        int n = countNodes(head);
        return sortedDLLToBST(head, n);
    }
};

🔍 How It Works
1. bstToDLL

Recursively does in-order traversal

Links nodes as a doubly linked list using left and right

2. sortedDLLToBST

Recursively builds balanced BST:

Left subtree from first half

Middle node becomes root

Right subtree from second half

3. O(1) Extra Space

No arrays or vectors

Just recursion stack

✅ Time & Space Complexity
Metric	Complexity
Time	O(n)
Space	O(log n)
Extra Memory	O(1) (no arrays)
📌 Visual Intuition

This method is similar to building a balanced BST from a sorted array — but instead of an array, you're walking through a linked list in-order, one node at a time.

🧩 Summary

✅ No extra space (no vector)
✅ No new nodes created
✅ Preserves original structure
✅ Uses BST properties fully
✅ Elegant in-place solution