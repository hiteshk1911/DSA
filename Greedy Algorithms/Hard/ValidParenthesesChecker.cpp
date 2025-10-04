Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true


Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.

//Recusive Approach
class Solution {
    bool helper(string &s, int i, int balance) {
        // if balance goes negative, too many ')'
        if (balance < 0) return false;
        // if we reached end, valid if balance == 0
        if (i == s.size()) return balance == 0;

        if (s[i] == '(')
            return helper(s, i + 1, balance + 1);
        else if (s[i] == ')')
            return helper(s, i + 1, balance - 1);
        else // s[i] == '*'
            return helper(s, i + 1, balance + 1) ||  // treat '*' as '('
                   helper(s, i + 1, balance - 1) ||  // treat '*' as ')'
                   helper(s, i + 1, balance);        // treat '*' as empty
    }

public:
    bool checkValidString(string s) {
        return helper(s, 0, 0);
    }
};

//Top-Down DP with Memoization
class Solution {
    bool helper(string &s, int i, int balance,vector<vector<int>> &dp) {
        // if balance goes negative, too many ')'
        if (balance < 0) return false;
        // if we reached end, valid if balance == 0
        if (i == s.size()) return balance == 0;

        if(dp[i][balance]!=-1){
            return dp[i][balance];
        }
        if (s[i] == '(')
            return dp[i][balance]= helper(s, i + 1, balance + 1,dp);
        else if (s[i] == ')')
            return dp[i][balance] = helper(s, i + 1, balance - 1,dp);
        else // s[i] == '*'
            return dp[i][balance] = helper(s, i + 1, balance + 1,dp) ||  // treat '*' as '('
                   helper(s, i + 1, balance - 1,dp) ||  // treat '*' as ')'
                   helper(s, i + 1, balance,dp);        // treat '*' as empty
    }

public:
    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return helper(s, 0, 0,dp);
    }
};


//Greedy Approach
class Solution {


public:
    bool checkValidString(string s) {
        int n = s.length();
        //greedy approach
        int mini = 0,maxi =0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                mini++;
                maxi++;
            }else if(s[i]==')'){
                mini--;
                maxi--;
            }else{
                mini--;
                maxi++;
            }

            if(mini<0){
                mini = 0;
            }
            //important check
            if(maxi<0){
                return false;
            }
        }

        return mini==0;
    }
};
