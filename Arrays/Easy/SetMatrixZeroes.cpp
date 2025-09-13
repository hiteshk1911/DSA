Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

//Brute Force Approach
- For each element in the matrix, if it is 0, set its entire row and column to 0
- TC : O((N*M)*(N+M)) ; SC : O(1)

//Better Approach(1)
- Use two sets to keep track of the rows and columns that need to be set to 0
- First pass: Traverse the matrix and add the row and column indices of 0 elements to the sets
- Second pass: Traverse the matrix again and set the elements to 0 if their row or column index is in the respective set
- TC : O(N*M) ; SC : O(N+M)
- CPP Code :

#include <bits/stdc++.h>
using namespace std;

void setMatrixZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    unordered_set<int> rows;
    unordered_set<int> cols;

    // First pass: Identify the rows and columns that need to be set to 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }

    // Second pass: Set the identified rows and columns to 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (rows.find(i) != rows.end() || cols.find(j) != cols.end())
            {
                matrix[i][j] = 0;
            }
        }
    }
}

//Better Approach(2)
- Save i and j of 0s found in vector<pair<int, int>>
- First pass: Traverse the matrix and store the indices of 0 elements in the vector
- Second pass: Traverse the matrix again and set the elements to 0 if their row or column index matches any of the stored indices
- TC : O(N*M) ; SC : O(L) where L is the number of 0s in the matrix // Better than O(N+M) when there are less 0s

//Optimal Approach
- Use the first row and first column of the matrix to keep track of the rows and columns that need to be set to 0
- Use two boolean variables to keep track of whether the first row and first column need to be set to 0
- First pass: Traverse the matrix and for each 0 element, set the corresponding first row and first column elements to 0
- Second pass: Traverse the matrix again (excluding the first row and first column) and set the elements to 0 if their corresponding first row or first column element is 0
- Finally, set the first row and first column to 0 if needed
- TC : O(N*M) ; SC : O(1)
- CPP Code :

#include <bits/stdc++.h>
using namespace std;

void setMatrixZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    bool firstRowZero = false;
    bool firstColZero = false;

    // Check if the first row has any zeroes
    for (int j = 0; j < m; j++)
    {
        if (matrix[0][j] == 0)
        {
            firstRowZero = true;
            break;
        }
    }

    // Check if the first column has any zeroes
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0)
        {
            firstColZero = true;
            break;
        }
    }

    // Use the first row and first column to mark zeroes
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0; // Mark the row
                matrix[0][j] = 0; // Mark the column
            }
        }
    }

    // Set the elements to zero based on the marks in the first row and first column
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // Set the first row to zero if needed
    if (firstRowZero)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }

    // Set the first column to zero if needed
    if (firstColZero)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
}