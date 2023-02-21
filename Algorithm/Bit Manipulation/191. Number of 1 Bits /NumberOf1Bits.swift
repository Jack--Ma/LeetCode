//
//  NumberOf1Bits.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/2/21.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/number-of-1-bits
 
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

extension Solution {
    func NumberOf1Bits(_ n: Int) -> Int {
        var result = 0
        var num = n
        while num > 0 {
            if num%2 == 1 {
                result+=1
            }
            num = num / 2
        }
        return result
    }
}
