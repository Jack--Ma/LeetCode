//
//  SpiralMatrixII.cpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/3/8.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "SpiralMatrixII.hpp"

/**
 Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
 
 Input: n = 3
 Output: [[1,2,3],[8,9,4],[7,6,5]]
 */

vector<vector<int>> Solution::generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n, -1));
    
    // level mean the square level from 0 to n/2
    int level = 0, num = 1;
    while (level < n / 2) {
        // j point to square's outer cycle
        int j = level;
        // every level count equal to 4*(levelCount)
        int levelCount = n-level-1;
        // 1. left to right, horizonal, length is levelCount
        while (j < levelCount) {
            result[level][j] = num++;
            j++;
        }
        j = level;
        // 2. top to bottom, vertical
        while (j < levelCount) {
            result[j][levelCount] = num++;
            j++;
        }
        j = levelCount;
        // 3. right to left, horizonal
        while (j > level) {
            result[levelCount][j] = num++;
            j--;
        }
        j = levelCount;
        // 4. bottom to top, vertical
        while (j > level) {
            result[j][level] = num++;
            j--;
        }
        level++;
    }
    // n is odd number, change the center number
    if (n % 2 == 1) {
        result[n/2][n/2] = n*n;
    }
    return result;
}

void testGenerateMatrix() {
    printVector(Solution().generateMatrix(20));
}
