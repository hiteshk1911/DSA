Problem Statement
1.You have a binary tree with integer values, and you need to check if it is possible to divide the tree into two separate trees,
by cutting one edge, such that both trees have the same total sum of nodes.

//Solution 1
- Calculate the total sum of all nodes in the tree using a depth-first search (DFS) traversal.
- If the total sum is odd, return false, as it cannot be split into two equal parts.
- If the total sum is even, perform another DFS traversal to check if there exists a subtree with a sum equal to half of the total sum.

//Solution 2
- Use a hash set to store the sums of all subtrees during a single DFS traversal.

