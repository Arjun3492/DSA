// Subarray With Maximum Product
// Problem statement
// Given an array ‘Arr’ that has ‘N’ elements.
// You have to find the subarray of ‘Arr’ that has the largest product.
// You must return the product of the subarray with the maximum product

// Link:https://www.codingninjas.com/studio/problems/subarray-with-maximum-product_6890008

// Example:
// Input: [2, 3, -2, 4]
// Output: 6
// Explanation: The subarray [2, 3] has the maximum product 6.

// BRUTE FORCE
// We will use nested loop to compute all the possible subarrays, and for each subarray we will
// compute the product and check if it is maximum
// Time complexity: O(n^3) ,can be reduced to O(n^2) by removing the third nested loop
// Space complexity: O(1)

int subarrayWithMaxProduct(vector<int> &arr)
{
    int n = arr.size();
    int maxProduct = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int product = 1;
            for (int k = i; k <= j; k++)
            {
                product *= arr[k];
            }
            maxProduct = max(maxProduct, product);
        }
    }
    return maxProduct;
}

// OPTIMAL APPROACH 1 (KADANE'S ALGORITHM)
// We will use Kadane's algorithm to solve this problem
// We will keep track of the maximum product ending at each index
// We will also keep track of the minimum product ending at each index
// We will keep track of the maximum product so far
// Time complexity: O(n)
// Space complexity: O(1)

int subarrayWithMaxProduct(vector<int> &arr)
{
    int n = arr.size();
    int maxProduct = arr[0];
    int minProduct = arr[0];
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap(maxProduct, minProduct);
        }
        maxProduct = max(arr[i], maxProduct * arr[i]);
        minProduct = min(arr[i], minProduct * arr[i]);
        result = max(result, maxProduct);
    }
    return result;
}

// OPTIMAL APPROACH 2
//  Intuition we know that maximum product would be obtained by subarray to the right or left of negative number
//  So we will traverse the array from left and right and keep track of maximum product
// In case of 0 we will reset the product to 1
//  Time complexity: O(n)
//  Space complexity: O(1)

int subarrayWithMaxProduct(vector<int> &arr)
{
    int n = arr.size();
    int maxProduct = INT_MIN;
    int prefixProduct = 1, postfixProduct = 1;
    ;
    for (int i = 0; i < n; i++)
    {
        prefixProduct *= arr[i];
        postfixProduct *= arr[n - i - 1];
        maxProduct = max(maxProduct, max(prefixProduct, postfixProduct));
        if (arr[i] == 0)
            prefixProduct = 1;
        if (arr[n - i - 1] == 0)
            postfixProduct = 1;
    }
    return maxProduct;
}
