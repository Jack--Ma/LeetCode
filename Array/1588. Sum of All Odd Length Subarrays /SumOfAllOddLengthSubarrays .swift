//
//  SumOfAllOddLengthSubarrays .swift
//  LeetCode-main
//
//  Created by jackma on 2023/3/4.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/sum-of-all-odd-length-subarrays
 
 Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.

 A subarray is a contiguous subsequence of the array.
 */

extension Solution {
    func SumOfAllOddLengthSubarrays(_ arr: [Int]) -> Int {
        var result = 0
        let length = arr.count
        
        // Array traverse, every element has odd-length subarray
        for i in 0..<length {
            // sum stores add subarrays' sum from i
            var sum = 0
            // tempSum stores subarrays' sum
            var tempSum = 0
            // traverse array from i
            for j in i..<length {
                tempSum+=arr[j]
                // when subarray[i,j] is odd-length subarray
                if ((j-i) % 2 == 0) {
                    sum+=tempSum
                }
            }
            result+=sum
        }
        
        return result
    }
}
