Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.
NOTE: Elements in the union should be in ascending order.

//Brute Force Approach
- Use a set to store unique elements from both arrays
- Insert all elements from both arrays into the set
- Convert the set to a vector and return it
- TC : O((N+M) log(N+M)) SC : O(N+M)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &arr1, vector<int> &arr2)
{
    set<int> unionSet;
    for (int num : arr1)
    {
        unionSet.insert(num);
    }
    for (int num : arr2)
    {
        unionSet.insert(num);
    }
    return vector<int>(unionSet.begin(), unionSet.end());
}

//Optimal Approach
- Use two pointers to traverse both arrays
- Compare elements at both pointers and add the smaller element to the result
- Move the pointer of the array from which the element was added
- Skip duplicate elements to ensure uniqueness
- TC : O(N+M) SC : O(N+M)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    vector<int> unionArr;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            if (unionArr.empty() || unionArr.back() != arr1[i])
            {
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            if (unionArr.empty() || unionArr.back() != arr2[j])
            {
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
        else
        {
            if (unionArr.empty() || unionArr.back() != arr1[i])
            {
                unionArr.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    while (i < n)
    {
        if (unionArr.empty() || unionArr.back() != arr1[i])
        {
            unionArr.push_back(arr1[i]);
        }
        i++;
    }

    while (j < m)
    {
        if (unionArr.empty() || unionArr.back() != arr2[j])
        {
            unionArr.push_back(arr2[j]);
        }
        j++;
    }

    return unionArr;
}

//Refactored Optimal Code
- We can optimize the code by reducing the number of checks for duplicates
- Instead of checking if the union array is empty in every condition, we can handle it once at the start of each while loop
- Reduce if/else conditions by combining them where possible
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    vector<int> unionArr;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        int val = 0;
        if (arr1[i] < arr2[j])
        {
            val = arr1[i++];
        }
        else if (arr1[i] > arr2[j])
        {
            val = arr2[j++];
        }
        else
        {
            val = arr1[i++];
            j++;
        }

        if (unionArr.empty() || unionArr.back() != val)
        {
            unionArr.push_back(val);
        }
    }

    while (i < n)
    {
        if (unionArr.empty() || unionArr.back() != arr1[i])
        {
            unionArr.push_back(arr1[i]);
        }
        i++;
    }

    while (j < m)
    {
        if (unionArr.empty() || unionArr.back() != arr2[j])
        {
            unionArr.push_back(arr2[j]);
        }
        j++;
    }

    return unionArr;
}