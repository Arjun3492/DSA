// Implement Max heap
// Max heap is a complete binary tree where the value of each node is greater than or equal to the value of its parent

class MaxHeap
{
private:
    vector<int> heap;

    // Helper function to heapify (maintain the max heap property)
    void heapify(int i)
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

public:
    // Function to insert a new element into the heap
    void push(int value)
    {
        heap.push_back(value);

        int i = heap.size() - 1;

        // Move the new element up the heap as needed
        while (i > 0 && heap[(i - 1) / 2] < heap[i])
        {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Function to remove and return the maximum element from the heap
    int pop()
    {
        if (heap.empty())
        {
            cout << "Heap is empty. Cannot pop.\n";
            return -1; // Return a sentinel value to indicate an empty heap
        }

        int maxEl = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();

        // Heapify the root to maintain the max heap property
        heapify(0);

        return maxEl;
    }

    // Function to print the elements of the heap
    void display()
    {
        cout << "Max Heap: ";
        for (int value : heap)
        {
            cout << value << " ";
        }
        cout << "\n";
    }
};

int main()
{
    MaxHeap maxHeap;

    // Insert elements into the max heap
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(15);
    maxHeap.push(40);
    maxHeap.push(50);

    // Display the current state of the max heap
    maxHeap.display();

    // Pop the maximum element and display the updated heap
    cout << "Popped element: " << maxHeap.pop() << "\n";
    maxHeap.display();

    return 0;
}
