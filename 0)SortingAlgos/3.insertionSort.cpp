// In insertion sort ,in each iteration we insert elements from the right unsorted elements
// to its correct postion in left sorted array by shifting them one place each

// TC : O(n^2)
// SC : O(n)

void insertionSort(vector<int> &arr)
{

    // outerloop n-1 times : 1 to n-1
    int n = arr.size();
    for (int i = 1; i <= n - 1; i++)
    {
        int curr = arr[i];
        int prev = i - 1;
        // shifting elements in the left sorted array to right to make space for curr element at its right index
        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}