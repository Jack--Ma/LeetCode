//
//  SortIntegersByTheNumberOf1Bits .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/11.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits
 
 You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.
 
 Return the array after sorting it.
 
 Input: arr = [0,1,2,3,4,5,6,7,8]
 Output: [0,1,2,4,8,3,5,6,7]
 Explantion: [0] is the only integer with 0 bits.
 [1,2,4,8] all have 1 bit.
 [3,5,6] have 2 bits.
 [7] has 3 bits.
 The sorted array by bits is [0,1,2,4,8,3,5,6,7]
 */

extension Solution {
    func SortIntegersByTheNumberOf1Bits(_ arr: [Int]) -> [Int] {
        var result = [Int]()
        var bitMap = [Int:[Int]]()
        // sort arr by ascending
        let _arr = arr.sorted(by: <)
        for num in _arr {
            var _num = num
            var bit = 0
            while _num != 0 {
                // odd number bit+1
                if _num%2 == 1 {
                    bit+=1
                }
                _num /= 2
            }
            if bitMap[bit] != nil {
                bitMap[bit]!.append(num)
            } else {
                bitMap[bit] = [num]
            }
        }
        // sort bitMap by key ascending
        let sortedBitMap = bitMap.sorted(by: {$0.0 < $1.0})
        for dict in sortedBitMap {
            result+=dict.value
        }
        
        return result
    }
}
