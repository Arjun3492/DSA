// In selection sort ,in each iteration we select the next
// smallest element to place at current index

// TC : O(n^2)
// SC : O(n)

void selectionSort(vector<int> &arr)
{
    // outer loop:num of times we need to run the iteration
    // n-1 times : 0 to n-2
    int n = arr.size();

    for (int i = 0; i < n - 2; i++)
    {

        // let assume for the current index i
        int smallestIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallestIdx])
            {
                smallestIdx = j;
            }
        }
        if (smallestIdx != i)
        {
            swap(arr[smallestIdx], arr[i]);
        }
    }
}
