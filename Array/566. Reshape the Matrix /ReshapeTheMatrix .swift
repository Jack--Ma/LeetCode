//
//  ReshapeTheMatrix .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/6.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/reshape-the-matrix
 
 In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

 You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

 The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

 If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
 */

extension Solution {
    func ReshapeTheMatrix(_ mat: [[Int]], _ r: Int, _ c: Int) -> [[Int]] {
        let h = mat.count, v = mat[0].count
        // build r*c array
        var result = Array(repeating: Array(repeating: 0, count: c), count: r)
        
        // special case protect
        if ((h*v != r*c) || (h==r && v==c)) {
            return mat
        }
        
        // result matrix's index
        var x = 0, y = 0
        for i in 0..<h {
            for j in 0..<v {
                result[x][y] = mat[i][j]
                // change column
                y+=1
                // change row
                if y == c {
                    y = 0
                    x+=1
                }
            }
        }
        
        return result
    }
}
