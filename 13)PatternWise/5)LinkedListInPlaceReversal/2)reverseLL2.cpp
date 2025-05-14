// 92. Reverse Linked List II

// https://leetcode.com/problems/reverse-linked-list-ii
class Solution
{
private:
    // will reverse the part of LL[left,right] using in place reversal technique
    // TC:O(n)
    // SC:O(1)
    ListNode *approach1(ListNode *head, int left, int right)
    {
        // Edge case: empty list, single node list, or no need to reverse
        if (!head || !head->next || left == right)
            return head;

        // Dummy node is used to simplify edge cases, especially when left == 1
        ListNode dummy(0);
        dummy.next = head;

        // 'prev' will eventually point to the node just before the 'left' position
        ListNode *prev = &dummy;

        // Move 'prev' to the (left - 1)th node
        for (int i = 1; i < left; i++)
        {
            prev = prev->next;
        }

        // Step 2: Initialize pointers for reversal(InPlace reversal Technique)
        // 'curr' points to the 'left'th node (start of sublist)
        ListNode *curr = prev->next;
        // 'prevSub' will become the new head of the reversed sublist
        ListNode *prevSub = nullptr;

        // Step 3: Reverse the sublist from 'left' to 'right'
        for (int i = 1; i <= right - left + 1; i++)
        {
            ListNode *next = curr->next; // Save next node
            curr->next = prevSub;        // Reverse current node's pointer
            prevSub = curr;              // Move 'prevSub' forward
            curr = next;                 // Move 'curr' forward
        }

        // Step 4: Connect the reversed sublist back to the main list

        // 'prev->next' is still pointing to the original 'left'th node (now the tail of reversed sublist)
        // Connect its 'next' to the node after right (which is curr when the loop ends)
        prev->next->next = curr;

        // Connect node before 'left' to the new head of the reversed sublist
        prev->next = prevSub;

        // Return the new head of the list (dummy.next handles case where head is modified)
        return dummy.next;
    }

    // In this approach, we reverse the sublist by performing multiple "head insertions".
    // In each iteration, we move the next node after 'curr' to the front of the sublist.
    ListNode *approach2(ListNode *head, int left, int right)
    {
        // Dummy node is used to simplify edge cases, especially when left == 1
        ListNode dummy(0);
        dummy.next = head;

        // 'prev' will eventually point to the node just before the 'left' position
        ListNode *prev = &dummy;

        // Move 'prev' to the (left - 1)th node
        for (int i = 1; i < left; i++)
        {
            prev = prev->next;
        }

        // 'curr' points to the 'left'th node, which will be the tail of the reversed sublist
        ListNode *curr = prev->next;

        // Perform (right - left) head insertions to reverse the sublist
        for (int i = 0; i < right - left; i++)
        {
            // 'next' is the node to be moved to the front of the reversed sublist
            ListNode *next = curr->next;

            // Step 1: Remove 'next' from its current position
            curr->next = next->next;

            // Step 2: Insert 'next' right after 'prev'
            next->next = prev->next;
            prev->next = next;
        }

        // Return the new head of the list (dummy.next handles case where head is modified)
        return dummy.next;
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        return approach1(head, left, right);
    }
};