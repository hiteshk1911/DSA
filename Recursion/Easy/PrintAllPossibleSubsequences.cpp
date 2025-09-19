Problem Statement: Given a string, find all the possible subsequences of the string.

Examples:

Example 1:
Input: str = "abc"
Output: a ab abc ac b bc c
Explanation: Printing all the 7 subsequence for the string "abc".

Example 2:
Input: str = "aa"
Output: a a aa
Explanation: Printing all the 3 subsequences for the string "aa"

//Solution1 - using bit manipulation
Time Complexity: O(2^n * n)
Reason: O(2^n) for the outer for loop and O(n) for the inner for loop.
Space Complexity: O(1)

vector<string> AllPossibleStrings(string s) {
	int n = s.length();
	vector<string>ans;
	for (int num = 0; num < (1 << n); num++) {
		string sub = "";
		for (int i = 0; i < n; i++) {
			//check if the ith bit is set or not
			if (num & (1 << i)) {
				sub += s[i];
			}
		}
		if (sub.length() > 0) {
			ans.push_back(sub);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

//Solution2 - using recursion
Complexity
Total subsequences: 2^n.
Time: O(2^n * n) (printing each subsequence takes O(n) in worst case).
Space: O(n) recursion depth.

#include <bits/stdc++.h>
using namespace std;

void generateSubsequences(string s, int idx, string current) {
    // Base case: reached end of string
    if(idx == s.size()) {
        cout << current << endl;
        return;
    }

    // Choice 1: exclude current char
    generateSubsequences(s, idx + 1, current);

    // Choice 2: include current char
    generateSubsequences(s, idx + 1, current + s[idx]);
}

