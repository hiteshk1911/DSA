You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

1) Recursive Solution
//TC : O(2^N)
//SC : O(2^N)
class Solution {
public:
    int climbStairs(int n) {
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }

        return climbStairs(n-1) + climbStairs(n-2);
    }
};

2) Memoization (Top-Down)
//TC : O(N)
//SC : O(N) + O(N)  (Recursion Stack + DP Array)
    int climbStairs(int n,vector<int>& dp) {
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = climbStairs(n-1,dp) + climbStairs(n-2,dp);
    }
    int main(){
        vector<int> dp(n+1,-1);
        return climbStairs(n,dp);
    }

3) Tabultaion (Bottom-Up)
//TC : O(N)
//SC : O(N)
#include <bits/stdc++.h>
using namespace std;

int main() {

  int n=3;
  vector<int> dp(n+1,-1);

  dp[0]= 1;
  dp[1]= 1;

  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
}

4) Space Optimization
//TC : O(N)
//SC : O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
  //prev2 prev1 cur
  int prev1 = 1;
  int prev2 = 0;

  for(int i=2; i<=n; i++){
      int cur = prev1 + prev2;
      prev2 = prev1;
      prev1 = cur;
  }
  return prev1;
}