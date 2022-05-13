//
//  CoinChange.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/11.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "CoinChange.hpp"

/**
 You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

 Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

 You may assume that you have an infinite number of each kind of coin.
 
 Input: coins = [1,2,5], amount = 11
 Output: 3
 Explanation: 11 = 5 + 5 + 1
 
 Input: coins = [2], amount = 3
 Output: -1
 */

void testCoinChange() {
    /**
     [186,419,83,408]
     6249
     [2147483647]
     2
     */
    vector<int> coins = {2147483647};
    cout << Solution().coinChange(coins, 2) << endl;
}

// solution by use recursion
// Time Limit Exceeded
void _coinChange_recursion(vector<int> &coins, int amount, int count, int& result) {
    if (amount == 0) {
        // find valid change
        result = min(result, count);
    } else {
        for (int coin : coins) {
            if (amount >= coin) {
                _coinChange_recursion(coins, amount-coin, count+1, result);
            }
        }
    }
}

int _coinChange_DP(vector<int> &coins, int amount) {
    int DP[10001] = {0};
    // default coin change value is 1
    for (int j = 0; j < coins.size(); j++) {
        int coin = coins[j];
        if (coin <= amount) {
            DP[coin] = 1;
        }
    }
    /**
     Same with Leetcode70. The formula is:
     DP[n] = 1 + min(DP[n-coins[0]], DP[n-coins[1]],..., DP[n-coins[i])
     */
    for (int i = 1; i <= amount; i++) {
        if (DP[i] != 0) {
            continue;
        }
        int minChange = INT_MAX;
        for (int j = 0; j < coins.size(); j++) {
            int coin = coins[j];
            if (coin < i) {
                int change = DP[i-coin];
                if (change > 0) {
                    minChange = min(minChange, change);
                }
            }
        }
        if (minChange != INT_MAX) {
            DP[i] = minChange+1;
        }
    }
    return DP[amount] != 0 ? DP[amount] : -1;
}

int Solution::coinChange(vector<int> &coins, int amount) {
    if (amount == 0) {
        return 0;
    }
    
    return _coinChange_DP(coins, amount);
}
