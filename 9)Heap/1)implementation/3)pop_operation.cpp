// Implementation of Heap pop operation with vector

// Approach:
// - Replace the root element with the last element (last leaf node).
// - Remove the last element from the heap.
// - Apply heapify to the root to restore the heap property:
//   - Move the root element down by swapping it with the larger of its children until the heap property is restored.

int pop(vector<int> &heap)
{
    // Get the size of the heap
    int n = heap.size();

    // Check if the heap is empty
    if (heap.empty())
    {
        return -1; // Return -1 to indicate that the heap is empty
    }

    // Store the maximum element (root of the max heap)
    int maxEl = heap[0];

    // Swap the root with the last element and remove the last element
    swap(heap[0], heap[n - 1]);
    heap.pop_back();
    n--;

    // Start from the root (index 0) and move down to maintain the max heap property
    int i = 0;
    while (i < n)
    {
        // Calculate indices of left and right children
        int leftElAt = 2 * i + 1;
        int rightElAt = 2 * i + 2;

        // Determine the index of the greater child,while checking if the bounds are exceeded
        int greaterElAt = (rightElAt < n && heap[rightElAt] > heap[leftElAt]) ? rightElAt : leftElAt;

        // Check if the current element is less than the greater child
        if (greaterElAt < n && heap[i] < heap[greaterElAt])
        {
            // Swap the current element with the greater child
            swap(heap[i], heap[greaterElAt]);
            // Update the index to the new position of the current element
            i = greaterElAt;
        }
        else
        {
            // If the current element is greater than both children, break out of the loop
            break;
        }
    }

    // Return the maximum element that was removed from the heap
    return maxEl;
}
