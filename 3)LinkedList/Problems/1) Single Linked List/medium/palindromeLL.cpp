// Problem Statement: Given the head of a singly linked list, return true if it is a palindrome else return false.

// Approach 1: Brute force
// We use a vector to store the elements of the linked list.
// We then use the two pointer approach to check if the vector generated is a palindrome or not.
// Time complexity: O(n)
// Space complexity: O(n)

bool isPalindrome(Node *head)
{
    vector<int> vec;
    Node *curr = head;
    while (curr)
    {
        vec.push_back(curr->data);
        curr = curr->next;
    }
    int l = 0, r = vec.size() - 1;
    while (l <= r)
    {
        if (vec[l] != vec[r])
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

// OPTIMIZED APPROACH
// We use the two pointer approach to find the middle of the linked list.
// We reverse the linked list from the middle to the end.
// We use two pointers to check if the linked list is a palindrome or not.
// OPTIONAL STEP: We reverse the linked list from the middle to the end again.[to restor the original linked list]
// Time complexity: O(n/2[finding the middle el] + n/2[reversing the right half] + n/2[checking for palindrome]) = O(n)
// Space complexity: O(1)

bool isPalindrome(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    // STEP 1 =>Finding the middle element
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
        }
    }
    // STEP 2=> Reversing the right half of the linked list
    Node *curr = slow->next;
    Node *prev = NULL;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    // STEP 3=>  Comparing the left half and the right half of the linked list
    Node *left = head;
    Node *right = prev;
    while (right != NULL)
    {
        if (left->data != right->data)
        {
            return false;
        }
        left = left->next;
        right = right->next;
    }
    return true;
}