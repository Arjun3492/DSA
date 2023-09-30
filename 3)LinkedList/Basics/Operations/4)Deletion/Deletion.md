# Deletion

## Complexity Analysis

| Operation             | Space Complexity                                      | Time Complexity |
| --------------------- | ----------------------------------------------------- | --------------- |
| Deletion at beginning | O(1)                                                  | O(1)            |
| Deletion at end       | O(1) if pointer to end node is given else O(n)        | O(1)            |
| Deletion in middle    | O(1) if pointer to the target_node is given else O(n) | O(1)            |

### You can delete an element in a list from:

1. Beginning
2. End
3. Middle

## **Deletion from the beginning**

To delete a node from the beginning of the list, we need to change the next pointer of the last node(in case of circular LL) and free the memory for the node to be deleted.

![Deletion from the beginning](image.png)

#### Algorithm:

1. If the list is empty, return NULL.
2. Else, move the head pointer to the next node (head = head->next).
3. Free the memory for the original head node.

```cpp
// Function to delete the head of the list
void deleteHead(Node** head_ref)
{
    // If linked list is empty
    if (*head_ref == NULL)
        return;

    // Store the pointer to the head node
    Node* temp = *head_ref;

    // Move head to next node
    *head_ref = (*head_ref)->next;

    // Delete the previous head
    free(temp);
}
```

## **Deletion from the end**

To delete a node from the end of the list, we need to change the next pointer of the second last node to NULL and free the memory for the node to be deleted.

![Deletion from the end](image-1.png)

#### Algorithm:

1. If the list is empty, return NULL.
2. Else, traverse to the second last node of the list.
3. Change the next pointer of the second last node to NULL.
4. Free the memory for the original last node.

```cpp
// Function to delete the last node
// of the list
void deleteLast(Node** head_ref)
{
    // If linked list is empty
    if (*head_ref == NULL)
        return;

    // If the list contains only a single node
    if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }

    // Else, traverse to the second last node
    Node* temp = *head_ref;
    while (temp->next->next != NULL)
        temp = temp->next;

    // Delete the last node
    free(temp->next);

    // Change next of second last
    temp->next = NULL;
}
```

## **Deletion from the middle**

To delete a node from the middle of the list, we need to change the next pointer of the previous node to the next node and free the memory for the node to be deleted.

![Deletion from the middle](image-2.png)

#### Algorithm:

1. If the list is empty, return NULL.
2. Else, traverse to the node to be deleted.
3. Change the next pointer of the previous node to the next node.
4. Free the memory for the node to be deleted.

```cpp
// Function to delete a node from
// the middle of the linked list
void deleteMiddle(Node** head_ref)
{
    // Base cases
    if (*head_ref == NULL)
        return;
    if ((*head_ref)->next == NULL) {
        delete (*head_ref);
        return;
    }

    // Find the previous node of the node to be deleted
    Node* temp = *head_ref;
    Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    // Delete the node
    prev->next = temp->next;

    delete temp;
}
```

## **Deletion at the given position k**

To delete a node at the given position k, we need to change the next pointer of the previous node to the next node and free the memory for the node to be deleted.

![Deletion at the given position k](image-3.png)

#### Algorithm:

1. If the list is empty, return NULL.
2. Else, traverse to the node to be deleted.
3. Change the next pointer of the previous node to the next node.
4. Free the memory for the node to be deleted.

```cpp
// Function to delete a node at the given position
void deleteAtPosition(Node** head_ref, int position)
{
    // If linked list is empty
    if (*head_ref == NULL)
        return;

    // Store head node
    Node* temp = *head_ref;

    // If head needs to be removed
    if (position == 0) {
        // Change head
        *head_ref = temp->next;

        // Free old head
        free(temp);
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    Node* next = temp->next->next;

    // Unlink the node from linked list
    free(temp->next); // Free memory

    temp->next = next; // Unlink the deleted node from list
}
```
