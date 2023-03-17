//
//  LongestConsecutiveSequence .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/17.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/longest-consecutive-sequence
 
 Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

 You must write an algorithm that runs in O(n) time.
 
 Input: nums = [100,4,200,1,3,2]
 Output: 4
 Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 */

extension Solution {
    func LongestConsecutiveSequence(_ nums: [Int]) -> Int {
        // key indicates the number in nums
        // value pair indicates key continuons interval like as (num-pair.0, num+pair.1)
        var map = [Int: (Int,Int)]()
        var result = 0
        for num in nums {
            guard map[num] == nil else { continue }
            // find num left-right interval
            let left = map[num-1], right = map[num+1]
            
            if let left = left, let right = right {
                map[num] = (left.0+1, right.1+1)
            } else if let left = left {
                map[num] = (left.0+1, 0)
            } else if let right = right {
                map[num] = (0, right.1+1)
            } else {
                map[num] = (0, 0)
            }
            // Adjust the left and right points of the interval
            let pair = map[num]
            let lower = num - pair!.0
            let upper = num + pair!.1
            map[lower] = (0, upper - lower)
            map[upper] = (upper - lower, 0)
            let count = upper - lower + 1
            result = max(result, count)
        }
        
        return result
    }
}
