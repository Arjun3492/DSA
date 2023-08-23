//return the union of two array such that the union only consist of unique elements


//Set container approach
vector<int> setApproach(vector<int> arr1, vector<int> arr2) {
  set<int> UninonSet;
  int a = arr1.size();
  int b = arr2.size();
  int n = min(a, b);
  int i = 0;
  while (i < n) {
    UninonSet.emplace(arr1[i]);
    UninonSet.emplace(arr2[i]);
    i++;
  }
  while (i < a) {
    UninonSet.emplace(arr1[i]);
    i++;
  }
  while (i < b) {
    UninonSet.emplace(arr2[i]);
    i++;
  }
  return {UninonSet.begin(),UninonSet.end()};
}


//2 pointer approach for sorted array
vector<int> sortedArray(vector<int> arr1, vector<int> arr2) {
  int i = 0, j = 0; // pointers
  int n = arr1.size();
  int m = arr2.size();
  vector<int> Union; // Uninon vector
  while (i < n && j < m) {
    if (arr1[i] < arr2[j]) // Case 1 and 2
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    } else if (arr1[i] > arr2[j]) // case 3
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    } else {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
      j++;
    }
  }
  while (i < n) // IF any element left in arr1
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}