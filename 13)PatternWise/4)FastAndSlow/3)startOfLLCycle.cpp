// Problem:https://leetcode.com/problems/linked-list-cycle-ii

/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{

private:
    // TC: O(n)
    // SC:O(n) //usage of hashSet
    ListNode *brute(ListNode *head)
    {
        unordered_set<ListNode *> sett;
        ListNode *curr = head;
        while (curr)
        {
            if (sett.count(curr)) // the first node to be seen again is the start of cycle
                return curr;
            sett.insert(curr);
            curr = curr->next;
        }
        return nullptr;
    }

    // TC:O(n)
    // SC:O(1)
    ListNode *optimal(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            // Once cycle detected, we reset either of pointer to head and move both of them by one till they meet
            //  and the point at which they will meet is the start of cycle (LOGIC: a long mathematical proof behind it)
            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // OR fast
            }
        }
        return nullptr;
    }

public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
            return nullptr;
        return optimal(head);
    }
};