// PROBLEM : Linked List Cycle
// https: // leetcode.com/problems/linked-list-cycle

class Solution
{
private:
    // TC:O(n)
    //  SC:O(n) , since we are using extra space (hashset)
    bool brute(ListNode *head)
    {
        unordered_set<ListNode *> sett; // using hashset
        ListNode *curr = head;

        while (curr)
        {
            if (sett.count(curr)) // if current node was seen before ,its a cycle
                return true;

            sett.insert(curr);
            curr = curr->next;
        }

        return false; // not a cycle
    }

    // TC:O(n)
    // SC:O(1) // no extra space
    bool optimal(ListNode *head)
    {
        ListNode *slow = head; // slow pointer
        ListNode *fast = head; // fast pointer

        while (fast && fast->next)
        {
            slow = slow->next;       // moving slow by 1
            fast = fast->next->next; // moving fast by 2
            if (slow == fast)
                return true;
        }
        return false;
    }

public:
    bool hasCycle(ListNode *head)
    {
        return optimal(head);
    }
};