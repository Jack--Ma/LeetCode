//
//  ValidPerfectSquare.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/22.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "ValidPerfectSquare.hpp"

/**
 Given a positive integer num, write a function which returns True if num is a perfect square else False.
 
 Follow up: Do not use any built-in library function such as sqrt.
 
 Input: num = 16
 Output: true
 
 Input: num = 14
 Output: false
 */

void testValidPerfectSquare() {
    cout << Solution().isPerfectSquare(2147483647) << endl;
}

bool Solution::isPerfectSquare(int num) {
    bool result = false;
    
    // must use long
    long left = 1, right = num;
    while (left <= right) {
        long p = (left+right) / 2;
        // in case of int overflow
        long s = pow(p, 2);
        if (s > num) {
            right = p-1;
        } else if (s < num) {
            // between [p/2, p]
            left = p+1;
        } else {
            result = true;
            break;
        }
    }
    
    return result;
}
