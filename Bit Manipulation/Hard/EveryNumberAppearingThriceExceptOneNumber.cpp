Example : [5 5 5 6 4 4 4]



1. Bit Counting (Mathematical Approach)

For each bit position (0–31), count how many numbers have that bit set.

Since every number except one appears thrice, the count will be divisible by 3 except for the unique number.

Take modulo 3 and reconstruct the unique number.

Code:

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
        int sum = 0;
        for (int num : nums) {
            if (num >> i & 1){ // check if i-th bit is set
             sum++;
           }
        }
        if (sum % 3) result |= (1 << i);
    }
    return result;
}


Time: O(32n) ≈ O(n)
Space: O(1)
✅ Works even with negatives.

2. Bitwise State Machine (Optimal O(n), O(1))

This is the cool trick:

Use two variables (ones, twos) to represent state of bits seen once and twice.

When a number is seen third time, it gets removed.

Logic:

ones  = (ones ^ num) & ~twos
twos  = (twos ^ num) & ~ones


Code:

int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    for (int num : nums) {
        ones = (ones ^ num) & ~twos;
        twos = (twos ^ num) & ~ones;
    }
    return ones; // unique number
}


Time: O(n)
Space: O(1)
✅ Most efficient solution.