//// Implement Min heap
//// Min heap is a complete binary tree where the value of each node is less than or equal to the value of its parent

#include <iostream>
#include <vector>

using namespace std;

class MinHeap
{
private:
    vector<int> heap;

    // Helper function to heapify (maintain the min heap property)
    void heapify(int i)
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

public:
    // Function to insert a new element into the heap
    void push(int value)
    {
        heap.push_back(value);

        int i = heap.size() - 1;

        // Move the new element up the heap as needed
        while (i > 0 && heap[(i - 1) / 2] > heap[i])
        {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Function to remove and return the minimum element from the heap
    int pop()
    {
        if (heap.empty())
        {
            cout << "Heap is empty. Cannot pop.\n";
            return -1; // Return a sentinel value to indicate an empty heap
        }

        int minEl = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();

        // Heapify the root to maintain the min heap property
        heapify(0);

        return minEl;
    }

    // Function to print the elements of the heap
    void display()
    {
        cout << "Min Heap: ";
        for (int value : heap)
        {
            cout << value << " ";
        }
        cout << "\n";
    }
};

int main()
{
    MinHeap minHeap;

    // Insert elements into the min heap
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(15);
    minHeap.push(40);
    minHeap.push(50);

    // Display the current state of the min heap
    minHeap.display();

    // Pop the minimum element and display the updated heap
    cout << "Popped element: " << minHeap.pop() << "\n";
    minHeap.display();

    return 0;
}
