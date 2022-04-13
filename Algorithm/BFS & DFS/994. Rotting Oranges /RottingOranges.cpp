//
//  RottingOranges.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/13.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "RottingOranges.hpp"

/**
 You are given an m x n grid where each cell can have one of three values:
     0 representing an empty cell,
     1 representing a fresh orange, or
     2 representing a rotten orange.
 Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
 
 Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
 
 Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 Output: 4
 
 Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
 Output: -1
 Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
 
 Input: grid = [[0,2]]
 Output: 0
 Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 */

void testRottingOranges() {
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1},
    };
    grid = {
        {2,1,1},
        {0,1,1},
        {1,0,1},
    };
    grid = {{0,2}};
    cout << Solution().orangesRotting(grid) << endl;
}

int Solution::orangesRotting(vector<vector<int>> &grid) {
    const int m = (int)grid.size();
    const int n = (int)grid[0].size();
    
    // 1st. build original rotten oranges vector
    vector<pair<int, int>> rottenOranges;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int num = grid[i][j];
            if (num == 2) {
                rottenOranges.push_back(make_pair(i, j));
            }
        }
    }
    
    int level = 0;
    while (!rottenOranges.empty()) {
        vector<pair<int, int>> nextRottenOranges;
        // 2rd. check every rotten orange 4-direction
        for (pair<int, int> pair : rottenOranges) {
            if (pair.second > 0 && grid[pair.first][pair.second-1] == 1) {
                nextRottenOranges.push_back(make_pair(pair.first, pair.second-1));
                grid[pair.first][pair.second-1] = 2;
            }
            if (pair.second < n-1 && grid[pair.first][pair.second+1] == 1) {
                nextRottenOranges.push_back(make_pair(pair.first, pair.second+1));
                grid[pair.first][pair.second+1] = 2;
            }
            if (pair.first > 0 && grid[pair.first-1][pair.second] == 1) {
                nextRottenOranges.push_back(make_pair(pair.first-1, pair.second));
                grid[pair.first-1][pair.second] = 2;
            }
            if (pair.first < m-1 && grid[pair.first+1][pair.second] == 1) {
                nextRottenOranges.push_back(make_pair(pair.first+1, pair.second));
                grid[pair.first+1][pair.second] = 2;
            }
        }
        rottenOranges = nextRottenOranges;
        if (!rottenOranges.empty()) {
            level++;
        }
    }
    
    // 3rd, check fresh orange exist or not
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int num = grid[i][j];
            if (num == 1) {
                return -1;
            }
        }
    }
    
    return level;
}
