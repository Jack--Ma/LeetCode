//
//  SumOfSquareNumbers.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/6/1.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "SumOfSquareNumbers.hpp"

/**
 Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
 
 0 <= c <= 231 - 1
 
 Input: c = 5
 Output: true
 Explanation: 1 * 1 + 2 * 2 = 5
 
 Input: c = 3
 Output: false
 */

void testSumOfSquareNumbers() {
    // 2147483648
    cout << Solution().judgeSquareSum(2147483647) << endl;
}

bool Solution::judgeSquareSum(int c) {
    int left = 0, right = sqrt(c);
    while (left <= right) {
        long num = powl(left, 2) + powl(right, 2);
        if (num < c) {
            left++;
        } else if (num > c) {
            right--;
        } else {
            return true;
        }
    }
    
    return false;
}
