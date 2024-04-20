// Binary Tree Zigzag Traversal
// Problem statement
// You have been given a Binary Tree of 'N' nodes, where the nodes have integer values.
// Your task is to print the zigzag traversal of the given tree.

// Note:
// In zigzag order, level 1 is printed from left to right fashion, level 2 is printed from right to
// left. and level 3 is printed from left to right again, and so on…..

// Link : https://www.naukri.com/code360/problems/zig-zag-traversal_1062662

// Approach
// We will follow the level order traversal of the tree with a slight modification.
// We will maintain a flag to keep track of the current direction of traversal.
// At each level, we will push the nodes in the current level into the ans list in the required direction and invert the direction for the next level.

// Time Complexity : O(N) ,as we are traversing each node once.
// Space Complexity : O(N) ,as we are using a queue to store the nodes of the tree.

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    // if tree is empty(null tree) , returing an empty list
    if (root == nullptr)
        return ans;

    // intially pushing the root node into the queue
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    // a flag var to keep track of the direction for  each row
    bool leftToRight = true;

    // Level order traversal loop
    while (!q.empty())
    {

        // creating a rowVec to store all the elements of the current row
        int rowSize = q.size();
        vector<int> rowVec(rowSize);

        // traversing each node of the curr row(elements currently in the queue)
        for (int i = 0; i < rowSize; i++)
        {

            // popped this node of the queue
            auto currNode = q.front();
            q.pop();
            // pushing its children into the queue
            if (currNode->left)
                q.push(currNode->left);
            if (currNode->right)
                q.push(currNode->right);

            // based on the leftToRight flag we will add the node value into the
            // rowVec
            int idx = leftToRight ? i : rowSize - i - 1;
            rowVec[idx] = currNode->data;
        }
        // once all the nodes of a given row are processed

        // inverting the value of leftToRight flag for  the next row
        leftToRight = !leftToRight;
        // pushing the elements of rowVec in the ans ds
        ans.insert(ans.end(), rowVec.begin(), rowVec.end());
    }
    return ans;
}
