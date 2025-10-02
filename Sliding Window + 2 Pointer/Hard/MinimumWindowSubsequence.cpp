🛠️ Changes Needed

For minimum window subsequence:

    We cannot just use a frequency map and sliding window.
    Instead, we need to scan s while trying to match t in order.

    Algorithm:

    Use two pointers (i on s, j on t).

    Move i forward until we find a subsequence of t.

    Once found, backtrack i to shrink and find the minimal window for that subsequence.

    Keep track of the smallest window length.

    Time complexity: O(n * m) worst-case (since each subsequence check may take O(m)).

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int minLen = INT_MAX, start = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == t[0]) { // potential start of subsequence
                int j = 0, k = i;
                // forward scan to match subsequence
                while (k < n && j < m) {
                    if (s[k] == t[j]) j++;
                    k++;
                }

                if (j == m) { // subsequence found
                    // backtrack to minimize window
                    int end = k - 1;
                    j = m - 1;
                    while (end >= i) {
                        if (s[end] == t[j]) {
                            j--;
                            if (j < 0) break;
                        }
                        end--;
                    }

                    if (k - end < minLen) {
                        minLen = k - end;
                        start = end;
                    }
                }
            }
        }

        return start == -1 ? "" : s.substr(start, minLen);
    }
};
