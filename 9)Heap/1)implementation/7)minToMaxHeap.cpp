// Problem statment:Convert min heap to max heap
// Link : https://www.naukri.com/code360/problems/convert-min-heap-to-max-heap_1381084
// Example:
// Given min heap : [1,2,3,6,7,8]
// Output max heap : [8,7,3,6,2,1]

// Approach:
// - Utilize the `heapifyMax` function to adjust the heap:
//   - Start from the last non-leaf node and move upwards to the root.
//   - For each node, ensure it satisfies the max heap property by swapping it with its largest child if necessary.
//   - Recursively apply the `heapifyMax` function to restore the max heap property.

void heapifyMax(int i, vector<int> &arr)
{
    int n = arr.size();
    int maxi = i;
    int leftChild = i * 2 + 1;
    int rightChild = i * 2 + 2;
    if (leftChild < n && arr[leftChild] > arr[maxi])
    {
        maxi = leftChild;
    }
    if (rightChild < n && arr[rightChild] > arr[maxi])
    {
        maxi = rightChild;
    }
    if (i != maxi)
    {
        swap(arr[maxi], arr[i]);
        heapifyMax(maxi, arr);
    }
    return;
}

vector<int> MinToMaxHeap(int n, vector<int> &arr)
{
    // we start from n/2 because we want to start from the last non leaf node
    // leaf node index range is [n/2,n-1]
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapifyMax(i, arr);
    }
    return arr;
}