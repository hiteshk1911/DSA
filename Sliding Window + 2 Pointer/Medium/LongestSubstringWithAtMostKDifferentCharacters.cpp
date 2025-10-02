🔑 Rule of Thumb

If the problem asks for the length of the longest substring/subarray (like LC 340, LC 159, LC 3, LC 76, LC 424, LC 1004, etc.)
👉 You can often replace while with if.

Because when you’re tracking only the maximum window length, it’s fine if the window is temporarily invalid — the window will adjust in the next iterations anyway.

So shrinking by just one step per iteration (if) is enough.

If the problem asks for the count of substrings/subarrays (like LC 992, LC 1248, LC 930, etc.)
👉 You must use while, because the window must always be valid when counting.

Otherwise you’ll overcount invalid subarrays.

Multiple shrinks might be required in the same iteration.

//Brute Force
- Find all the subarrays with at most k distinct elements

//Better Approach
- TC: O(2N)

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
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
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};

//Best Approach
- TC: O(N)

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        if (n == 0 || k == 0) return 0;

        unordered_map<char, int> freq;  // character -> count
        int left = 0, right = 0, ans = 0;

        while (right < n) {
            // expand window
            freq[s[right]]++;

            // shrink window if more than k distinct
            if (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }

            // valid window has <= k distinct characters
            if(freq.size() <= k){
                ans = max(ans, right - left + 1);
            }

            right++;
        }
        return ans;
    }
};
