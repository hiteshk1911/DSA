Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

Example 1:
Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.

Example 2:
Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.

Example 3:
Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

//Solution
class Solution {
public:
void f(int ind, int sum, vector<int> &temp, vector<vector<int>> &ans,vector<int> &arr,int n,int k)
{
    if(sum==0){
        if(temp.size()==k){
            ans.push_back(temp);
        }
        return ;
    }

    if(sum<0){
        return ;
    }


    for(int i=ind;i<n;i++){

		if(i>ind && arr[i]==arr[i-1]){
			continue;
		}
       temp.push_back(arr[i]);
       f(i+1,sum-arr[i],temp,ans,arr,n,k);
       temp.pop_back();

    }

}
vector<vector<int>> combSum(vector<int> &arr, int sum,int k)
{
    vector<vector<int>> ans;
    vector<int> temp;

    int n=arr.size(),x=0;

    // sort(arr.begin(),arr.end());
    f(0,sum,temp,ans,arr,n,k);
    return ans;
}
vector<vector<int>> combinationSum2(vector<int> &arr, int target,int k){
	return combSum(arr,target,k);
}
vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr={1,2,3,4,5,6,7,8,9};
        vector<vector<int>> vec= combinationSum2(arr,n,k);


        return vec;
    }
};