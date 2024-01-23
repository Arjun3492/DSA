// return the union of two array such that the union only consist of unique elements

// SET CONTAINER APPROACH
// as a set only contains unique elements,
// we can insert all the elements of both the arrays in a set and return
// the set as a vector

// TC: O(n+m)
// SC: O(n+m)
vector<int> setApproach(vector<int> arr1, vector<int> arr2)
{
  set<int> UninonSet;
  int a = arr1.size();
  int b = arr2.size();
  int n = min(a, b);
  int i = 0;
  while (i < n)
  {
    UninonSet.emplace(arr1[i]);
    UninonSet.emplace(arr2[i]);
    i++;
  }
  while (i < a)
  {
    UninonSet.emplace(arr1[i]);
    i++;
  }
  while (i < b)
  {
    UninonSet.emplace(arr2[i]);
    i++;
  }
  return {UninonSet.begin(), UninonSet.end()};
}

// 2 POINTER APPROACH FOR SORTED ARRAY
// TC: O(n+m)
// SC: O(1)
vector<int> sortedArray(vector<int> arr1, vector<int> arr2)
{
  int i = 0, j = 0; // pointers
  int n = arr1.size();
  int m = arr2.size();
  vector<int> Union; // Union vector
  while (i < n && j < m)
  {
    if (arr1[i] < arr2[j]) // Case 1
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    }
    else if (arr1[i] > arr2[j]) // case 2
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
    else // case 3 ,both elements are equal
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
      j++;
    }
  }
  while (i < n) // IF any elements are left in arr1
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // If any elements are left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}