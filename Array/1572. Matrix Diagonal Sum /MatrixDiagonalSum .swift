//
//  MatrixDiagonalSum .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/6.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/matrix-diagonal-sum
 
 Given a square matrix mat, return the sum of the matrix diagonals.

 Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.


 */

extension Solution {
    func MatrixDiagonalSum(_ mat: [[Int]]) -> Int {
        var result = 0
        let l = mat.count
        
        /**
         traverse mat, judge the num satisfies either of the following two conditions. l is mat.length
         1. x-y=0
         2. x+y+1=l
         */
        
        for (i, nums) in mat.enumerated() {
            for (j, num) in nums.enumerated() {
                if (i == j) || (i+j+1 == l) {
                    result += num
                }
            }
        }
        
        return result
    }
}
