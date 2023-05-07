//
//  RotateImage.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/5/7.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/rotate-image
 
 You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

 You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
 */

extension Solution {
    func RotateImage(_ matrix: inout [[Int]]) {
        let wh = matrix.count
        
        // 1st: up-down rotate matrix
        var up = 0, down = wh-1
        while up < down {
            matrix.swapAt(down, up)
            up+=1;down-=1;
        }
        
        // 2rd: back-slash(right-top to left-down) rotate matrix
        for i in (0..<wh) {
            for j in (i+1..<wh) {
                let temp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = temp
            }
        }
    }
}
