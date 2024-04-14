// Preorder Binary Tree
// Problem statement
// You are given a ‘Binary Tree’.
// Return the preorder traversal of the Binary Tree.

// Link : https://www.naukri.com/code360/problems/preorder-binary-tree_5948

// Template:
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Recursive Approach
void recursiveHelper(TreeNode<int> *root, vector<int> &ans)
{

    // Base case : If root if null
    if (root == NULL)
        return;

    // pushing the current node value to ans
    ans.push_back(root->data);

    // calling recursiveHelper on left sub tree
    recursiveHelper(root->left, ans);

    // calling recursiveHelper on right sub tree

    recursiveHelper(root->right, ans);
}

// Driver function
vector<int> preOrder(TreeNode<int> *root)
{
    vector<int> ans;
    recursiveHelper(root, ans);
    return ans;
}

// Iterative Approach
void iterativeHelper(TreeNode<int> *root, vector<int> &ans)
{
    if (root == nullptr)
        return;

    stack<TreeNode<int> *> st;
    st.push(root);

    while (!st.empty())
    {

        // pushing the top node of stack to ans
        TreeNode<int> *node = st.top();
        st.pop();
        ans.push_back(node->data);

        // Pushing right child first so that it gets processed after left child(root->left->right)
        if (node->right != nullptr)
            st.push(node->right);

        if (node->left != nullptr)
            st.push(node->left);
    }
}

// Driver function
vector<int> preOrder(TreeNode<int> *root)
{
    vector<int> ans;
    iterativeHelper(root, ans);
    return ans;
}
