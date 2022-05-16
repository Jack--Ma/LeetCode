//
//  BitwiseAndOfNumbersRange.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/15.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "BitwiseAndOfNumbersRange.hpp"

/**
 Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.
 
 Input: left = 5, right = 7
 Output: 4
 
 Input: left = 0, right = 0
 Output: 0
 
 Input: left = 1, right = 2147483647
 Output: 0
 */

void testBitwiseAndOfNumbersRange() {
    cout << Solution().rangeBitwiseAnd(5, 7) << endl;
}

int Solution::rangeBitwiseAnd(int left, int right) {
    if (left == 0 || right == 0) {
        return 0;
    }
    
    /**
     The core is log2(left) must equal to log2(right)
     If not, such as 3 ~ 5, 0b0011 & 0b0100 & 0b0101
     Must exist a number such as 4/8/16....
     */
    if ((int)log2(left) != (int)log2(right)) {
        return 0;
    }
    
    int result = left;
    for (long i = left; i < right; i++) {
        result = result & i;
    }
    return result;
}
