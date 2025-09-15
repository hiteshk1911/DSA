Given a string array nums of length n. A string is called a complete string if every prefix of this string is also present in the array nums.

Find the longest complete string in the array nums.
If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return "None" (without quotes).


Examples:
Input : nums = [ "n", "ni", "nin", "ninj" , "ninja" , "nil" ]
Output : ninja

Explanation :
The word "ninja" is the longest word which has all its prefixes present in the array.

Input : nums = [ "ninja" , "night" , "nil" ]
Output : None

Explanation :

There is no string that has all its prefix present in array. So we return None.

//Solution
Build Trie: O(N * L) where N = number of words, L = max word length.
DFS traversal: visits each node once → O(26 * N * L) worst case.
Efficient for interview constraints.

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    string word;
    TrieNode() {
        isEnd = false;
        word = "";
        for(int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Solution {
    TrieNode* root;
public:
    Solution() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for(char c : word) {
            int idx = c - 'a';
            if(!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
        node->word = word;
    }

    string longestWord(vector<string>& words) {
        // Build Trie
        for(string &w : words) insert(w);

        string ans = "";
        dfs(root, ans);
        return ans;
    }

    void dfs(TrieNode* node, string &ans) {
        if(!node) return;
        // if not root and not an end, invalid path
        if(node != root && !node->isEnd) return;

        if(node->word.size() > ans.size() ||
           (node->word.size() == ans.size() && node->word < ans)) {
            ans = node->word;
        }

        for(int i = 0; i < 26; i++) {
            if(node->children[i]) dfs(node->children[i], ans);
        }
    }
};

int main() {
    vector<string> words = {"w","wo","wor","worl","world","banana","ban","b","ba"};
    Solution sol;
    cout << sol.longestWord(words) << endl; // Output: world
}
