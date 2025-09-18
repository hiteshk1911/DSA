Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


//Brute Force Approach

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //brute force
        string ans="";

        for(int i=0;i<strs[0].length();i++){
            bool match=true;
            char ch=strs[0][i];

            for(int j=1;j<strs.size();j++){
                if(strs[j].length()<i || ch!=strs[j][i]){
                    match=false;
                    break;
                }
            }
            if(match==false){
                break;
            }else{
                ans.push_back(ch);
            }
        }

        return ans;
    }
};

//Optimal Approach

class TrieNode{
    public :
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int countChild;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
        countChild=0;

    }
};
class Trie{
    public :
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }

    void insertHelper(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return ;
        }

        int index=word[0]-'a';
        TrieNode* child;

        if(root->children[index]){
            child=root->children[index];
        }else{
            child= new TrieNode(word[0]);
            root->children[index]=child;
            root->countChild++;
        }

        insertHelper(child,word.substr(1));
    }
    void insert(string word){
        insertHelper(root,word);
    }
    void lcpHelper(TrieNode* root,string& ans,string word){
        if(word.length()==0){


            return ;
        }

        int index = word[0]-'a';

        if(!root->children[index] || root->countChild>1){
            return ;
        }else{
            ans.push_back(word[0]);
            lcpHelper(root->children[index],ans,word.substr(1));
        }
    }
    string lcp(string word){
        string ans="";
        lcpHelper(root,ans,word);
        return ans;
    }

};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //Method 1
//         Trie* t=new Trie();
//         sort(strs.begin(),strs.end());
//         for(int i=0;i<strs.size();i++){

//             t->insert(strs[i]);
//         }

//         return t->lcp(strs[0]);

        //Method2
        if(strs.size()==1){
            return strs[0];
        }
        string first = strs[0];
        int n =first.size();
        string ans = "";
        for(int i=0;i<n;i++){
            for(int j=1;j<strs.size();j++){
                if(i<strs[j].size() && strs[j][i]==first[i]){

                }else{
                    return ans;
                }
            }
            ans = ans + first[i];
        }

        return ans;
    }
};