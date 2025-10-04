Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.



Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.


Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104

class Solution {
public:
    static bool comp(vector<int>& val1,vector<int>& val2){
        return val1[1]<val2[1];
    }
    //just a small variation of N Meetings in 1 Room
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 1;
        int n =intervals.size();

        sort(intervals.begin(),intervals.end(),comp);

        int i = 1;
        int lastEndingTime = intervals[0][1];

        while(i<n){
            if(intervals[i][0]>=lastEndingTime){
                count=count+1;
                lastEndingTime = intervals[i][1];
            }
            i++;
        }

        return n - count;
    }
};