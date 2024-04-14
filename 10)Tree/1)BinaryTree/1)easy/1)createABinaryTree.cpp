// Create Binary Tree
// Link : https://www.naukri.com/code360/problems/create-binary-tree_8360671

// Intuition:
//  Since we have to create a binary tree from the given array, using the level order traversal .
//  We will use a queue to maintain the level order traversal and create the tree accordingly.
//  At first we will create the root node and push it into the queue.
//  Then we will iterate over the array and create the left and right nodes and push them into the queue.
//  We will continue this process until the queue is empty and the entire array is traversed.

Node *createTree(vector<int> &arr)
{

    // edge case if arr is empty
    if (arr.empty())
        return NULL;

    // Creating the root node and pushing it inside queue
    Node *root = new Node(arr[0]);
    queue<Node *> q;
    q.push(root);

    int i = 1;

    // until the queue is not empty and the
    // entire array is not traversed
    while (!q.empty() && i < arr.size())
    {

        // picking the front element(node),so that the level wise order is maintained
        Node *curr = q.front();
        q.pop();

        // Linking the left node and pushing it into queue
        Node *left = new Node(arr[i++]);
        curr->left = left;
        q.push(left);

        // Linking the right node and pushing it into queue
        if (i < arr.size())
        {
            Node *right = new Node(arr[i++]);
            curr->right = right;
            q.push(right);
        }
    }

    return root;
}