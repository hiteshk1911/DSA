Problem Statement: Implement a Trie Data Structure which supports the following three operations:

Search (word): To check if the string `word` is present in the Trie or not.
Insert (word): To insert a string `word` in the Trie.
Start With(word): To check if there is a string that has the prefix `word`.

Trie is a data structure that is like a tree data structure in its organisation. It consists of nodes that store letters or alphabets of words, which can be added, retrieved, and deleted from it in a very efficient way.
In other words, Trie is an information retrieval data structure, which can beat naive data structures like Hashmap, Tree, etc in the time complexity of its operations.

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

    // Returns if the word
    // is in the trie
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                // If a letter is not found,
                // the word is not in the Trie
                return false;
            }
            // Move to the next node
            node = node->get(word[i]);
        }
        // Check if the last node
        // marks the end of a word
        return node->isEnd();
    }

    // Returns if there is any word in the
    // trie that starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containsKey(prefix[i])) {
                // If a letter is not found, there is
                // no word with the given prefix
                return false;
            }
            // Move to the next node
            node = node->get(prefix[i]);
        }
        // The prefix is found in the Trie
        return true;
    }
};

int main() {
    Trie trie;
    cout << "Inserting words: Striver, Striving, String, Strike" << endl;
    trie.insert("striver");
    trie.insert("striving");
    trie.insert("string");
    trie.insert("strike");

    cout << "Search if Strawberry exists in trie: " <<
    (trie.search("strawberry") ? "True" : "False")<< endl;

    cout << "Search if Strike exists in trie: " <<
   ( trie.search("strike") ? "True" : "False" )<< endl;

    cout << "If words is Trie start with Stri: " <<
    (trie.startsWith("stri") ? "True" : "False" )<< endl;

    return 0;
}
