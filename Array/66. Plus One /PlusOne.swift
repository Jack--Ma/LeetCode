//
//  PlusOne.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/4/14.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/plus-one
 
 You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

 Increment the large integer by one and return the resulting array of digits.
 */

extension Solution {
    func PlusOne(_ digits: [Int]) -> [Int] {
        var result = Array<Int>()
        
        let size = digits.count
        var carryFlag = 1
        for i in (0..<size).reversed() {
            let num = digits[i]
            let plusNum = (num+carryFlag) % 10
            carryFlag = (num+carryFlag) / 10
            result.append(plusNum)
        }
        if carryFlag > 0 {
            result.append(carryFlag)
        }
        return result.reversed()
    }
}
