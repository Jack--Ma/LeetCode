//
//  SearchA2DMatrix.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/23.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "SearchA2DMatrix.hpp"

/**
 Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 Output: true
 
 Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 Output: false
 */

bool _searchMatrix_binary_search(vector<vector<int>> &matrix, int target) {
    const int height = (int)matrix.size();
    const int width = (int)matrix[0].size();
    int left = 0, right = height - 1;
    int i = (left + right) / 2;
    // binary search find target row index
    vector<int> targetRow;
    while (left <= right) {
        vector<int> row = matrix[i];
        if (row[0] <= target && target <= row[width-1]) {
            targetRow = row;
            break;
        } else if (target < row[0]) {
            right = i - 1;
        } else if (target > row[width-1]) {
            left = i + 1;
        }
        i = (left + right) / 2;
    }
    if (targetRow.empty()) {
        return false;
    }
    
    left = 0, right = width - 1;
    i = (left + right) / 2;
    // binary search find target column index
    while (left <= right) {
        int num = targetRow[i];
        if (num == target) {
            return true;
        } else if (target < num) {
            right = i - 1;
        } else if (target > num) {
            left = i + 1;
        }
        i = (left + right) / 2;
    }
    
    return false;
}

// my solution
bool Solution::searchMatrix(vector<vector<int>> &matrix, int target) {
    return _searchMatrix_binary_search(matrix, target);
    int rowSize = (int)matrix.size();
    int colSize = (int)matrix[0].size();
    
    // 1st step: find target row
    int targetRow = INT_MAX;
    for (int i = 0; i < rowSize; i++) {
        int rowNum_0 = matrix[i][0];
        int rowNum_last = matrix[i][colSize-1];
        if (target >= rowNum_0 && target <= rowNum_last) {
            // in this row
            targetRow = i;
            break;
        }
    }
    
    if (targetRow >= rowSize) {
        return false;
    }
    
    // 2st step: find target
    vector<int> targetRowArray = matrix[targetRow];
    for (int j = 0; j < colSize; j++) {
        int num = targetRowArray[j];
        if (num == target) {
            return true;
        }
    }
    return false;
}

void testSearchMatrix() {
    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    matrix = {{1}};
    cout << Solution().searchMatrix(matrix, 0) << endl;
}
