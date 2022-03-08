//
//  RotateImage.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/8.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "RotateImage.hpp"

/**
 You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

 You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
 DO NOT allocate another 2D matrix and do the rotation.
 
 Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 Output: [[7,4,1],[8,5,2],[9,6,3]]
 */

void Solution::rotate(vector<vector<int>> &matrix) {
    // 1st: up-down rotate matrix
    int up = 0, down = (int)matrix.size()-1;
    while (up < down) {
        swap(matrix[down--], matrix[up++]);
    }
    
    // 2rd: back-slash(from right-top to left-dwon) rotate matrix
    for (int i = 0; i < (int)matrix.size()-1; i++) {
        for (int j = i+1; j < (int)matrix.size(); j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void testRotate() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution().rotate(matrix);
    printVector(matrix);
}
