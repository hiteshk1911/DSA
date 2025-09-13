Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

//Clockwise Rotation - 90 degrees
//Brute Force Approach
- Create a new matrix to store the rotated version
- For each element in the original matrix, place it in the correct position in the new matrix
- TC : O(N*M) SC : O(N*M)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> rotated(m, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            rotated[j][n - 1 - i] = matrix[i][j];
        }
    }

    matrix = rotated; // Copy the rotated matrix back to the original matrix
}

//Optimal Approach
- Transpose the matrix (swap rows with columns)
- Reverse each row to get the rotated matrix
- TC : O(N*M) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // Transpose the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < m; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reverse each row
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

//Clockwise Rotation - 180 degrees
- Reverse each row
- Reverse the entire matrix (reverse the order of rows)
- TC : O(N*M) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

void rotateMatrix180(vector<vector<int>> &matrix) // No need to transpose -> just reverse rows and then reverse the order of rows
{
    int n = matrix.size();
    int m = matrix[0].size();

    // Reverse each row
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    // Reverse the entire matrix (reverse the order of rows)
    reverse(matrix.begin(), matrix.end());
}


// For anti-clockwise rotation, reverse each column instead of each row after transposing.
// CPP Code for reversing each column:

#include <bits/stdc++.h>
using namespace std;

void rotateMatrixCounterClockwise(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // Transpose the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < m; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reverse each column
    for (int j = 0; j < m; j++)
    {
        int top = 0, bottom = n - 1;
        while (top < bottom)
        {
            swap(matrix[top][j], matrix[bottom][j]);
            top++;
            bottom--;
        }
    }
}

//For anti-clockwise rotation by 180 degrees
- Reverse each column
- Reverse the entire matrix (reverse the order of rows)
- TC : O(N*M) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

void rotateMatrix180CounterClockwise(vector<vector<int>> &matrix) // No need to transpose -> just reverse columns and then reverse the order of rows
{
    int n = matrix.size();
    int m = matrix[0].size();

    // Reverse each column
    for (int j = 0; j < m; j++)
    {
        int top = 0, bottom = n - 1;
        while (top < bottom)
        {
            swap(matrix[top][j], matrix[bottom][j]);
            top++;
            bottom--;
        }
    }
    // Reverse the entire matrix (reverse the order of rows)
    reverse(matrix.begin(), matrix.end());
}
