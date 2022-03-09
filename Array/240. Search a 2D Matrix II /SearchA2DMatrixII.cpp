//
//  SearchA2DMatrixII.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/9.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "SearchA2DMatrixII.hpp"

/**
 Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
 - Integers in each row are sorted in ascending from left to right.
 - Integers in each column are sorted in ascending from top to bottom.

 Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
 Output: true
 */

// timeout solution
bool _searchMatrixII_timeout(vector<vector<int>> &matrix, int target) {
    for (vector<int> nums : matrix) {
        if (target >= nums[0] && target <= nums[nums.size()-1]) {
            // use bisection method
            int a = 0, b = (int)nums.size()-1;
            int i = (a + b) / 2;
            while (i >= a && i <= b) {
                if (target < nums[i]) {
                    b = i - 1;
                    i = (a + b) / 2;
                } else if (target > nums[i]) {
                    a = i + 1;
                    i = (a + b) / 2;
                } else {
                    return true;
                }
            }
        }
    }
    return false;
}

// better solution
bool Solution::searchMatrixII(vector<vector<int>> &matrix, int target) {
    int n = (int)matrix.size(), m = (int)matrix[0].size();
    int i = 0, j = m-1;
    // from right-top corner to the target
    while (i < n && j >= 0) {
        if (target < matrix[i][j]) {
            // target is smaller, turn left
            j--;
        } else if (target > matrix[i][j]) {
            // targt is bigger, turn down
            i++;
        } else {
            return true;
        }
    }
    
    return false;
}

void testSearchMatrixII() {
    vector<vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    
    cout << Solution().searchMatrixII(matrix, 25) << endl;
}
