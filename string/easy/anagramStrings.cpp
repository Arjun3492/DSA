//Check if two Strings are anagrams of each other
// Problem Statement: Given two strings, check if two strings are anagrams of each other or not.

//Two strings are anagrams if the count of every letter of both strings are equal.
//Example: s1 = "listen", s2 = "silent"
//Both strings have the same count of letters, hence they are anagrams of each other.
//Example: s1 = "aab", s2 = "abb"
//Both strings do not have the same count of letters, hence they are not anagrams of each other.

//Approach 1: Brute Force
//We generate all possible permutations of the string s1 and check if any of the permutations is equal to the string s2.
//Time complexity: O(n!)
//Space complexity: O(n)
//where n is the length of the string s1.

//Approach 2: Sorting
//We sort both the strings and check if they are equal.
//Time complexity: O(nlogn)
//Space complexity: O(n)
bool isAnagram(string str1, string str2) {
  // Write your code here
  if (str1.size() != str2.size()) {
    return false;
  }

  sort(str1.begin(), str1.end());
  // O(nlogn)
  sort(str2.begin(), str2.end());
  // O(nlogn)
  return str1 == str2;
}


//Optimized Approach
//We use a frequency array(initially all 0) to store the count of every letter of the string s1.(hashing)
//We iterate over the string s2 and decrement the count of every letter of the string s2 in the frequency array.
//We iterater over the frequency array and check if the count of every letter is 0.
//If the count of every letter is 0, then the strings are anagrams of each other.
//if not then we break the loop and return false.
//Time complexity: O(n)
//Space complexity: O(n)
bool isAnagram(string str1, string str2) {
 
  if (str1.size() != str2.size()) {
    return false;
  }

  vector<int> freq(26, 0);
  int _isAnagram=true;
 for(char ch:str1){
     freq[ch-'a']++;
 }
 for(char ch:str2){
     freq[ch-'a']--;
 }
 for(int i :freq){
     if(i!=0){
         _isAnagram=false;
         break;
     }
 }
 return _isAnagram;
}