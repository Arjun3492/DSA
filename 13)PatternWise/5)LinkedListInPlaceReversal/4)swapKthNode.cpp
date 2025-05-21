// 1721. Swapping Nodes in a Linked List
// https://leetcode.com/problems/swapping-nodes-in-a-linked-list

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
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *first = head;
        ListNode *second = head;
        ListNode *fast = head;

        // Move fast pointer to the k-th node
        for (int i = 1; i < k; ++i)
        {
            fast = fast->next;
        }

        first = fast; // This is the k-th node from the beginning

        // Move fast to the end, and move second with it
        // So that second reaches the k-th node from the end
        // as fast pointer now have to move total-k steps towards the end
        while (fast->next)
        {
            fast = fast->next;
            second = second->next;
        }

        // Swap the values
        swap(first->val, second->val);

        return head;
    }
};