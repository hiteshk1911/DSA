 Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.

//Brute Force Approach
- Use two nested loops to compare each interval with all other intervals
- If two intervals overlap, merge them and mark the second interval as merged
- TC : O(N^2) SC : O(1)
- Code CPP:

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    vector<bool> merged(n, false);
    vector<vector<int>> result;

    for (int i = 0; i < n; i++)
    {
        if (merged[i])
            continue;

        int start = intervals[i][0];
        int end = intervals[i][1];

        for (int j = i + 1; j < n; j++)
        {
            if (merged[j])
                continue;

            if (intervals[j][0] <= end && intervals[j][1] >= start) // Check for overlap
            {
                start = min(start, intervals[j][0]);
                end = max(end, intervals[j][1]);
                merged[j] = true; // Mark as merged
            }
        }

        result.push_back({start, end});
    }

    return result;
}

//Dry Run
example = [[1,3],[2,4],[5,7],[6,8]]
// i = 0, merged = [false, false, false, false], result = []
// start = 1, end = 3
// j = 1, intervals[1][0] <= end && intervals[1][1] >= start => 2 <= 3 && 4 >= 1 => true
// start = min(1, 2) = 1, end = max(3, 4) = 4, merged = [false, true, false, false]
// j = 2, intervals[2][0] <= end && intervals[2][1] >= start => 5 <= 4 && 7 >= 1 => false
// j = 3, intervals[3][0] <= end && intervals[3][1] >= start => 6 <= 4 && 8 >= 1 => false
// result = [[1, 4]]
// i = 1, merged = [false, true, false, false], continue
// i = 2, merged = [false, true, false, false], result = [[1, 4]]
// start = 5, end = 7
// j = 3, intervals[3][0] <= end && intervals[3][1] >= start => 6 <= 7 && 8 >= 5 => true
// start = min(5, 6) = 5, end = max(7, 8) = 8, merged = [false, true, false, true]
// result = [[1, 4], [5, 8]]
// i = 3, merged = [false, true, false, true], continue
// return [[1, 4], [5, 8]]

//Optimal Approach
- Sort the intervals based on the start time
- Traverse the sorted intervals and compare the current interval with the last interval in the result
- If they overlap, merge them by updating the end time of the last interval in the result
- If they don't overlap, add the current interval to the result
- TC : O(N log N) SC : O(N)
- Code CPP:

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    if (intervals.size() == 0)
        return {};

    sort(intervals.begin(), intervals.end()); // Sort based on the start time
    vector<vector<int>> result;
    result.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= result.back()[1]) // Check for overlap
        {
            result.back()[1] = max(result.back()[1], intervals[i][1]); // Merge intervals
        }
        else
        {
            result.push_back(intervals[i]); // No overlap, add to result
        }
    }

    return result;
}

//Dry Run
example = [[1,3],[2,4],[5,7],[6,8]]
// After sorting: [[1,3],[2,4],[5,7],[6,8]]
// result = [[1, 3]]
// i = 1, intervals[1][0] <= result.back()[1] => 2 <= 3 => true
// result.back()[1] = max(3, 4) = 4
// result = [[1, 4]]
// i = 2, intervals[2][0] <= result.back()[1] => 5 <= 4 => false
// result = [[1, 4], [5, 7]]
// i = 3, intervals[3][0] <= result.back()[1] => 6 <= 7 => true
// result.back()[1] = max(7, 8) = 8
// result = [[1, 4], [5, 8]]
// return [[1, 4], [5, 8]]
// Note: The input intervals may not be initially sorted. The optimal approach sorts them first to facilitate merging.

