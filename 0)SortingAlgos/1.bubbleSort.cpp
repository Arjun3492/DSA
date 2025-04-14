// Intuition : In each iteration we place the current largest element at its correct position towards the right
//  by comparision are swapping with adjacent elements

// TC : O(n^2)
// SC : O(n)

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();

    // outer loop : number of times each iteration needs to run
    // since in bubble sort with each iteration one el is placed at its correct position in right, we need to run n-1 iterations:0 to n-2

    for (int i = 0; i <= n - 2; i++)
    {

        bool swapped = false;
        // inner loop , we keep swapping elements from start to end of unsorted array
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            // no swaps means the array is sorted
            break;
        }
    }
}