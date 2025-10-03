Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.



Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]


//Optimal Approach: Bit Manipulation (XOR)
=> Bit Manipulation (Optimal)

This is the standard trick:

XOR all numbers → result = x ^ y (where x and y are the two unique numbers).

Because all pairs cancel out.

Find any set bit in result (say rightmost set bit).

This bit is different between x and y.

Partition numbers into 2 groups based on this bit:

Group A → bit set.

Group B → bit unset.

Each group will have one unique number.

XOR within each group → gives x and y.

//Complexity Analysis
Time: O(n)
Space: O(1)
✅ Works for negative numbers too.

vector<int> singleNumber(vector<int>& nums) {
    long long xorsum = 0;
    for (int num : nums) xorsum ^= num; // xorsum = x ^ y

    // get rightmost set bit
    long long diff = xorsum & (-xorsum); //or we can write diff = (xorsum & (xorsum - 1)) ^ xorsum;

    int a = 0, b = 0;
    for (int num : nums) {
        if (num & diff) a ^= num;  // group with set bit
        else b ^= num;             // group with unset bit
    }
    return {a, b};
}
