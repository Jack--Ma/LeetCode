//
//  AddToArrayFormOfInteger.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/5/5.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/add-to-array-form-of-integer/
 
 The array-form of an integer num is an array representing its digits in left to right order.
    * For example, for num = 1321, the array form is [1,3,2,1].
 Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.
 */

extension Solution {
    func AddToArrayFormOfInteger(_ nums: [Int], _ k: Int) -> [Int] {
        var result = [Int]()
        
        var carryFlag = 0
        var k = k
        for i in (0..<nums.count).reversed() {
            let num = nums[i]
            let num_k = k % 10
            k /= 10
            result.insert((num+num_k+carryFlag) % 10, at: 0)
            carryFlag = (num+num_k+carryFlag) / 10
        }
        while k > 0 {
            let num_k = k % 10
            k /= 10
            result.insert((num_k+carryFlag) % 10, at: 0)
            carryFlag = (num_k+carryFlag) / 10
        }
        if carryFlag > 0 {
            result.insert(carryFlag, at: 0)
        }
        return result
    }
}
