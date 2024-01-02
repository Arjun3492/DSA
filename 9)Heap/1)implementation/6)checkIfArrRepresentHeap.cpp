// Problem Statment: Given an array arr check weather it represents a max heap

bool doesRespresentMaxHeap(int arr)
{
    int n = arr.size();

    for (int i = (n / 2) - 1; i >= 0; i--)
    // we start from n/2 because we want to start from the last non leaf node
    // leaf node index range is [n/2,n-1]
    {
        int leftChild = i * 2 + 1;
        int rightChild = i * 2 + 2;
        if (leftChild < n && arr[leftChild] < arr[i])
        {
            return false;
        }
        if (rightChild < n && arr[rightChild] < arr[i])
        {
            return false;
        }
        return true;
    }
}