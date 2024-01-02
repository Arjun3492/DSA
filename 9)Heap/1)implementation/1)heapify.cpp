// Heapify is a helper function that takes an index i and recursively moves the element at that index down the heap until it is in the correct position. The heapify function is called in the pop function to maintain the max heap property after the root is removed.

void heapifyMaxHeap(int i)
{
    int n = heap.size();
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Compare with left child
    if (left < n && heap[left] > heap[largest])
    {
        largest = left;
    }

    // Compare with right child
    if (right < n && heap[right] > heap[largest])
    {
        largest = right;
    }

    // If the largest is not the current node, swap and recursively heapify
    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        heapify(largest);
    }
}

void heapifyMinHeap(int i)
{
    int n = heap.size();
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Compare with left child
    if (left < n && heap[left] < heap[smallest])
    {
        smallest = left;
    }

    // Compare with right child
    if (right < n && heap[right] < heap[smallest])
    {
        smallest = right;
    }

    // If the smallest is not the current node, swap and recursively heapify
    if (smallest != i)
    {
        swap(heap[i], heap[smallest]);
        heapify(smallest);
    }
}
