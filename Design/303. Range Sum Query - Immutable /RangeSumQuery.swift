//
//  RangeSumQuery.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/13.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/range-sum-query-immutable
 
 Given an integer array nums, handle multiple queries of the following type:

 Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
 Implement the NumArray class:

 NumArray(int[] nums) Initializes the object with the integer array nums.
 int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 */

// My solution
class NumArray {
    let nums: [Int]
    
    init(_ nums: [Int]) {
        self.nums = nums
    }
    
    func sumRange(_ left: Int, _ right: Int) -> Int {
        var i = left
        var sum = 0
        while i <= right {
            sum += nums[i]
            i+=1
        }
        return sum
    }
}

// Best solution
class NumArray_Best {
    // store nums' sum array
    var sums = [Int]()

    init(_ nums: [Int]) {
        var sum = 0
        for n in nums {
            sum += n
            sums.append(sum)
        }
    }
    
    // reduce loop count
    func sumRange(_ left: Int, _ right: Int) -> Int {
        var sum = sums[right]
        if (left > 0) {
            sum -= sums[left - 1]
        }
        return sum
    }
}
