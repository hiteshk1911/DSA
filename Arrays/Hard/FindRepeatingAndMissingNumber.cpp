You are given a read-only array of N integers with values also in the range [1, N] both inclusive.
Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

//Brute Force Approach
- Use a frequency array to count the occurrences of each number
- Traverse the frequency array to find the number with frequency 2 (repeating) and the number with frequency 0 (missing)
- TC : O(N) SC : O(N)

//Better Approach
- Use the input array itself to mark the presence of numbers by negating the value at the index corresponding to each number
- Traverse the array to find the index with a positive value (missing number) and the index with a negative value that has already been negated (repeating number)
- TC : O(N) SC : O(1)
- Code CPP:

#include <bits/stdc++.h>
using namespace std;

pair<int, int> findRepeatingAndMissing(vector<int> &arr) {
    int n = arr.size();
    int repeating = -1, missing = -1;

    for (int i = 0; i < n; i++) {
        int index = abs(arr[i]) - 1; // Get the index corresponding to the value
        if (arr[index] < 0) {
            repeating = abs(arr[i]); // If already negative, it's the repeating number
        } else {
            arr[index] = -arr[index]; // Negate the value at that index to mark presence
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            missing = i + 1; // The index + 1 is the missing number
            break;
        }
    }

    return {repeating, missing};
}

//Dry run
Example Input: arr = [3, 1, 3, 4, 2]
//Dry run Steps:
// Initial array: [3, 1, 3, 4, 2]
// i = 0: index = 2, arr[2] = 3 -> arr[2] = -3 -> arr = [3, 1, -3, 4, 2]
// i = 1: index = 0, arr[0] = 3 -> arr[0] = -3 -> arr = [-3, 1, -3, 4, 2]
// i = 2: index = 2, arr[2] = -3 (already negative) -> repeating = 3
// i = 3: index = 3, arr[3] = 4 -> arr[3] = -4 -> arr = [-3, 1, -3, -4, 2]
// i = 4: index = 1, arr[1] = 1 -> arr[1] = -1 -> arr = [-3, -1, -3, -4, 2]
// Second pass to find missing number
// i = 0: arr[0] = -3 (negative)
// i = 1: arr[1] = -1 (negative)
// i = 2: arr[2] = -3 (negative)
// i = 3: arr[3] = -4 (negative)
// i = 4: arr[4] = 2 (positive) -> missing = 5
// Final result: (3, 5)
Example Output: (3, 5)


//Optimal Approach
- Use mathematical formulas to find the sum and sum of squares of the first N natural numbers
- Use the differences between the expected sums and the actual sums to derive equations for the repeating and missing numbers
- Solve the equations to find the values of A and B
- TC : O(N) SC : O(1)
- Code CPP:

#include <bits/stdc++.h>
using namespace std;

pair<int, int> findRepeatingAndMissing(vector<int> &arr) {
    int n = arr.size();
    long long sumN = (long long)n * (n + 1) / 2; // Sum of first N natural numbers
    long long sumNSq = (long long)n * (n + 1) * (2 * n + 1) / 6; // Sum of squares of first N natural numbers

    long long sumArr = 0, sumArrSq = 0;
    for (int num : arr) {
        sumArr += num;
        sumArrSq += (long long)num * num;
    }

    long long diff = sumN - sumArr; // B - A
    long long diffSq = sumNSq - sumArrSq; // B^2 - A^2

    // B^2 - A^2 = (B - A)(B + A)
    // => B + A = diffSq / diff
    long long sumBA = diffSq / diff;

    // Now we have two equations:
    // 1. B - A = diff
    // 2. B + A = sumBA
    // Solving these two equations:
    // Adding both equations: 2B = diff + sumBA => B = (diff + sumBA) / 2
    // Substituting B in the first equation: A = B - diff

    int B = (diff + sumBA) / 2;
    int A = B - diff;

    return {A, B};
}