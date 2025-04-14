// Intuition: in heap sort, we push the root element to sorted list, swap it with last node and heapify again
//  We keep repeating this until all elements are stored in sorted list

// TC : Building a heap[O(n)] + heap sort(heapifying for each of 'n' elements [ O(n * log n) ])
// TC : O(n) + O(n * log n) = O(n * log n)

// Heapify Fn: Heapifies a tree at index i down till the leaf nodes
void heapify(vector<int> &arr, int i, int n)
{
    int min = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    if (leftChild < n && arr[leftChild] < arr[min])
    {
        min = leftChild;
    }

    if (rightChild < n && arr[rightChild] < arr[min])
    {
        min = rightChild;
    }

    if (i != min)
    {

        swap(arr[i], arr[min]);
        heapify(arr, min, n);
    }
}

void heapSort(vector<int> &arr)
{
    int n = arr.size();

    // since from (n/2) to n are leaf(single) nodes, hence already heapified
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }

    // temp arr to store the heap elements
    vector<int> temp;

    // Main heap sort logic
    for (int i = n - 1; i >= 0; i--)
    {
        temp.emplace_back(arr[0]);
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}