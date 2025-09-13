Program to generate Pascal's Triangle

Problem Statement: This problem has 3 variations. They are stated below:

Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.

Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.

In Pascal’s triangle, each number is the sum of the two numbers directly above it.

//Variation 1
- Use the formula nCr = n! / (r! * (n - r)!) to calculate the value at position (r, c)
- TC : O(r) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}
int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int getElement(int r, int c) {
    return nCr(r, c);
}

//Variation 2
- Use the formula nCr = n! / (r! * (n - r)!) to calculate the values in the n-th row
- TC : O(n^2) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}
int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}
vector<int> getRow(int n) {
    vector<int> row;
    for (int r = 0; r <= n; r++) {
        row.push_back(nCr(n, r));
    }
    return row;
}

//Variation 3
- Use a 2D vector to store the values in Pascal’s triangle
- Each element is the sum of the two elements directly above it
- TC : O(n^2) SC : O(n^2)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle(numRows);
    for (int i = 0; i < numRows; i++) {
        triangle[i].resize(i + 1);
        triangle[i][0] = triangle[i][i] = 1; // First and last element of each row is 1
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j]; // Sum of the two elements above
        }
    }
    return triangle;
}
