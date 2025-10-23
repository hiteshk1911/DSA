Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.



Example 1:

Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: 9
Example 2:

Input: grid = [[1,1,0,0]]
Output: 1


Constraints:

1 <= grid.length <= 100
1 <= grid[0].length <= 100
grid[i][j] is 0 or 1




class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // DP tables for consecutive 1s up and left
        vector<vector<int>> up(n, vector<int>(m, 0));
        vector<vector<int>> left(n, vector<int>(m, 0));

        int maxSide = 0;

        // Precompute up and left
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    up[i][j] = (i > 0 ? up[i - 1][j] : 0) + 1;
                    left[i][j] = (j > 0 ? left[i][j - 1] : 0) + 1;

                    // The largest possible square ending here
                    int small = min(up[i][j], left[i][j]);

                    // Check if we can form a valid square of side = small, small-1, etc.
                    while (small > maxSide) {
                        // Check top and left borders of the square
                        if (up[i][j - small + 1] >= small && left[i - small + 1][j] >= small) {
                            maxSide = small;  // Found a larger square
                            break;
                        }
                        small--;
                    }
                }
            }
        }

        return maxSide * maxSide;
    }
};
