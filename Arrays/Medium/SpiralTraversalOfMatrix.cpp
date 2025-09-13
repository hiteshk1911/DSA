 Given a Matrix, print the given matrix in spiral order.

//Optimal Approach
- Use four pointers to keep track of the boundaries of the matrix (top, bottom, left, right)
- Traverse the matrix in a spiral order using the four pointers
- NOTE: Dont we need to check count < totalElements? ->
        No, because the while loop condition top <= bottom && left <= right ensures that we do not go out of bounds.
- TC : O(N*M) ; SC : O(1)
- CPP Code :

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> result;
    if (matrix.empty())
        return result;

    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right)
    {
        // Traverse from left to right
        for (int j = left; j <= right; j++)
        {
            result.push_back(matrix[top][j]);
        }
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom; i++)
        {
            result.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            // Traverse from right to left
            for (int j = right; j >= left; j--)
            {
                result.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        if (left <= right)
        {
            // Traverse from bottom to top
            for (int i = bottom; i >= top; i--)
            {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return result;
}
