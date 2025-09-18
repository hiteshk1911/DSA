A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

//Optimal Approach

std::string removeOuterParentheses(std::string s) {
        std::string result;
        int balance = 0; // to track the number of opening parentheses

        for (char c : s) {
            if (c == '(') {
                // If balance > 0, it means we are in a primitive part, so we can add it
                if (balance > 0) {
                    result += c;
                }
                balance++; // increment balance for '('
            } else { // c == ')'
                // We add ')' only if we are in a primitive part
                if (balance > 1) {
                    result += c;
                }
                balance--; // decrement balance for ')'
            }
        }
        return result;
}