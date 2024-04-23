// Maximum  Arbitiary Width of Binary Tree

// Problem statement:
//  Given the root of a binary tree, return the maximum width of the given tree.
//  The maximum width of a tree is the maximum width among all levels.

// The width of one level is defined as the length between the end-nodes (the leftmost and
// rightmost non-null nodes), where the null nodes between the end-nodes that would be present
// in a complete binary tree extending down to that level are also counted into the length calculation.

// Approach:
// Since we have to consider the null nodes as well, we will assign a unique index to each node.
//  We know that the left child of a node at index i is 2*i+1 and the right child is 2*i+2.(0-based indexing)
//  We will do a level order traversal and assign the index to each node.
//  At each level, we will calculate the width of the level by subtracting the index of the leftmost node from the index of the rightmost node.
//  We will keep track of the maximum width at each level and return the maximum width at the end.
//  To avoid overflow while calculating the index of children we will use relative indexing by subtracting the index of the first node of level from the index of the current node.
//  Time complexity: O(N), where N is the number of nodes in the tree.
//  Space complexity: O(N)[Queue space] .

// Function widthOfBinaryTree to find the
// maximum width of the Binary Tree
int widthOfBinaryTree(TreeNode *root)
{
    // If the root is null,
    // the width is zero
    if (!root)
    {
        return 0;
    }

    // Initialize a variable 'ans'
    // to store the maximum width
    int ans = 0;

    // Create a queue to perform level-order
    // traversal, where each element is a pair
    // of TreeNode* and its position in the level
    queue<pair<TreeNode *, int>> q;
    // Push the root node and its
    // position (0) into the queue
    q.push({root, 0});

    // Perform level-order traversal
    while (!q.empty())
    {
        // Get the number of
        // nodes at the current level
        int size = q.size();
        // Get the position of the front
        // node in the current level
        int mmin = q.front().second;

        // Store the first and last positions
        // of nodes in the current level
        int first, last;

        // Process each node
        // in the current level
        for (int i = 0; i < size; i++)
        {
            // Calculate current position relative
            // to the minimum position in the level
            int cur_id = q.front().second - mmin;
            // Get the current node
            TreeNode *node = q.front().first;
            // Pop the front node from the queue
            q.pop();

            // If this is the first node in the level,
            // update the 'first' variable
            if (i == 0)
            {
                first = cur_id;
            }

            // If this is the last node in the level,
            // update the 'last' variable
            if (i == size - 1)
            {
                last = cur_id;
            }

            // Enqueue the left child of the
            // current node with its position
            if (node->left)
            {
                q.push({node->left, cur_id * 2 + 1});
            }

            // Enqueue the right child of the
            // current node with its position
            if (node->right)
            {
                q.push({node->right, cur_id * 2 + 2});
            }
        }

        // Update the maximum width by calculating
        // the difference between the first and last
        // positions, and adding 1
        ans = max(ans, last - first + 1);
    }

    // Return the maximum
    // width of the binary tree
    return ans;
}