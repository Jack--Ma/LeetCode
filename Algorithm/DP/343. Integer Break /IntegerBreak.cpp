//
//  IntegerBreak.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/13.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "IntegerBreak.hpp"

/**
 Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
 
 Return the maximum product you can get.
 
 Input: n = 2
 Output: 1
 Explanation: 2 = 1 + 1, 1 × 1 = 1.
 
 Input: n = 10
 Output: 36
 Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 */

void testIntegerBreak() {
    cout << Solution().integerBreak(58) << endl;
}

int _integerBreak_DP(int n) {
    if (n == 2) {
        return 1;
    } else if (n == 3) {
        return 2;
    }
    /**
     1. n: 2+2+3+.....+3
     2. n+1: 2+3+3+.....+3
     3. n+2: 3+3+3+.....+3
     4. n+3: 2+2+3+.....+3+3
     */
    int a = (n-4) / 3;
    int b = (n-4) % 3;
    switch (b) {
        case 0:{
            return pow(2, 2) * pow(3, a);
        }
            break;
        case 1:{
            return pow(2, 1) * pow(3, a+1);
        }
            break;
        case 2:{
            return pow(2, 0) * pow(3, a+2);
        }
            break;
        default:
            break;
    }
    return 0;
}

int Solution::integerBreak(int n) {
    return _integerBreak_DP(n);
}
