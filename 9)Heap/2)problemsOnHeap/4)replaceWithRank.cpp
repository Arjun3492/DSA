// Replace Each Element Of Array With Its Corresponding Rank
//  Given an array of integers, replace each element of the array with its corresponding rank in the array.
// If two elements have the same value, their rank will be the same.

// Example :
// Input: arr[] = {10, 8, 15, 12, 6, 20, 1}
// Output: arr[] = {4, 3, 6, 5, 2, 7, 1}
// Explanation:
// The element with value 10 has rank 4 as it is the 4th element of the array.
// The element with value 8 has rank 3 as it is the 3rd element of the array.
// and so on.

// Approach 1: Brute Force
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// We will traverse the array and for each element we will find its rank by traversing the array again

// Approach 2: Using Sorting
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
// We will sort the array and then we will traverse the array and for each element we will find its rank by traversing the sorted array

// Approach 3: Using Hashing
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
// We will create a map and store the element and its index in the map
// then we will sort the array and then we will traverse the array and for each element we will find its rank by traversing the map

// Approach 4: Using Min Heap
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

typedef pair<int, int> pii;
vector<int> replaceWithRank(vector<int> &arr, int n)
{

    vector<int> ans(n);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // push {element,i} in pq
    for (int i = 0; i < n; i++)
    {
        pq.push({arr[i], i});
    }

    int rank = 0;

    int lastel = INT_MIN; // for the equal elements check

    while (pq.size())
    {

        pii temp = pq.top();

        if (temp.first != lastel)
        { // if the elements are not equal

            rank++;

            lastel = temp.first;
        }

        ans[temp.second] = rank; // store the rank in ans

        pq.pop(); // pop the element;
    }

    return ans;
}
