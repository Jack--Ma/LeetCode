//
//  BestTimeToBuyAndSellStock.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/18.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "BestTimeToBuyAndSellStock.hpp"

/**
 Input: prices = [7,1,5,3,6,4]
 Output: 5
 Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
 
 Input: prices = [7,6,4,3,1]
 Output: 0
 Explanation: In this case, no transactions are done and the max profit = 0.
 */

// my solution
int Solution::maxProfit(vector<int> &prices) {
    int maxProfit = 0;
    int profit = 0;
    int minBuyPrice = INT_MAX; // mark the minimum purchase price
    for (int i = 0; i < prices.size(); i++) {
        int num = prices[i];
        // change the smallest buy price
        minBuyPrice = min(minBuyPrice, num);
        // calculate profit
        profit = num - minBuyPrice;
        maxProfit = max(maxProfit, profit);
    }
    return maxProfit;
}

// time out solution
int timeOutSolutionMaxProfit(vector<int> &prices) {
    if (prices.size() < 2) {
        return 0;
    }
    int result = 0;
    for (int i = 0; i < prices.size(); i++) {
        for (int j = i+1; j < prices.size(); j++) {
            int p1 = prices[i];
            int p2 = prices[j];
            int profit = p2-p1;
            result = max(profit, result);
        }
    }
    return result;
}

void testMaxProfit() {
    vector<int> nums = {2,4,1};
    Solution().maxProfit(nums);
}
