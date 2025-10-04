There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.



Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.


Constraints:

n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104

🧠 Approach 1: Brute Force (Iterative Adjustments)
⏱ O(n²) time | O(n) space

Idea:
Keep assigning 1 candy to all, then repeatedly adjust until all constraints are satisfied.

Code:
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        bool changed = true;

        while (changed) {
            changed = false;
            for (int i = 0; i < n; i++) {
                if (i > 0 && ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
                    candies[i] = candies[i - 1] + 1;
                    changed = true;
                }
                if (i < n - 1 && ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                    candies[i] = candies[i + 1] + 1;
                    changed = true;
                }
            }
        }

        int sum = 0;
        for (int c : candies) sum += c;
        return sum;
    }
};


✅ Works, but too slow for large inputs.

⚙️ Approach 2: Two-Pass Greedy (Optimal)
⏱ O(n) time | O(n) space

This is the standard optimal approach accepted by Leetcode.

Idea:

Do one left-to-right pass → ensure each child has more candy than left neighbor if rating is higher.

Do one right-to-left pass → ensure same for right neighbor.

Take the max of both passes.

Code:
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // Left to right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        }

        // Right to left
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i], candies[i + 1] + 1);
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};


✅ Best balance between simplicity and performance.

//Striver Observation Solution - Most optimal
class Solution {
public:
    // TC - O(N) SC - O(1)
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int sum =1,i=1 ;
        while(i<n){
            //plateau
            if(ratings[i]==ratings[i-1]){
                sum = sum + 1;
                i++;
                continue;
            }

            //increasing slope
            int peak = 1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak = peak + 1;
                sum = sum + peak;
                i++;
            }

            //decreasing slope
            int down = 1;
            while(i<n && ratings[i]<ratings[i-1]){
                sum = sum + down;
                down = down + 1;
                i++;
            }

            //check condition for extra
            if(down > peak){
                sum = sum + (down - peak);
            }
        }

        return sum ;
    }
};

⚡ Approach 3: Constant Space Greedy (O(1) space)
⏱ O(n) time | O(1) space

Observation: The distribution pattern forms ascending and descending slopes.

When ratings increase → you’re climbing up → give increasing candies.

When ratings decrease → you’re going down → handle it carefully.

Code:
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n <= 1) return n;

        int total = 1; // first child
        int up = 0, down = 0, peak = 0;

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                up++;
                peak = up;
                down = 0;
                total += 1 + up;
            } else if (ratings[i] == ratings[i - 1]) {
                up = down = peak = 0;
                total += 1;
            } else { // ratings[i] < ratings[i-1]
                up = 0;
                down++;
                total += 1 + down - (peak >= down ? 1 : 0);
            }
        }

        return total;
    }
};


✅ Uses constant space and still linear time.
⚠️ But trickier to understand — not recommended unless optimizing heavily.

