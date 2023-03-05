//
//  NextGreaterElementI .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/5.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/next-greater-element-i
 
 The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

 You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

 For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

 Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
 
 Constraints:
    1 <= nums1.length <= nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 104
    All integers in nums1 and nums2 are unique.
    All the integers of nums1 also appear in nums2.
 */

extension Solution {
    func NextGreaterElementI(_ nums1: [Int], _ nums2: [Int]) -> [Int] {
        // HashMap: key is nums2's num, value is the num's Next Greater Element
        var map = [Int:Int]()
        // The Monotonic Stack
        var stack = [Int]()
        
        for num in nums2 {
            // Find stack top element's Next Greater Element	
            while let top = stack.last, num > top {
                map[top] = num
                stack.removeLast()
            }
            
            stack.append(num)
        }
        // default is -1
        var result = Array(repeating: -1, count: nums1.count)
        for (i, num) in nums1.enumerated() {
            // find num in map, value is the Next Greater Element
            if let value = map[num] {
                result[i] = value
            }
        }
        
        return result
    }
}
