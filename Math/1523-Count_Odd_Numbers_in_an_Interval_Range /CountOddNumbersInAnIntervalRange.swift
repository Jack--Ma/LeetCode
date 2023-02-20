//
//  CountOddNumbersInAnIntervalRange.swift
//  LeetCode-main
//
//  Created by jackma on 2023/2/20.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/?envType=study-plan&id=programming-skills-i
 
 Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

 Input: low = 3, high = 7
 Output: 3
 Explanation: The odd numbers between 3 and 7 are [3,5,7].
 */

extension Solution {
    func CountOddNumbersInAnIntervalRange(_ low: Int, _ high: Int) -> Int {
        var result = 0
        let low_odd = low % 2, high_odd = high % 2
        switch (low_odd|high_odd) {
        case 0:
            result += ((high - low) / 2)
        case 1:
            result += ((high - low) / 2 + 1)
        default:
            result += ((high - low) / 2)
        }
        
        return result
    }
}
