//
//  MonotonicArray .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/18.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/monotonic-array
 
 An array is monotonic if it is either monotone increasing or monotone decreasing.

 An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

 Given an integer array nums, return true if the given array is monotonic, or false otherwise.
 */

extension Solution {
    func MonotonicArray(_ nums: [Int]) -> Bool {
        guard nums.count > 1 else { return true }
        var flag = 0
        var i = 0, j = 1
        while j < nums.count {
            let num1 = nums[i], num2 = nums[j]
            if num1 < num2 {
                if flag == 0 {
                    flag = 1
                } else if flag < 1 {
                    return false
                }
            } else if num1 > num2 {
                if flag == 0 {
                    flag = -1
                } else if flag > 0 {
                    return false
                }
            }
            i+=1;j+=1;
        }
        
        return true
    }
}
