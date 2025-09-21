Problem Statement: Given a String, find the length of longest substring without any repeating character.

Solution 1: Brute force Approach
Approach: This approach consists of taking the two loops one for traversing the string and another loop - nested loop for finding different substrings and after that,
we will check for all substrings one by one and check for each and every element if the element is not found then we will store that element in HashSet otherwise we will break from the loop and count it.

Solution 2: Optimised  Approach 1
Approach: We will have two pointers left and right. Pointer ‘left’ is used for maintaining the starting point of the substring while ‘right’ will maintain the
endpoint of the substring.’ right’ pointer will move forward and check for the duplicate occurrence of the current element if found then the ‘left’ pointer will be shifted ahead so as to delete the duplicate elements.

#include <bits/stdc++.h>
#include<unordered_set>

using namespace std;

int solve(string str) {

  if(str.size()==0)
      return 0;
  int maxans = INT_MIN;
  unordered_set < int > set;
  int l = 0;
  for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
  {
    if (set.find(str[r]) != set.end()) //if duplicate element is found
    {
      while (l < r && set.find(str[r]) != set.end()) {
        set.erase(str[l]);
        l++;
      }
    }
    set.insert(str[r]);
    maxans = max(maxans, r - l + 1);
  }
  return maxans;
}


Solution 3: Optimised  Approach 2
Approach: In this approach, we will make a map that will take care of counting the elements and maintaining the frequency of each and every element as a unity by taking the latest index of every element.

#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    int lengthofLongestSubstring(string s) {
      vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
};