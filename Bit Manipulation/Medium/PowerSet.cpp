1️⃣ Recursive / Backtracking Approach
#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& res) {
    if (index == nums.size()) {
        res.push_back(subset);
        return;
    }
    // include nums[index]
    subset.push_back(nums[index]);
    backtrack(nums, index + 1, subset, res);
    subset.pop_back(); // exclude nums[index]
    backtrack(nums, index + 1, subset, res); // without current element
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> subset;
    backtrack(nums, 0, subset, res);
    return res;
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = subsets(nums);
    for (auto &v : ans) {
        cout << "{ ";
        for (int x : v) cout << x << " ";
        cout << "}\n";
    }
}


✅ Uses recursion/backtracking, time complexity O(2^n * n) , space complexity : O(n).



2️⃣ Bit Manipulation Approach

Each subset corresponds to a binary mask of length n

1 → include element, 0 → exclude element

vector<vector<int>> subsetsBitmask(vector<int>& nums) {
    int n = nums.size();
    int total = 1 << n; // 2^n subsets
    vector<vector<int>> res;

    for (int mask = 0; mask < total; mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) subset.push_back(nums[i]);
        }
        res.push_back(subset);
    }
    return res;
}


✅ Very efficient and elegant; O(2^n * n) , space complexity : O(1).