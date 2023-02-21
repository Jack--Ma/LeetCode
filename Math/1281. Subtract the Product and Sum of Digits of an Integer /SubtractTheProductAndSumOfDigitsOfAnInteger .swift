//
//  SubtractTheProductAndSumOfDigitsOfAnInteger .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/2/21.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer
 
 Given an integer number n, return the difference between the product of its digits and the sum of its digits.
 
 Input: n = 234
 Output: 15
 Explanation:
 Product of digits = 2 * 3 * 4 = 24
 Sum of digits = 2 + 3 + 4 = 9
 Result = 24 - 9 = 15
 */

extension Solution {
    func SubtractTheProductAndSumOfDigitsOfAnInteger(_ n: Int) -> Int {
        var result = 0
        var _sum = 0, _product = 1
        var num = n
        while num>0 {
            _product = _product * (num % 10)
            _sum = _sum + (num % 10)
            num = num / 10
        }
        result = _product - _sum
        return result
    }
}
