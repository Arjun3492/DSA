# Linked List In-Place Reversal

## 🔍 1. When Should Linked List In-Place Reversal Be Used?

### ✅ Use this pattern when:
- You need to **reverse all or part of a linked list**.
- You are asked to **reverse nodes in groups**, or **rotate** the list.
- You want to **modify the list structure directly** without extra memory (O(1) space).

### 🧠 Keywords to look for:
- “Reverse linked list”
- “In-place”
- “Reverse between positions left and right”
- “Reverse in groups of k”
- “Rotate the list”
- “Do not use extra space”

---

## 💣 2. Brute Force Approach (Without In-Place Reversal)

### Example: Reverse Linked List using stack (extra space)

```cpp
ListNode* reverseList(ListNode* head) {
    stack<int> s;
    //Storing the node data in stack
    ListNode* curr = head;
    while (curr) {
        s.push(curr->data);
        curr = curr->next;
    }

    //Resetting curr to head 
    ListNode curr = head;
    while (!s.empty()) {
        //overwriting the nodes data using the stack enteries
        curr->data = s.top();
        s.pop();
        curr = curr->next;
    }

    return curr;
}
```

### ⛔ Time: O(n), Space: O(n)

---

## 🛠️ 3. How In-Place Reversal Works (With C++ Templates)

### 💡 Core Idea:
Reverse the pointers of the list while traversing it using **three pointers**: `prev`, `curr`, and `next`.

---

### ✅ Template 1: Reverse Entire Linked List (In-place)

```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr) {
        ListNode* next = curr->next; // save next node
        curr->next = prev;           // reverse the link
        prev = curr;                 // move prev forward
        curr = next;                 // move curr forward
    }

    return prev;
}
```

---

### ✅ Template 2: Reverse a Sublist Between Positions `left` and `right`

```cpp
// Function to reverse the sublist using Template 1
ListNode *reverseBetween1(ListNode *head, int left, int right)
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

// In this in each iteration we move curr one place right and bring the "next" to the front
ListNode *reverseBetween2(ListNode *head, int left, int right)
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
```

---

### ✅ Template 3: Reverse in Groups of K

```cpp
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* curr = head;
    int count = 0;
    
    // Check if there are at least k nodes
    while (curr && count < k) {
        curr = curr->next;
        count++;
    }

    if (count < k) return head;

    // Reverse first k nodes
    ListNode* prev = nullptr;
    curr = head;
    for (int i = 0; i < k; i++) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // head is now the tail of the reversed group
    head->next = reverseKGroup(curr, k);
    return prev;
}
```

---

## 📚 4. Common Problems Based on This Pattern

### 🟢 Easy
- [Leetcode 206](https://leetcode.com/problems/reverse-linked-list/) – Reverse Linked List

### 🟡 Medium
- [Leetcode 92](https://leetcode.com/problems/reverse-linked-list-ii/) – Reverse Linked List II
- [Leetcode 61](https://leetcode.com/problems/rotate-list/) – Rotate List
- [Leetcode 25](https://leetcode.com/problems/reverse-nodes-in-k-group/) – Reverse Nodes in k-Group

### 🔴 Hard
- [Leetcode 1721](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/) – Swapping Nodes in a Linked List (uses reversal concepts)
- [Leetcode 430](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/) – Flatten Multilevel Doubly Linked List
