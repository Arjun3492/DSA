// Problem Statment: Given an array arr check weather it represents a max heap

// Approach:
// - Start from `n/2` (last non-leaf node) because leaf nodes don't need to be checked.
// - Iterate from `n/2` to the root:
//   - If the left child of a node is greater than the parent, return false.
//   - If the right child of a node is greater than the parent, return false.
// - If all nodes satisfy the max heap property, return true.

bool doesRespresentMaxHeap(int arr)
{
    int n = arr.size();

    for (int i = (n / 2) - 1; i >= 0; i--)
    // we start from n/2 because we want to start from the last non leaf node
    // leaf node index range is [n/2,n-1]
    {
        int leftChild = i * 2 + 1;
        int rightChild = i * 2 + 2;

        // if left child is smaller than parent then return false
        if (leftChild < n && arr[leftChild] < arr[i])
        {
            return false;
        }

        // if right child is smaller than parent then return falseS
        if (rightChild < n && arr[rightChild] < arr[i])
        {
            return false;
        }
        return true;
    }
}