//
//  MoveZeroes .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/4.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/move-zeroes/
 
 Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

 Note that you must do this in-place without making a copy of the array.
 */

extension Solution {
    func MoveZeroes(_ nums: inout [Int]) {
        var numIndex = 0, zeroIndex = 0
        while numIndex < nums.count && zeroIndex < nums.count {
            // ensure numIndex point to number, zeroIndex point to zero
            if (nums[numIndex] == 0) {
                numIndex+=1
                continue
            }
            if (nums[zeroIndex] != 0) {
                zeroIndex+=1
                continue
            }
            // extra handle with zeroIndex > numIndex
            if (numIndex < zeroIndex) {
                numIndex+=1
                continue
            }
            // exchange two numbers
            nums.swapAt(numIndex, zeroIndex)
            numIndex+=1
            zeroIndex+=1
        }
    }
}
