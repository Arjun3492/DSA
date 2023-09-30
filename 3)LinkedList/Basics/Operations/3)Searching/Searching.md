# Search an element in a Linked List

## Complexity Analysis:

| Operation            | Time Complexity | Space Complexity                         |
| -------------------- | --------------- | ---------------------------------------- |
| Search (Iteratively) | O(n)            | O(1)                                     |
| Search (Recursively) | O(n)            | O(n) Stack space used by recursive calls |

## Iterative Method:

### Algorithm:

1. Initialize a node pointer, current = head.
2. Do following while current is not NULL
   1. If the current value (i.e., current->key) is equal to the key being searched return true.
   2. Otherwise, move to the next node (current = current->next).
3. If the key is not found, return false

### Code:

```cpp
// Iterative C++ program to search
// an element in linked list

/* Checks whether the value x is present in linked list */
bool search(Node* head, int x)
{
	Node* current = head; // Initialize current
	while (current != NULL) {
		if (current->key == x)
			return true;
		current = current->next;
	}
	return false;
}
```

## Recursive Method:

### Algorithm:

1. Initialize a node pointer, current = head.
2. If current is NULL, return false.
3. If current->key (current value is equal to the key being searched), return true.
4. Otherwise, return search(current->next, x) (recursive call for the rest of the list).

### Code:

```cpp
// Recursive C++ program to search
// an element in linked list
#include <bits/stdc++.h>
using namespace std;

/* Checks whether the value x is present in linked list */
bool search(struct Node* head, int x)
{
	// Base case
	if (head == NULL)
		return false;

	// If key is present in current node, return true
	if (head->key == x)
		return true;

	// Recur for remaining list
	return search(head->next, x);
}
```
