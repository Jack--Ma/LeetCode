//
//  NumberOf1Bits.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/17.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "NumberOf1Bits.hpp"

/**
 Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
 
 Input: n = 00000000000000000000000000001011
 Output: 3
 Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
 
 Input: n = 00000000000000000000000010000000
 Output: 1
 Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
 
 Input: n = 11111111111111111111111111111101
 Output: 31
 Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
 */

void testNumberOf1Bits() {
    cout << Solution().hammingWeight(0b11111111111111111111111111111101) << endl;
}

int Solution::hammingWeight(uint32_t n) {
    int weight = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            weight++;
        }
        n = n / 2;
    }
    
    return weight;
}
