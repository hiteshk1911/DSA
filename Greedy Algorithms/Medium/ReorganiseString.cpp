Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.



Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""


Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.



class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        priority_queue<pair<int,char>> pq;

        unordered_map<char,int> freq;

        int maxFreq = 0;
        for(char ch:s){
            freq[ch]++;
            maxFreq = max(maxFreq,freq[ch]);
        }

        if(maxFreq>(n+1)/2){
            return "";   //not possible to reorganize string
        }

        for(auto it:freq){
            //{freq,character}
            pq.push({it.second,it.first});
        }

        string ans;
        while(pq.size()>1){
            pair<int,char> a = pq.top();
            pq.pop();

            pair<int,char> b = pq.top();
            pq.pop();

            ans.push_back(a.second);
            ans.push_back(b.second);

            a.first-=1;
            b.first-=1;

            if(a.first>0){
                pq.push(a);
            }
            if(b.first>0){
                pq.push(b);
            }
        }

        if (!pq.empty()) {
            auto [count, ch] = pq.top();
            if (count > 1) return "";
            ans.push_back(ch);
        }
        return ans;
    }
};