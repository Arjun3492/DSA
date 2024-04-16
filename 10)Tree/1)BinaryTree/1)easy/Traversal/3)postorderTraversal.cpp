// Postorder Traversal
// Problem statement
// You have been given a Binary Tree of 'n' nodes, where the nodes have integer values.Your task is to return its postorder traversal.

// Link : https://www.naukri.com/code360/problems/postorder-traversal_2035933

// Helper function
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> postOrderList;
    helper(root, postOrderList);
    return postOrderList;
}

// Recursive Approach:
// We will use a recursive approach to solve this problem.
// We will create a helper function that will take the root node and a vector as input.
// The helper function will call itself recursively on the left subtree.
// Then it will call itself recursively on the right subtree.
// Then it will push the current node value to the vector.

void helper(TreeNode *root, vector<int> &postOrderList)
{
    if (root == nullptr)
        return;

    // left->right->root
    helper(root->left, postOrderList);   // calling recursiveHelper on left sub tree
    helper(root->right, postOrderList);  // calling recursiveHelper on right sub tree
    postOrderList.push_back(root->data); // pushing the current node value to ans
}

// Iterative Approach
// We will use an iterative approach to solve this problem.
// We will use two stacks to maintain the nodes.
// We will push the root node into the first stack.
// Then we will iterate over the first stack until it is empty.
// We will pop the top element from the first stack and push it into the second stack.
// Then we will push the left and right child of the popped element into the first stack.
// Finally, we will return the elements of the second stack in reverse order.

void helper(TreeNode *root, vector<int> &postOrderList)
{

    stack<TreeNode *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        // take the top node of stack1 and push it to stack2
        TreeNode *node = st1.top();
        st1.pop();
        st2.push(node);

        // if this node has a left or right node push it to stack 1
        if (node->left != nullptr)
            st1.push(node->left);
        if (node->right != nullptr)
            st1.push(node->right);
    }

    // finally pop all the nodes from stack 2
    while (!st2.empty())
    {
        postOrderList.push_back(st2.top()->data); // pushing the current node value to ans
        st2.pop();
    }
}

// Iterative Approach using one stack
// Here we are using the same logic as the iterative approach of the preorder traversal but with a slight modification.
// We will push the root node first and then push the left child and then the right child.
// so that the right child gets processed first and then the left child.
// It will give us a root->right->left traversal .
// When we reverse the traversal we will get the postorder traversal. (left->right->root)

void helper(TreeNode *root, vector<int> &postOrderList)
{
    if (root == nullptr)
        return;

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        postOrderList.push_back(node->data);

        if (node->left != nullptr)
            st.push(node->left);

        if (node->right != nullptr)
            st.push(node->right);
    }

    reverse(postOrderList.begin(), postOrderList.end());
}
