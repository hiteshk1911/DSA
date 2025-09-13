You are given an array of prices where prices[i] is the price of a given stock on an ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

//Brute Force Approach
- Use two nested loops to consider all possible pairs of buy and sell days
- Calculate the profit for each pair and keep track of the maximum profit
- TC : O(N^2) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int maxProfitBruteForce(vector<int> &prices) {
    int n = prices.size();
    int maxProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int profit = prices[j] - prices[i];
            maxProfit = max(maxProfit, profit);
        }
    }

    return maxProfit;
}

//Optimal Approach
- Use a single loop to keep track of the minimum price seen so far and calculate the profit for each day
- Update the maximum profit whenever a higher profit is found
- TC : O(N) SC : O(1)
- CPP Code:

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int i = 0; i < n; i++) {
        minPrice = min(minPrice, prices[i]);
        int profit = prices[i] - minPrice;
        maxProfit = max(maxProfit, profit);
    }

    return maxProfit;
}