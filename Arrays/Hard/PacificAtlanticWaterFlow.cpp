Problem Statement :
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

class Solution {
public:
    int m, n;
    vector<vector<int>> heights;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(int i, int j, vector<vector<bool>>& ocean) {
        ocean[i][j] = true;

        for (auto& d : directions) {
            int x = i + d[0];
            int y = j + d[1];

            if (x >= 0 && x < m && y >= 0 && y < n &&
                !ocean[x][y] && heights[x][y] >= heights[i][j]) {
                dfs(x, y, ocean);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        heights = h;
        m = h.size();
        n = h[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific: top row + left column
        for (int i = 0; i < m; i++) dfs(i, 0, pacific);
        for (int j = 0; j < n; j++) dfs(0, j, pacific);

        // Atlantic: bottom row + right column
        for (int i = 0; i < m; i++) dfs(i, n - 1, atlantic);
        for (int j = 0; j < n; j++) dfs(m - 1, j, atlantic);

        // Find intersection
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});
            }
        }

        return res;
    }
};
