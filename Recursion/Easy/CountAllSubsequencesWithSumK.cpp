Given an array nums and an integer k.Return the number of non-empty subsequences of nums such that the sum of all elements in the subsequence is equal to k.


Examples:
Input : nums = [4, 9, 2, 5, 1] , k = 10

Output : 2

Explanation : The possible subsets with sum k are [9, 1] , [4, 5, 1].

Input : nums = [4, 2, 10, 5, 1, 3] , k = 5

Output : 3

Explanation : The possible subsets with sum k are [4, 1] , [2, 3] , [5].

//Solution

class Solution{
    private:
    void checkHelper(int n, vector<int>& arr, int k,int index,int &ans){
        if(index>=n){
            if(k==0){
                ans++;

            }
            return ;
        }

        //exclude
        checkHelper(n,arr,k,index+1,ans);

        //include
        if(arr[index]<=k){

           checkHelper(n,arr,k-arr[index],index+1,ans);
        }

    }

    public:
    int countSubsequenceWithTargetSum(vector<int>& arr, int k){
    	int index = 0;
        int n = arr.size();
        int ans = 0;
         checkHelper(n,arr,k,index,ans);
         return ans;
    }
};