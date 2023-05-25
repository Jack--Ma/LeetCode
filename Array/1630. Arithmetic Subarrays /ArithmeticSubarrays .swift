//
//  ArithmeticSubarrays .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/5/25.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/arithmetic-subarrays
 
 A sequence of numbers is called arithmetic if it consists of at least two elements, and the difference between every two consecutive elements is the same. More formally, a sequence s is arithmetic if and only if s[i+1] - s[i] == s[1] - s[0] for all valid i.
 
 You are given an array of n integers, nums, and two arrays of m integers each, l and r, representing the m range queries, where the ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.
 
 Return a list of boolean elements answer, where answer[i] is true if the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]] can be rearranged to form an arithmetic sequence, and false otherwise.
 */

extension Solution {
    func ArithmeticSubarrays(_ nums: [Int], _ l: [Int], _ r: [Int]) -> [Bool] {
        var result = [Bool]()
        
        for i in 0..<l.count {
            let arr = nums[l[i]...r[i]].sorted()
            var isArithmetic = true
            for j in 2..<arr.count {
                if (arr[j]-arr[j-1]) != (arr[1]-arr[0]) {
                    isArithmetic = false
                    break
                }
            }
            result.append(isArithmetic)
        }
        
        return result
    }
    
}
