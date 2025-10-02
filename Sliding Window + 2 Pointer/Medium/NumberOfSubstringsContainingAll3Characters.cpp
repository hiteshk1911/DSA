Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.



Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb".
Example 3:

Input: s = "abc"
Output: 1


Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.

//Brute Force
- Find all the substrings and check if they contain all 3 characters

//Better Approach
- Find all the substrings with at most 3 distinct characters and subtract from it the substrings with at most 2 distinct characters

class Solution {
    int numberOfSubstringsWithAtMostKDistinctCharacters(string s, int k) {
        int n = s.size();
        if (n == 0 || k == 0) return 0;

        unordered_map<char, int> freq;  // character -> count
        int left = 0, right = 0, ans = 0;

        while (right < n) {
            // expand window
            freq[s[right]]++;

            // shrink window if more than k distinct
            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }

            // valid window has <= k distinct characters
            ans = ans + (right - left + 1);
            right++;
        }
        return ans;
    }
public:
    int numberOfSubstrings(string s) {
        return numberOfSubstringsWithAtMostKDistinctCharacters(s,3)-numberOfSubstringsWithAtMostKDistinctCharacters(s,2);
    }
};

//Better Approach 2
class Solution {
    int numberOfSubstringsWithAtMostKDistinctCharacters(string s, int k) {
        int n = s.size();
        if (n == 0 || k == 0) return 0;

        unordered_map<char, int> freq;  // character -> count
        int left = 0, right = 0, ans = 0;

        while (right < n) {
            // expand window
            freq[s[right]]++;

            // shrink window if more than k distinct
            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }

            // valid window has <= k distinct characters
            ans = ans + (right - left + 1);
            right++;
        }
        return ans;
    }
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        //total substrings - numberOfSubstringsWithAtMost2DistinctCharacters
        return n*(n+1)/2 -numberOfSubstringsWithAtMostKDistinctCharacters(s,2);
    }
};

//Optimal Approach
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> last(3, -1); // last seen positions of a,b,c
        int count = 0;

        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
            if (last[0] != -1 && last[1] != -1 && last[2] != -1) {
                count += 1 + min({last[0], last[1], last[2]});
            }
        }
        return count;
    }
};
