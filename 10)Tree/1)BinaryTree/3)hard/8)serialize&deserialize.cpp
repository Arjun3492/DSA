// Serialize and Deserialize Binary Tree
// Problem statement
// You have been given a binary tree of integers.
// You are supposed to serialize and deserialize (refer to notes) the given binary tree.

// You can choose any algorithm to serialize/deserialize the given binary tree.
// You only have to ensure that the serialized string can be deserialized to the original binary tree.

// Link : https://www.naukri.com/code360/problems/serialize-and-deserialize-binary-tree_920328

// Approach
// Serialize
// 1. We will do a level order traversal of the tree and store the nodes value in a string
// 2. For the null nodes we will store a special character to represent null

// Deserialize
// 1. We will create a queue and push the root node in the queue
// 2. We will iterate over the string and pop the front node from the queue
// 3. If the current character is not null then we will create a new node and assign the value to the node
// 4. We will push the left and right child of the node in the queue
// 5. If the current character is null then we will assign the left and right child of the node as null

string serializeTree(TreeNode<int> *root)
{
    if (!root)
        return "";
    string str;
    queue<TreeNode<int> *> q;
    q.push(root);
    // Level order traversal
    while (!q.empty())
    {
        TreeNode<int> *curr = q.front();
        q.pop();
        // Append the node value to the string, if the node is null then append #(special character for null node)
        string tmp = curr != nullptr ? to_string(curr->data) + "," : "#,";
        str.append(tmp);
        // If the node is not null then push the left and right child of the node in the queue
        if (curr)
        {

            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return str;
}

TreeNode<int> *deserializeTree(string &serialized)
{
    // Return nullptr if the string is empty or contains only a null node
    if (serialized.empty() || serialized == "#,")
        return nullptr;

    queue<TreeNode<int> *> q;
    TreeNode<int> *root = nullptr;
    string nodeValue;

    // Read the root node value from the serialized string
    int pos = 0;

    // Read the root node value from the serialized string,(Eg 55,so we will read 55 from the string)
    while (pos < serialized.size() && serialized[pos] != ',')
    {
        nodeValue += serialized[pos];
        pos++;
    }
    pos++; // Move past the comma

    // Intializing the root node
    root = new TreeNode<int>(stoi(nodeValue));
    q.push(root);

    while (pos < serialized.size())
    {
        TreeNode<int> *curr = q.front();
        q.pop();

        // READING LEFT CHILD VALUE FROM THE SERIALIZED STRING
        nodeValue = "";
        while (pos < serialized.size() && serialized[pos] != ',')
        {
            nodeValue += serialized[pos];
            pos++;
        }
        pos++; // Moving past the comma
        if (nodeValue != "#")
        {
            curr->left = new TreeNode<int>(std::stoi(nodeValue));
            q.push(curr->left);
        }

        // READING RIGHT CHILD VALUE FROM THE SERIALIZED STRING
        nodeValue = "";
        while (pos < serialized.size() && serialized[pos] != ',')
        {
            nodeValue += serialized[pos];
            pos++;
        }
        pos++; // Moving past the comma
        if (nodeValue != "#")
        {
            curr->right = new TreeNode<int>(std::stoi(nodeValue));
            q.push(curr->right);
        }
    }

    return root;
}
