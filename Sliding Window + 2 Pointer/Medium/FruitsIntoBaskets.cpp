You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].


Constraints:

1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length

//Brute Force
- Find all the subarrays with at most 2 distinct elements

//Better Approach
class Solution {
public:
    //Best optimised
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> type; //type->count

        int left = 0, right = 0, ans = 0;
        while(right<n){

            type[fruits[right]]++;

            while(type.size()>2){
                type[fruits[left]]--;
                if(type[fruits[left]]==0){
                    type.erase(fruits[left]);
                }
                left++;
            }


            ans = max(ans,right-left+1);


            right++;

        }
        return ans;
    }
};

//Optimal Approach
class Solution {
public:
    //Best optimised
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> type; //type->count

        int left = 0, right = 0, ans = 0;
        while(right<n){

            type[fruits[right]]++;

            //Turned while into if condition & added an important check
            if(type.size()>2){
                type[fruits[left]]--;
                if(type[fruits[left]]==0){
                    type.erase(fruits[left]);
                }
                left++;
            }

            //Important check
            if(type.size()<=2){
                ans = max(ans,right-left+1);
            }

            right++;

        }
        return ans;
    }
};