//
//  Sqrt(x).cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/24.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "Sqrt(x).hpp"

/**
 Given a non-negative integer x, compute and return the square root of x.
 
 Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
 
 Input: x = 4
 Output: 2
 
 Input: x = 8
 Output: 2
 */

void testSqrt() {
    cout << Solution().mySqrt(2147483647) << endl;
}

int Solution::mySqrt(int x) {
    int left = 0, right = x;
    while (left <= right) {
        int p = (left + right) / 2;
        // must transform to long type
        long p_2 = (long)p*(long)p;
        if (p_2 > x) {
            right = p-1;
        } else if (p_2 < x) {
            left = p+1;
        } else {
            return p;
        }
    }
    
    return (left + right) / 2;
}
