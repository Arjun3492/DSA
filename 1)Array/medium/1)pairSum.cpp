// Two Sum : Check if a pair with given sum exists in Array
// Problem Statement: Given an array of integers arr[] and an integer target,
// Return YES if there exist two numbers such that their sum is equal to the target.
// Otherwise, return NO

// BRUTE FORCE APPROACH
//  for every element we will find every other element
string read(int n, vector<int> book, int target)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {

      if (book[i] + book[j] == target)
      {
        return "YES";
      }
    }
  }
  return "NO";
}

// OPTIMAL APPROACH
// Using hashmap ,
//  for each element i we will check if their exist a key in map which is equal to rem,where rem= target-i;
//  if exist return TRUE
// else we will store the book pages and index i pair in map, for future use

string read(int n, vector<int> book, int target)
{

  map<int, int> hashMap;
  for (int i = 0; i < n; i++)
  {

    // Checking if remainder previously exists in hashMap i.e. it has been traversed
    int rem = target - book[i];
    if (hashMap.find(rem) != hashMap.end())
    {
      return "YES";
    }
    // STEP 2: Store the current element in hashMap
    hashMap[book[i]] = i;
  }
  return "NO";
}
