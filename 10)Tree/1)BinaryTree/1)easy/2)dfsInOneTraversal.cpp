// Tree Traversals
// Problem statement
// You have been given a Binary Tree of 'N'
// nodes, where the nodes have integer values.

// Your task is to return the ln-Order, Pre-Order, and Post-Order traversals of the given binary tree.

// Link : https://www.naukri.com/code360/problems/tree-traversal_981269

// Intuition:
//  We will use the Depth First Search (DFS) algorithm to traverse the tree.
//  We will use a stack of pairs to maintain the nodes and their traversal status.
//  We will start by pushing the root node into the stack.
// We will then iterate over the stack until it is empty following the following three rules:
// 1.If the status of the node is 1, we will add  it to the pre-order traversal list  and  update the status to 2 and push the left child of the node into the stack(if it exists).
// 2.If the status of the node is 2, we will add  it to the in-order traversal list update the status to 3 and push the right child of the node into the stack(if it exists).
// 3.If the status of the node is 3, we will add  it to the post-order traversal list.

// The time complexity of this approach is O(N) where N is the number of nodes in the tree.

vector<vector<int>> getTreeTraversal(TreeNode *root)
{

    if (root == NULL)
        return {};

    // creating a stack of node and number pair
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});

    vector<int> inorder, preorder, postorder;

    while (!st.empty())
    {

        // Selecting the top element of stack
        pair<TreeNode *, int> it = st.top();
        st.pop();

        // if its value is 1
        if (it.second == 1)
        {
            preorder.push_back(it.first->data); // adding it to the preorder list

            st.push({it.first, 2}); // updating the status to 2

            if (it.first->left != NULL) // if left child exists
            {
                st.push({it.first->left, 1});
            }
        }
        // if its value is 2
        else if (it.second == 2)
        {
            inorder.push_back(it.first->data); // adding it to the inorder list
            st.push({it.first, 3});            // updating the status to 3
            if (it.first->right != NULL)       // if right child exists
            {
                st.push({it.first->right, 1});
            }
        } // if its value is 3
        else
        {
            postorder.push_back(it.first->data); // adding it to the postorder list
        }
    }

    return {inorder, preorder, postorder};
}