// Inorder Traversal
// Problem statement
// You have been given a Binary Tree of 'n' nodes, where the nodes have integer values.
// Your task is to return the In-Order traversal of the given binary tree.

// Link : https://www.naukri.com/code360/problems/inorder-traversal_3839605

// Driver code
vector<int> getInOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return {};
    vector<int> inorderList;
    helper(root, inorderList);
    return inorderList;
}

// Recursive Approach:
// We will use a recursive approach to solve this problem.
// We will create a helper function that will take the root node and a vector as input.
// The helper function will call itself recursively on the left subtree.
// Then it will push the current node value to the vector.
// Then it will call itself recursively on the right subtree.

void recHelper(TreeNode *root, vector<int> &inorderList)
{
    if (root == nullptr)
        return;
    recHelper(root->left, inorderList);
    inorderList.push_back(root->data);
    recHelper(root->right, inorderList);
}

// Iterative Approach
// We will use an iterative approach to solve this problem.
// We keep moving to the leftmost node until(node->left==nullptr) and push the nodes into the stack.
// Once we reach the end(node->left==nullptr) , we pop the top element from the stack(the previous inserted left node) and push it into the ans vector.
// Then we move to the right node of the popped element so that we can traverse the right subtree.

void iterativeHelper(TreeNode *root, vector<int> &inorderList)
{
    stack<TreeNode *> s;
    TreeNode *curr = root;
    while (curr != nullptr || !s.empty()) // if curr is not null or stack is not empty
    {
        while (curr != nullptr) // keep moving to the leftmost node until there exist another left node
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top(); // pop the top element from the stack(the previous inserted left node)
        s.pop();
        inorderList.push_back(curr->data); // push it into the ans vector
        curr = curr->right;                // handle the right subtree
    }
}