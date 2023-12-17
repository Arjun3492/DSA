// Problem statement :Given a vector of size n, make a linked list from the vector and return the head of the linked list.

class Node
{

public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

// Approach 1: Iterative
// We iterate over the vector and create a new node for each element of the vector.
// We set the data of the node to the element of the vector.
// We set the next of the node to NULL.
// We set the next of the previous node to the current node.
// We return the head of the linked list.
// Time complexity: O(n)
// Space complexity: O(1)
// where n is the size of the vector.

Node *constructLL(vector<int> &arr)
{
    int n = arr.size();
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < n; i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

// Approach 2: Recursive
// We create a new node for the current element of the vector.
// We set the data of the node to the element of the vector.
// We set the next of the node to the return value of the recursive call for the next element of the vector.
// We return the current node.
// Time complexity: O(n)
// Space complexity: O(n)
// where n is the size of the vector.

Node *constructLL(vector<int> &arr, int i)
{
    if (i == arr.size())
    {
        return NULL;
    }
    Node *newNode = new Node(arr[i]);
    newNode->next = constructLL(arr, i + 1);
    return newNode;
}