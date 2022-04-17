//
//  ReverseBits.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/17.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "ReverseBits.hpp"

/**
 Reverse bits of a given 32 bits unsigned integer.
 
 Input: n = 00000010100101000001111010011100
 Output:    964176192 (00111001011110000010100101000000)
 Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
 
 Input: n = 11111111111111111111111111111101
 Output:   3221225471 (10111111111111111111111111111111)
 Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.
 */

void testReverseBits() {
    cout << Solution().reverseBits(0b1100) << endl;
}

uint32_t Solution::reverseBits(uint32_t n) {
    uint32_t reverse = 0;
    const int bits = 32;
    int i = 0;
    while (i < bits) {
        if (n % 2 == 1) {
            reverse = reverse * 2 + 1;
        } else {
            reverse = reverse * 2;
        }
        n = n / 2;
        i++;
    }
    
    return reverse;
}
