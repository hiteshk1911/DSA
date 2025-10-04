You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:

The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.
Examples :

Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
Output: [2, 60]
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).
Input: deadline[] = [2, 1, 2, 1, 1], profit[] = [100, 19, 27, 25, 15]
Output: [2, 127]
Explanation: Job1 and Job3 can be done with maximum profit of 127 (100+27).
Input: deadline[] = [3, 1, 2, 2], profit[] = [50, 10, 20, 30]
Output: [3, 100]
Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100 (50 + 20 + 30).
Constraints:
1 ≤ deadline.size() = profit.size() ≤ 105
1 ≤ deadline[i] ≤ deadline.size()
1 ≤ profit[i] ≤ 500

#include<bits/stdc++.h>

using namespace std;
// A structure to represent a job
struct Job {
   int id; // Job Id
   int dead; // Deadline of job
   int profit; // Profit if job is over before or on deadline
};
class Solution {
   public:
      bool static comparison(Job a, Job b) {
         return (a.profit > b.profit); // Sort in decreasing order of profit
      }
   //Function to find the maximum profit and the number of jobs done
   pair < int, int > JobScheduling(Job arr[], int n) {

      sort(arr, arr + n, comparison);
      int maxi = arr[0].dead;
      for (int i = 1; i < n; i++) {
         maxi = max(maxi, arr[i].dead);
      }

      int slot[maxi + 1];

      for (int i = 0; i <= maxi; i++)
         slot[i] = -1;

      int countJobs = 0, jobProfit = 0;

      for (int i = 0; i < n; i++) {
         for (int j = arr[i].dead; j > 0; j--) { //why day>0? because 0th day doesn't exist
            if (slot[j] == -1) {
               slot[j] = i;
               countJobs++;
               jobProfit += arr[i].profit;
               break;
            }
         }
      }

      return make_pair(countJobs, jobProfit);
   }
};
int main() {
   int n = 4;
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   //function call
   pair < int, int > ans = ob.JobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;

   return 0;
}
Output: 3 90

Time Complexity: O(N log N) + O(N*M).

O(N log N ) for sorting the jobs in decreasing order of profit. O(N*M) since we are iterating through all N jobs and for every job we are checking from the last deadline, say M deadlines in the worst case.

Space Complexity: O(M) for an array that keeps track on which day which job is performed if M is the maximum deadline available.

//💡 Greedy Strategy

Sort jobs by profit (descending order) — pick most profitable jobs first.

For each job (in that order):

Try to schedule it on the latest possible free day ≤ its deadline.

If that day is already occupied, move backward to find a free one.

Keep count of:

countJobs = number of scheduled jobs.

totalProfit = total profit of scheduled jobs.

⚙️ Efficient Implementation (Using Array Scheduling)
class Solution {
public:
    vector<int> JobScheduling(vector<int>& deadline, vector<int>& profit) {
        int n = deadline.size();

        // Step 1: Combine jobs into a single vector of pairs
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }

        // Step 2: Sort by profit in descending order
        sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());

        // Step 3: Find maximum deadline
        int maxDeadline = 0;
        for (auto &job : jobs)
            maxDeadline = max(maxDeadline, job.second);

        // Step 4: Create time slots (-1 means free)
        vector<int> slot(maxDeadline + 1, -1);

        int countJobs = 0, totalProfit = 0;

        // Step 5: Schedule each job
        for (auto &job : jobs) {
            int profit = job.first;
            int dead = job.second;

            // Try to place it on the latest available day ≤ deadline
            for (int day = dead; day > 0; day--) { //why day>0? because 0th day doesn't exist
                if (slot[day] == -1) { // free slot
                    slot[day] = profit;
                    countJobs++;
                    totalProfit += profit;
                    break;
                }
            }
        }

        return {countJobs, totalProfit};
    }
};

//We can optimise the inner loop using Disjoint Set Union (DSU) to achieve nearly O(1) time complexity for finding the latest free slot.