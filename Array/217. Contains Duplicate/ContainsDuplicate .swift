//
//  ContainsDuplicate .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/12.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/contains-duplicate
 
 Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
 */

extension Solution {
    func ContainsDuplicate(_ nums: [Int]) -> Bool {
        var numsMap = [Int:Int]()
        
        for num in nums {
            if numsMap[num] == nil {
                numsMap[num] = 1
            } else {
                return true
            }
        }
        
        return false
    }
}
