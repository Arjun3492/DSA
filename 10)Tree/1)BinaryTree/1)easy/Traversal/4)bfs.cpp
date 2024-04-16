// Level Order Traversal
// Problem statement
// You are given a ‘Binary Tree’.
// Return the level-order or BFS traversal of the Binary Tree.

// Link : https://www.naukri.com/code360/problems/zigzag-binary-tree-traversal_920532

// Approach:
// We will use a queue to maintain the nodes.
// We will push the root node into the queue at first.
// and while the queue is not empty, we will pop the front element from the queue and push it into the ans vector.
// Then we will push the left and right child of the popped element into the queue.
// this will help follow the level order traversal.

vector<int> levelOrder(TreeNode<int> *root)
{
    vector<int> lvlOrderList; // to store the level order traversal
    queue<TreeNode<int> *> q; // to maintain the nodes
    q.push(root);             // pushing the root node into the queue

    // while the queue is not empty
    while (!q.empty())
    {

        // pushing the front element of the queue into the ans vector
        TreeNode<int> *node = q.front();
        lvlOrderList.push_back(node->data);
        q.pop();

        // pushing the left and right child of the popped element into the queue
        // so that in next iteration we can traverse the left and right nodes
        if (node->left != nullptr)
            q.push(node->left);
        if (node->right != nullptr)
            q.push(node->right);
    }
    return lvlOrderList;
}
