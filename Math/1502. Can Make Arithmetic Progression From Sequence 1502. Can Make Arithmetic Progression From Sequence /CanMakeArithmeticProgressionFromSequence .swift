//
//  CanMakeArithmeticProgressionFromSequence .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/2/26.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence
 
 A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

 Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.
 */

extension Solution {
    func CanMakeArithmeticProgressionFromSequence(_ arr: [Int]) -> Bool {
        var result = true
        
        let _arr = arr.sorted(by: <)
        let diff = _arr[1] - _arr[0]
        for i in 1..<_arr.count-1 {
            if ((_arr[i+1] - _arr[i]) != diff) {
                result = false
                break
            }
        }
        
        return result
    }
}
