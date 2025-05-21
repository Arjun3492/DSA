// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list

/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode() : val(0), next(nullptr) {}
 *  ListNode(int x) : val(x), next(nullptr) {}
 *  ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
private:
    // This method utilize stack to reverse the linked list
    // TC:O(n)
    // SC:O(n)[Stack space]
    ListNode *brute(ListNode *head)
    {
        // Edge case:
        if (!head || !head->next)
            return head;
        // Pushing all the element into the stack
        stack<ListNode *> st;
        ListNode *curr = head;
        while (curr)
        {
            st.push(curr);
            curr = curr->next;
        }

        // new head
        head = st.top();
        st.pop();
        curr = head;
        while (!st.empty())
        {
            curr->next = st.top();
            curr = curr->next;
            st.pop();
        }
        // Pointing the last node to NULL
        curr->next = nullptr;
        return head;
    }
    // This method utilize three pointers "prev,curr and next" to perform in-place traversal
    //  very similar to how swap 2 numbers
    // TC:O(N)
    // SC:O(1)
    ListNode *optimal(ListNode *head)
    {
        ListNode *curr = head, *prev = nullptr;
        while (curr)
        {
            ListNode *next = curr->next; // temporarily storing the next node
            curr->next = prev;           // reversing the next pointer of current node
            prev = curr;                 // moving prev to curr node
            curr = next;                 // moving curr to next node
        }

        return prev;
    }

public:
    ListNode *reverseList(ListNode *head)
    {
        return optimal(head);
    }
};