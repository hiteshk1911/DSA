Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.



Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

//Brute Force
- Find all the substrings and check if they contain all characters of t

//Optimal Approach
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m =t.size();

        int minLen = INT_MAX , startIndex = -1 ,count=0;
        int left = 0 ,right = 0;

        unordered_map<char,int> freq;

        for(int i=0;i<m;i++){
            freq[t[i]]++;
        }

        while(right < n){
            //count of characters matched
            if(freq[s[right]]>0){
                count = count + 1;

            }
            freq[s[right]]--;

            //shrinking the window
            // valid window has all characters of t
            while(count == m){
                if(right-left+1<minLen){
                    minLen = right-left+1;
                    startIndex = left;
                }

                freq[s[left]]++;
                if(freq[s[left]]>0){
                    count = count - 1;
                }
                left++;
            }
            right = right + 1;
        }
        return startIndex == -1 ? "":s.substr(startIndex,minLen);
    }
};