//
//  DetermineWhetherMatrixCanBeObtainedByRotation.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/6/8.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "DetermineWhetherMatrixCanBeObtainedByRotation.hpp"

/**
 Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.
 
 Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
 Output: true
 Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
 
 Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
 Output: false
 Explanation: It is impossible to make mat equal to target by rotating mat.
 */

void testDetermineWhetherMatrixCanBeObtainedByRotation() {
    vector<vector<int>> mat = {
        {0,1},
        {1,0},
    };
    vector<vector<int>> target = {
        {1,0},
        {0,1},
    };
    cout << Solution().findRotation(mat, target) << endl;
}

bool Solution::findRotation(vector<vector<int>> &mat, vector<vector<int>> &target) {
    const int n = (int)mat.size();
    
    if (mat == target) {
        return true;
    }
    
    int k = 3;
    while (k > 0) {
        for (int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());       // reverse each row.
        }
        if (mat == target) {
            return true;
        }
    }
    
    return false;
}
