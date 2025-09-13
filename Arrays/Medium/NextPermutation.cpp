Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.
If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).

//Brute Force Approach
- Generate all permutations of the array
- Store the permutations in a list and sort the list
- Find the current permutation in the list and return the next permutation
- TC : O(N * N!) SC : O(N * N!)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> permutations;
    sort(nums.begin(), nums.end());

    do {
        permutations.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));

    for (int i = 0; i < permutations.size(); i++) {
        if (permutations[i] == nums) {
            if (i == permutations.size() - 1) {
                nums = permutations[0];
            } else {
                nums = permutations[i + 1];
            }
            break;
        }
    }
}

//Optimal Approach
- Find the first decreasing element from the right
- If no such element is found, reverse the entire array
- If such an element is found, find the first element greater than the decreasing element from the right
- Swap the two elements
- Reverse the elements to the right of the decreasing element
- NOTE: This approach works because we are trying to find the next lexicographical permutation.
        By finding the first decreasing element from the right, we are identifying the point where we can make a change to create a larger permutation.
        Swapping it with the next larger element ensures that we are making the smallest possible increase to the permutation.
        Finally, reversing the elements to the right of the swapped element ensures that we are creating the smallest possible arrangement of those elements, which gives us the next permutation.
- Edge Case: If the array is sorted in descending order, we simply reverse it to get the smallest permutation.
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    int i = n - 2;

    // Step 1: Find the first decreasing element from the right
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) { //What if is -1? -> The array is sorted in descending order -> Reverse the entire array
        // Step 2: Find the first element greater than the decreasing element from the right
        int j = n - 1;
        while (j >= 0 && nums[j] <= nums[i]) {
            j--;
        }
        // Step 3: Swap the two elements
        swap(nums[i], nums[j]);
    }

    // Step 4: Reverse the elements to the right of the decreasing element
    reverse(nums.begin() + i + 1, nums.end()); //Handles i=-1 case as well -> Reverse the entire array
}