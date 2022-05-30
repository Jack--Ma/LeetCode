//
//  CountNegativeNumbersInASortedMatrix.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/30.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "CountNegativeNumbersInASortedMatrix.hpp"

/**
 Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.
 
 Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
 Output: 8
 Explanation: There are 8 negatives number in the matrix.
 */

void testCountNegativeNumbersInASortedMatrix() {
    vector<vector<int>> grid = {
        {4,3,2,-1},
        {3,2,1,-1},
        {1,1,-1,-2},
        {-1,-1,-2,-3},
    };
    grid = {
        {-1},
        {-2},
    };
    cout << Solution().countNegatives(grid) << endl;
}

int Solution::countNegatives(vector<vector<int>> &grid) {
    int result = 0;
    const int m = (int)grid.size();
    const int n = (int)grid[0].size();
    
    // find the last row which row's first number is positive
    int left = 0, right = m-1;
    while (left <= right) {
        int p = (left+right) / 2;
        if (grid[p][0] < 0) {
            right = p-1;
        } else {
            left = p+1;
        }
    }
    
    int lastRow = (left+right) / 2;
    for (int i = 0; i <= lastRow; i++) {
        vector<int> nums = grid[i];
        int l = 0, r = n-1;
        while (l <= r) {
            int q = (l+r) / 2;
            if (nums[q] < 0) {
                r = q-1;
            } else {
                l = q+1;
            }
        }
        // [0, (l + r) / 2] numbers beyond 0
        if (l >= 0 && r >= 0) {
            result+=((l + r) / 2 + 1);
        }
    }
    
    return m * n - result;
}
