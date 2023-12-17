// Problem Statement: Given the heads of two singly linked-lists headA and headB,
// return the node at which the two lists intersect.
// If the two linked lists have no intersection at all, return null.

// Link:https://takeuforward.org/data-structure/find-intersection-of-two-linked-lists/

// Example 1:
// Input: https://lh5.googleusercontent.com/4WJ3tjiiLLRYeZOXd_o4BtSYdlsSnOwWKxTGIRW8qQfW9gFymPC710FCgiIrB6vTwwa-hR5WrtWjKOk-beBhD9WtH4nFi16W4f42FQAS0PTXiD_1LmPQYzwmn_eE2OChjKVGRVTy
// Output: Intersected at '2'
// Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).

// Brute Force Approach
//  For each node in the first linked list, traverse the second linked list.
//  If the node is present in the second linked list, return the node.
//  If the node is not present in the second linked list, return NULL.

// Time Complexity:O(n*m)
// Space Complexity:O(1)

Node *findIntersection(Node *firstHead, Node *secondHead)
{

    Node *firstCurr = firstHead;
    Node *secondCurr = secondHead;
    while (firstCurr != NULL)
    {
        while (secondCurr != NULL)
        {
            if (firstCurr == secondCurr)
            {
                return firstCurr;
            }
            secondCurr = secondCurr->next;
        }
        firstCurr = firstCurr->next;
        secondCurr = secondHead;
    }
    return NULL;
}

// BETTER APPROACH  : USING HASHING
// We create a set to store the addresses of the nodes of the first linked list.
// We iterate over the second linked list.
// If the address of the current node is present in the set, we return the current node.
// If the address of the current node is not present in the set, we insert the address of the current node in the set.
// If we reach the end of the second linked list, we return NULL.

// Time Complexity:O(n+m)
// Space Complexity:O(n)

Node *findIntersection(Node *firstHead, Node *secondHead)
{
    unordered_set<Node *> hashTable;
    while (firstHead != NULL)
    {
        hashTable.insert(firstHead);
        firstHead = firstHead->next;
    }
    while (secondHead != NULL)
    {
        if (hashTable.find(secondHead) != hashTable.end())
        {
            return secondHead;
        }
        secondHead = secondHead->next;
    }
    return NULL;
}

// BETTER APPROACH:USING DIFFERENCE IN LENGTHS
//  We calculate the length of the first linked list.
//  We calculate the length of the second linked list.
//  We calculate the difference between the lengths of the two linked lists.
//  We iterate over the linked list with greater length till the difference becomes zero.
//  We iterate over both the linked lists till the current nodes of both the linked lists are equal.
//  If the current nodes of both the linked lists are equal, we return the current node.
//  If the current nodes of both the linked lists are not equal, we continue the process.
//  If we reach the end of both the linked lists, we return NULL.
//  Time Complexity:O(2max(length of list1,length of list2))+O(abs(length of list1-length of list2))+O(min(length of list1,length of list2))
//  Space Complexity:O(1)

Node *solve(Node *firstHead, Node *secondHead, int diff)
{
    Node *firstCurr = firstHead;
    Node *secondCurr = secondHead;
    while (diff--)
    {
        firstCurr = firstCurr->next;
    }
    while (firstCurr != NULL && secondCurr != NULL)
    {
        if (firstCurr == secondCurr)
        {
            return firstCurr;
        }
        firstCurr = firstCurr->next;
        secondCurr = secondCurr->next;
    }
    return NULL;
}

Node *findIntersection(Node *firstHead, Node *secondHead)
{
    // BETTER ,using diff in length
    int len1 = 0, len2 = 0;
    Node *firstCurr = firstHead;
    Node *secondCurr = secondHead;
    while (firstCurr != NULL || secondCurr != NULL)
    {
        if (firstCurr != NULL)
        {
            len1++;
            firstCurr = firstCurr->next;
        }
        if (secondCurr != NULL)
        {
            len2++;
            secondCurr = secondCurr->next;
        }
    }

    return len1 > len2 ? solve(firstHead, secondHead, len1 - len2)
                       : solve(secondHead, firstHead, len2 - len1);
}

// OPTIMAL APPROACH : USING TWO POINTERS
// Take two dummy nodes for each list. Point each to the head of the lists.
// Iterate over them. If anyone becomes null, point them to the head of the opposite lists and continue iterating until they collide.
// INTUITION:https://lh3.googleusercontent.com/lQGGtwWBXL3Kvl15qC71jpZwvbokF4h963aahFBTd1fAathQjnPSbpxWbCaXv8c3OjJSaWJRot_Ug9WL85_SEPy9ShJxNNCLUFHTWsjS6pQKWGbGoK4Jhpe4Ebgr4VfbCWfOQ0uHC
// Time Complexity:O(n+m)
// Space Complexity:O(1)

Node *findIntersection(Node *firstHead, Node *secondHead)
{
    Node *firstCurr = firstHead;
    Node *secondCurr = secondHead;
    while (firstCurr != secondCurr)
    {
        if (firstCurr == NULL)
        {
            firstCurr = secondHead;
        }
        else
        {
            firstCurr = firstCurr->next;
        }
        if (secondCurr == NULL)
        {
            secondCurr = firstHead;
        }
        else
        {
            secondCurr = secondCurr->next;
        }
    }
    return firstCurr;
}