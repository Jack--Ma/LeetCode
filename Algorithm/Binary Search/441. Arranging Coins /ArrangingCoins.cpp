//
//  ArrangingCoins.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/26.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "ArrangingCoins.hpp"

/**
 You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.
 
 Given the integer n, return the number of complete rows of the staircase you will build.
 
 Input: n = 5
 Output: 2
 Explanation: Because the 3rd row is incomplete, we return 2.
 
 Input: n = 8
 Output: 3
 Explanation: Because the 4th row is incomplete, we return 3.
 */

void testArrangingCoins() {
    cout << Solution().arrangeCoins(2147483647) << endl;
}

int Solution::arrangeCoins(int n) {
    long left = 1, right = n;
    while (left <= right) {
        long p = (left+right) / 2;
        long maxCoins = (1+p)*p/2;
        if (maxCoins > n) {
            right = p-1;
        } else {
            left = p+1;
        }
    }
    
    return int(left+right) / 2;
}
