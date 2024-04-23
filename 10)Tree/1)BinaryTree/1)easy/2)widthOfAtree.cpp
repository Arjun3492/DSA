// Maximum Width In Binary Tree
// Problem statement
// You have been given a Binary Tree of integers. You are supposed to return
// the maximum width of the given Binary Tree. The maximum width of the tree
// is the maximum width among all the levels of the given tree.

// The width of one level is defined as the length between the leftmost and the
// rightmost, non-null nodes in the level, where the null nodes in between the
// leftmost and rightmost are excluded into length calculation.

// Link : https://www.naukri.com/code360/problems/maximum-width-in-binary-tree_763671

// Approach :
// We will follow a level order traversal and at each level, we will calculate the
// width of the level using the size of the queue at the start of each new level.
// At each level, we will remove the existing nodes from the queue and add their children in the queue.

// Time complexity: O(N), where N is the number of nodes in the tree.
// Space complexity: O(max_width)[Queue space] .

int getMaxWidth(TreeNode<int> *root)
{
    int ans = 0;
    // Edge case: if null tree
    if (!root)
        return ans;
    // Queue for level order traversal
    queue<TreeNode<int> *> q;
    // Pushing the root node intially
    q.push(root);

    // Level order traversal
    while (!q.empty())
    {
        int rowSize = q.size();  // Width of the current level
        ans = max(ans, rowSize); // Updating the maximum width

        for (int i = 0; i < rowSize; i++) // Iterating over the current level, removing the existing nodes and adding their children
        {
            auto currNode = q.front();
            q.pop();
            if (currNode->left)
                q.push(currNode->left);
            if (currNode->right)
                q.push(currNode->right);
        }
    }

    return ans;
}
