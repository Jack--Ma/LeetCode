//
//  PowerOfTwo.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/17.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "PowerOfTwo.hpp"

/**
 Given an integer n, return true if it is a power of two. Otherwise, return false.
 An integer n is a power of two, if there exists an integer x such that n == 2x.
 
 Input: n = 16
 Output: true
 Explanation: 24 = 16
 */

void testPowerOfTwo() {
    cout << Solution().isPowerOfTwo(30) << endl;
}

bool Solution::isPowerOfTwo(int n) {
    if (n < 0) {
        return false;
    }
    while (n > 1) {
        if (n % 2 == 1) {
            return false;
        }
        n = n / 2;
    }
    
    return n == 1;
}
