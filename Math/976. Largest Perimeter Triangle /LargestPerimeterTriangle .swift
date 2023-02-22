//
//  LargestPerimeterTriangle .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/2/21.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/largest-perimeter-triangle
 
 Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.
 
 Input: nums = [2,1,2]
 Output: 5
 Explanation: You can form a triangle with three side lengths: 1, 2, and 2.
 */

extension Solution {
    func LargestPerimeterTriangle(_ nums: [Int]) -> Int {
        var result = 0
        
        let _nums = nums.sorted(by: { a, b in
            return a > b
        })
        print(_nums)

        for i in 0..<_nums.count-2 {
            let num1 = _nums[i], num2 = _nums[i+1], num3 = _nums[i+2]
            
            if (num2+num3) > num1 {
                result = num1 + num2 + num3
                break
            }
        }

        return result
    }
}
