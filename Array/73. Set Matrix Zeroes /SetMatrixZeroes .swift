//
//  SetMatrixZeroes .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/15.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/set-matrix-zeroes/
 
 Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

 You must do it in place.
 */

extension Solution {
    func SetMatrixZeroes(_ matrix: inout [[Int]]) {
        let height = matrix.count
        let width = matrix[0].count
        
        // col indicates whether there are zeros in each column
        // and row indicates whether there are zeros in each row
        var colMap = Array(repeating: 0, count: width)
        var rowMap = Array(repeating: 0, count: height)
        
        for (i, nums) in matrix.enumerated() {
            for (j, num) in nums.enumerated() {
                if num == 0 {
                    // when num is 0, set i-row and j-col are both 0
                    rowMap[i] = 1
                    colMap[j] = 1
                }
            }
        }
        
        for (i, nums) in matrix.enumerated() {
            for (j, num) in nums.enumerated() {
                if rowMap[i] == 1 {
                    matrix[i][j] = 0
                }
                if colMap[j] == 1 {
                    matrix[i][j] = 0
                }
            }
        }
    }
}
