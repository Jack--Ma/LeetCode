//
//  PlusOne.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/6/5.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "PlusOne.hpp"

/**
 You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
 
 Input: digits = [1,2,3]
 Output: [1,2,4]
 Explanation: The array represents the integer 123.
 Incrementing by one gives 123 + 1 = 124.
 Thus, the result should be [1,2,4].
 */

void testPlusOne() {
    vector<int> digits = {9,9};
    printVector(Solution().plusOne(digits));;
}

vector<int> Solution::plusOne(vector<int> &digits) {
    const int size = (int)digits.size();
    vector<int> result;
    
    bool carryFlag = true;
    for (int i = size-1; i >= 0; i--) {
        int num = digits[i];
        result.insert(result.begin(), (num+(int)carryFlag) % 10);
        carryFlag = (num+(int)carryFlag) / 10;
    }
    if (carryFlag) {
        result.insert(result.begin(), 1);
    }
    return result;
}
