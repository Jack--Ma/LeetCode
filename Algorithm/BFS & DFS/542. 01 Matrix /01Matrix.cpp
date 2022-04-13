//
//  01Matrix.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/12.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "01Matrix.hpp"

/**
 Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
 The distance between two adjacent cells is 1.
 
 Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
 Output: [[0,0,0],[0,1,0],[0,0,0]]
 
 Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
 Output: [[0,0,0],[0,1,0],[1,2,1]]
 */

void test01Matrix() {
    vector<vector<int>> mat = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    mat = {
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };
    printVector(Solution().updateMatrix(mat));
}

vector<vector<int>> Solution::updateMatrix(vector<vector<int>>& mat) {
    const int m = (int)mat.size();
    const int n = (int)mat[0].size();

    vector<vector<int>> result(m, vector<int>(n, 0));
    // store every level cells, from 0
    vector<pair<int, int>> cellVector;
    // flag mark the cell did used or not
    vector<vector<int>> flag(m, vector<int>(n, 0));
    // 1st. vector add 0 level cells
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int num = mat[i][j];
            if (num == 0) {
                cellVector.push_back(make_pair(i, j));
                flag[i][j] = 1;
            }
        }
    }

    int level = 0;
    while (!cellVector.empty()) {
        // next level cells
        vector<pair<int, int>> nextCellVector;
        for (pair<int, int> pair : cellVector) {
            result[pair.first][pair.second] = level;
            // 2rd. build next level from 4-directions
            if (pair.second > 0 && flag[pair.first][pair.second-1] == 0) {
                nextCellVector.push_back(make_pair(pair.first, pair.second-1));
                flag[pair.first][pair.second-1] = 1;
            }
            if (pair.second < n-1 && flag[pair.first][pair.second+1] == 0) {
                nextCellVector.push_back(make_pair(pair.first, pair.second+1));
                flag[pair.first][pair.second+1] = 1;
            }
            if (pair.first > 0 && flag[pair.first-1][pair.second] == 0) {
                nextCellVector.push_back(make_pair(pair.first-1, pair.second));
                flag[pair.first-1][pair.second] = 1;
            }
            if (pair.first < m-1 && flag[pair.first+1][pair.second] == 0) {
                nextCellVector.push_back(make_pair(pair.first+1, pair.second));
                flag[pair.first+1][pair.second] = 1;
            }
        }
        cellVector = nextCellVector;
        level++;
    }

    return result;
}
