// Problem Statement: Given a Linked list that has two pointers in
// each node and one of which points to the first node and the other
// points to any random node. Write a program to clone the LinkedList.

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *random;
 *		Node() : data(0), next(nullptr), random(nullptr){};
 *		Node(int x) : data(x), next(nullptr), random(nullptr) {}
 *		Node(int x, Node *next, Node *random) : data(x), next(next),
 *random(random) {}
 * };
 */

// APPRAOCH 1: Using Hashing
//   1) Create a map to store the mapping from original list nodes to cloned list nodes.
//   2) Traverse the original list and clone the nodes as well as store the mapping from original list nodes to cloned list nodes in the map.
//   3) Traverse the original list again and using the map update the next and random pointers of cloned list nodes.
//   4) Return the head of the cloned list.

// Complexity: 1) Time Complexity O(n)
//             2) Space Complexity O(n)

Node *cloneLL(Node *head)
{

    // Create a map to store the mapping from original list nodes to cloned list nodes.
    unordered_map<Node *, Node *> hash;

    // Traverse the original list and clone the nodes as well as store the mapping from original list nodes to cloned list nodes in the map.
    Node *curr = head;
    while (curr != nullptr)
    {
        hash[curr] = new Node(curr->data);
        curr = curr->next;
    }

    // Traverse the original list again and using the map update the next and random pointers of cloned list nodes.
    curr = head;
    while (curr != nullptr)
    {
        hash[curr]->next = hash[curr->next];
        hash[curr]->random = hash[curr->random];
        curr = curr->next;
    }

    // Return the head of the cloned list.
    return hash[head];
}

// OPTIMIZED APPROACH: Without using extra space
//   1) Create a copy node of the current node and insert it between the current node and the next node.
//   2) Traverse the list and link the random pointers of the copy nodes.[curr->next(COPYNODE)->random = curr->random->next]
//   3) Separate the copy and original list.
//   4) Return the head of the copy list.

// Complexity: 1) Time Complexity O(n)
//             2) Space Complexity O(1)

Node *cloneLL(Node *head)
{
    if (head == nullptr)
    {
        return head;
    }
    if (head->next == nullptr)
    {
        return new Node(head->data);
    }

    // Step 1:inserting copy nodes in between
    Node *curr = head;
    while (curr)
    {
        Node *copyNode = new Node(curr->data);
        copyNode->next = curr->next;
        curr->next = copyNode;
        curr = copyNode->next;
    }

    // Step 2: linking pointers of the copy nodes
    curr = head;
    while (curr)
    {
        if (curr->random != nullptr)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    // Step 3: Separating copy and original list
    curr = head;
    Node *copyHead = curr->next;
    while (curr)
    {
        curr->next = curr->next->next;
        curr = curr->next;
    }
    return copyHead;
}