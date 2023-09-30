//BRUTE FORCE APPROACH
// for every element we will find every other element
string read(int n, vector<int> book, int target)
{
    for(int i =0;i<n;i++){
        for(int j=i+1;j<n;j++){

            if(book[i]+book[j]==target){
                return "YES";
            }
        }
    }
    return "NO";
}


//OPTIMAL APPROACH
//Using hashmap ,
// for each element i we will check if their exist a key in map which is equal to rem,where rem= target-i; 
// if exist return TRUE
//else we will store the book pages and index i pair in map, for future use

string read(int n, vector<int> book, int target) {
  // Write your code here.

  map<int, int> hashMap;
  // brute force approach
  for (int i = 0; i < n; i++) {
    // for(int j=i+1;j<n;j++){
    //     if(book[i]+book[j]==target){
    //         return "YES";
    //     }

    int rem = target - book[i];
    if (hashMap.find(rem) != hashMap.end()) {
      return "YES";
    }
    hashMap[book[i]] = i;
  }
return "NO";

}

