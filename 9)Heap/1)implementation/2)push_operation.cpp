// Implementation of Heap push operation with vector

// Approach:
// - Add the new element as a leaf node at the end of the heap (vector).
// - Move the new element up to restore the heap property:
//   - Compare the new element with its parent.
//   - Swap if the new element is greater than the parent.
//   - Repeat until the heap property is restored or the new element becomes the root.

void push(vector<int> &heap, int value)
{
    // Add the new element to the end of the heap
    heap.push_back(value);

    // Get the index of the newly added element
    int i = heap.size() - 1;

    // Move up the heap to maintain the max heap property
    while (i > 0)
    {
        int parent = (i - 1) / 2; // Calculate the index of the parent

        // If the current element is greater than its parent, swap them
        if (heap[i] > heap[parent])
        {
            swap(heap[i], heap[parent]);
            i = parent; // Update the index to the new position of the current element
        }
        else
        {
            break; // Break if the max heap property is satisfied
        }
    }
}
