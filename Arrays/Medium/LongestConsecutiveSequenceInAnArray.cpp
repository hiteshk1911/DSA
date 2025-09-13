You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

//Brute Force Approach
- For each element, check for the next consecutive elements in the array
- Linear search for each consecutive element
- TC : O(N^2) ; SC : O(1)
- CPP Code :

#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveSequence(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;

    int longestStreak = 1;

    for (int i = 0; i < n; i++)
    {
        int currentNum = arr[i];
        int currentStreak = 1;

        while (find(arr.begin(), arr.end(), currentNum + 1) != arr.end()) //Handles duplicates as well
        {
            currentNum += 1;
            currentStreak += 1;
        }

        longestStreak = max(longestStreak, currentStreak);
    }

    return longestStreak;
}

//Better Force Approach
- Sort the array & traverse through it to find the longest consecutive sequence
- TC : O(N log N) ; SC : O(1)
- CPP Code :

#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveSequence(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;

    sort(arr.begin(), arr.end());
    int longestStreak = 1;
    int currentStreak = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1]) // To handle duplicates
        {
            if (arr[i] == arr[i - 1] + 1)
            {
                currentStreak++;
            }
            else
            {
                longestStreak = max(longestStreak, currentStreak);
                currentStreak = 1;
            }
        }
    }

    return max(longestStreak, currentStreak);
}

//Optimal Approach
- Use a hash set to store the elements of the array
- For each element, check if it is the start of a sequence (i.e., the previous element is not in the set)
- If it is the start of a sequence, keep checking for the next consecutive elements in the set
- TC : O(N) ; SC : O(N)
- CPP Code :

#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveSequence(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;

    unordered_set<int> numSet(arr.begin(), arr.end());
    int longestStreak = 1;

    for (int num : numSet)
    {
        // Check if it's the start of a sequence
        if (numSet.find(num - 1) == numSet.end())
        {
            int currentNum = num;
            int currentStreak = 1;

            // Check for the next consecutive elements
            while (numSet.find(currentNum + 1) != numSet.end()) //Handles duplicates as well ? -> No, set inherently handles duplicates
            {
                currentNum += 1;
                currentStreak += 1;
            }

            longestStreak = max(longestStreak, currentStreak);
        }
    }

    return longestStreak;
}