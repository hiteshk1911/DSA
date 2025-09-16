Binary Tree: where each node can have at most two children nodes, known as the left child and the right child.

Full Binary Tree:
A Full Binary Tree, also known as a Strict Binary Tree, adheres to the structural property where every node has either zero or two children.
No node of this tree has just a single child, all internal nodes have exactly two children or in the case of leaf nodes, no children.

Complete Binary Tree:
A Complete Binary Tree is a specialised form of Binary Tree where all levels are filled completely except possibly the last level, which is filled from left to right.
All levels of the tree, except possibly the last one, are fully filled. If the last level is not completely filled, it is filled from left to right, ensuring that nodes are positioned as far left as possible.

Perfect Binary Tree:
A Perfect Binary tree is a type of Binary Tree where all leaf nodes are at the same level and the number of leaf nodes is maximised for that level.
Properties of perfect binary trees make them efficient for certain operations like searching and sorting due to their balanced nature. However, achieving and maintaining perfect balance, especially when the number of nodes is not a power of two, might not be feasible in many practical applications.

Balanced Binary Tree:
A Balanced Binary tree is a type of Binary Tree where the heights of the two subtrees of any node differ by at most one. This property ensures that the tree remains relatively well-balanced, preventing the tree from becoming highly skewed or degenerate.
In a balanced binary tree, the height of the tree should be log2N at maximum, where N is the number of nodes.

Degenerate Tree:
A Degenerate Tree is a Binary Tree where the nodes are arranged in a single path leaning to the right or left. The tree resembles a linked list in its structure where each node points to the next node in a linear fashion.

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}

class Tree{
public:
    Node* root;

    Tree() {
        root = nullptr;
    }
}

