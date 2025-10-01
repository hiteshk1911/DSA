Problem Statement : Given a string array nums of length n. A string is called a complete string if every prefix of this string is also present in the array nums.

Find the longest complete string in the array nums.
If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return "None" (without quotes).


Examples:
Input : nums = [ "n", "ni", "nin", "ninj" , "ninja" , "nil" ]
Output : ninja

Explanation :
The word "ninja" is the longest word which has all its prefixes present in the array.

#include <iostream>
using namespace std;

// TrieNode structure for Trie
struct TrieNode {
    // Array to store links to child nodes,
    // each index represents a letter
    TrieNode* links[26];
    // Flag indicating if the node
    // marks the end of a word
    bool flag = false;

    // Check if the node contains
    // a specific key (letter)
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    // Insert a new node with a specific
    // key (letter) into the Trie
    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }

    // Get the node with a specific
    // key (letter) from the Trie
    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }

    // Set the current node
    // as the end of a word
    void setEnd() {
        flag = true;
    }

    // Check if the current node
    // marks the end of a word
    bool isEnd() {
        return flag;
    }
};

// Trie class
class Trie {
private:
    TrieNode* root;

public:
    // Constructor to initialize the
    // Trie with an empty root node
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the Trie
    // Time Complexity O(len), where len
    // is the length of the word
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                // Create a new node for
                // the letter if not present
                node->put(word[i], new TrieNode());
            }
            // Move to the next node
            node = node->get(word[i]);
        }
        // Mark the end of the word
        node->setEnd();
    }

   // Checks if all prefixes of 'word' exist in the Trie
   bool checkIfPrefixExists(const string &word) {
       TrieNode* node = root;
       for (int i = 0; i < word.size(); ++i) {
           if (!node->containsKey(word[i])) {
                return false;
           }
           node = node->get(word[i]);
           if (!node->isEnd()) {
                return false;
           }
       }
       return true;
   }

   // Returns the longest string with all prefixes present
   string longestStringWithAllPrefixes(int n, vector<string> &a) {
       for (const string &word : a) {
            insert(word);
       }

       string ans = "";
       for (const string &word : a) {
           if (checkIfPrefixExists(word)) {
               if (word.length() > ans.length() || (word.length() == ans.length() && word < ans)) {
                   ans = word;
               }
           }
       }
       return ans.empty() ? "None" : ans;
   }
};

