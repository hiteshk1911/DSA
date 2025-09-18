Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.


Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false

//Solution

#include <string>

class Solution {
public:
    bool rotateString(std::string s, std::string goal) {
        // Check if lengths are the same
        if (s.length() != goal.length()) {
            return false;
        }
        // Concatenate s with itself
        std::string doubleS = s + s;
        // Check if goal is a substring of doubleS
        return doubleS.find(goal) != std::string::npos;
    }
};