// Problem Statement: To find the length of loop in linked list if present, else return 0.

// Example 1:
// Input:LinkedList: 1->2->3->4->5->2
// Output: 4
// Explanation: The loop is 2->3->4->5->2. Therefore, length=4.

// Example 2:
// Input: LinkedList: 2->3->4->7
// Output: 0
// Explanation: The loop is not present.

// BRUTE FORCE APPROACH
// We use a map to hash the address of the nodes of the linked list along with their position.
// We iterate over the linked list and check if the address of the current node is present in the map or not.
// If the address of the current node is present in the map, we return the difference between the current position and the position of the node in the map.
// Else, we insert the address of the current node in the map along with its position.
// If we reach the end of the linked list, we return 0.
// Time complexity: O(n)
// Space complexity: O(n)

// Intuition:  Total length traversed - The position of the node where the loop starts = length of loop
// image ref:https://media.geeksforgeeks.org/wp-content/uploads/20200417215415/GfG-linked-list.png

// Code Snippet:
int countNodesinLoop(struct Node *head)
{
    // Code here
    map<Node *, int> mpp;
    int totalTraversed = 0;
    while (head)
    {
        if (mpp.find(head) != mpp.end())
        {
            // if the address of the current node is present in the map,
            // we return the difference between the total length traversed and the position of the node where the loop start in the map.

            return totalTraversed - mpp[head];
        };
        mpp[head] = totalTraversed;
        totalTraversed++;
        head = head->next;
    }
    return 0;
}

// OPTIMIZED APPROACH
// We use two pointers slow and fast.
// We iterate over the linked list till the next of the fast pointer is NULL.
// We move the slow pointer by one and the fast pointer by two.
// If the slow pointer and the fast pointer meet, we break out of the loop.
// We set the slow pointer to the head.
// We iterate over the linked list till the slow pointer and the fast pointer meet.
// Now the slow pointer points to the starting point of loop .
// We create a temp pointer and set it to the slow pointer.
// We iterate over the linked list till the next of the temp pointer is equal to the slow pointer.(Traversing the loop)
// We increment the count by one.
// We return the count.
// Time complexity: O(n)
// Space complexity: O(1)

// Intuition: https://www.youtube.com/watch?v=LUm2ABqAs1w

int countNodesinLoop(struct Node *head)
{
    // Code here
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
        }
        if (slow == fast)
        {
            break;
        }
    }
    if (fast->next == NULL)
    {
        return 0;
    }
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *temp = slow;
    int count = 1;
    while (temp->next != slow)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
