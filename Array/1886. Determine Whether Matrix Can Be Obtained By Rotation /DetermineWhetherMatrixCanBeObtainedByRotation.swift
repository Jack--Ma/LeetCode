//
//  DetermineWhetherMatrixCanBeObtainedByRotation.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/5/8.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation
 
 Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.
 */

extension Solution {
    func DetermineWhetherMatrixCanBeObtainedByRotation(_ mat: [[Int]], _ target: [[Int]]) -> Bool {
        var mat = mat
        let wh = mat.count
        
        if mat == target { return true }
        
        for _ in (0..<3) {
            // rotate three times, adjust whether mat is equal to target
            for i in (0..<wh) {
                for j in (i..<wh) {
                    let temp = mat[i][j]
                    mat[i][j] = mat[j][i]
                    mat[j][i] = temp
                }
            }
            for i in (0..<wh/2) {
                mat.swapAt(i, wh-i-1)
            }
            if mat == target {
                return true
            }
        }
        
        return false
    }
}
