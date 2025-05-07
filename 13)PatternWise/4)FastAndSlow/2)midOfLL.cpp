// https://leetcode.com/problems/middle-of-the-linked-list
// Find the middle of LL

/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{

private:
    // TC: O(n + n/2)
    ListNode *brute(ListNode *head)
    {
        int len = 0;

        ListNode *curr = head;
        while (curr)
        {
            len++;
            curr = curr->next;
        }

        len = len / 2 + 1;
        ListNode *mid = head;
        while (--len)
        {
            mid = mid->next;
        }

        return mid;
    }

    // TC:O(n)
    ListNode *optimal(ListNode *head)
    {
        // slow and fast pointer technique
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // when fast has reached the end, slow is at mid
        return slow;
    }

public:
    ListNode *middleNode(ListNode *head)
    {
        return optimal(head);
    }
};