Problem Statement :
You are climbing a staircase with n + 1 steps, numbered from 0 to n.
You are also given a 1-indexed integer array costs of length n, where costs[i] is the cost of step i.
From step i, you can jump only to step i + 1, i + 2, or i + 3. The cost of jumping from step i to step j is defined as: costs[j] + (j - i)2
You start from step 0 with cost = 0.
Return the minimum total cost to reach step n.


class Solution {
private:
   int minCost(int n,vector<int>& costs,int currentIndex,vector<int> &dp){
       if(currentIndex==n){
           return 0;
       }
       if(currentIndex>n){
           return INT_MAX;
       }

        if(dp[currentIndex]!=-1){
            return dp[currentIndex];
        }

    int op1 = INT_MAX;
       if(currentIndex+1<=n){
           op1 =  costs[currentIndex+1-1] + 1 + minCost(n,costs,currentIndex+1,dp);
       }

        int op2 = INT_MAX;
       if(currentIndex+2<=n){
           op2 =  costs[currentIndex+2-1] + 4 + minCost(n,costs,currentIndex+2,dp);
       }

        int op3 = INT_MAX;
       if(currentIndex+3<=n){
           op3 =  costs[currentIndex+3-1] + 9 + minCost(n,costs,currentIndex+3,dp);
       }



       return dp[currentIndex] = min(op1,min(op2,op3));
   }
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,-1);
        return minCost(n,costs,0,dp);
    }
};