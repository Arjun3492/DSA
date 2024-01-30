// Problem Statement: Given an array, print all the elements which are leaders.
// A Leader is an element that is greater than all of the elements on its right side in the array.

// BRUTE FORCE
// Run a nested loop to compare each element in array with elements after it
// if no element after it is greatest ,then add it to final array

vector<int> superiorElements(vector<int> &a)
{
  int n = a.size();
  vector<int> ans;
  for (int i = n - 1; i >= 0; i--)
  {
    int el = a[i];
    bool isLeader = true;
    for (int j = i + 1; j < n; j++)
    {
      if (el <= a[j])
      {
        isLeader = false;
        break;
      }
    }
    if (isLeader)
    {
      // no element to right is greater
      ans.emplace_back(el);
    }
  }

  return ans;
}

// BETTER
//  since we know that any element added to final array is greater than all the elements to its right
//  so check if the current element is > the last element added to ans array
vector<int> superiorElements(vector<int> &a)
{
  int n = a.size();
  vector<int> ans;
  for (int i = n - 1; i >= 0; i--)
  {
    int el = a[i];
    if (!ans.empty() && el > ans.back())
    {
      // checking if current el > last pushed element
      //  if yes then it will be larger than others on the right too
      ans.emplace_back(el);
    }
    else
    {

      bool isLeader = true;
      for (int j = i + 1; j < n; j++)
      {
        if (el <= a[j])
        {
          isLeader = false;
          break;
        }
      }
      if (isLeader)
      {
        ans.emplace_back(el);
      }
    }
  }

  return ans;
}

// OPTIMAL APPROACH
// using a pointer max the traversing the array from right
// if any element  if greater than max , update max and push element to final array
// sc:O(n)
// tc:O(n)
vector<int> superiorElements(vector<int> &a)
{
  int n = a.size();
  int max = a.back();
  vector<int> ans(1, max);
  for (int i = n - 2; i >= 0; i--)
  {
    if (a[i] > max)
    {
      max = a[i];
      ans.emplace_back(max);
    }
  }
  return ans;
}
