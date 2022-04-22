//
//  NumberOfIslands.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/22.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "NumberOfIslands.hpp"

/**
 Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
 
 An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 
 Input: grid = [
   ["1","1","1","1","0"],
   ["1","1","0","1","0"],
   ["1","1","0","0","0"],
   ["0","0","0","0","0"]
 ]
 Output: 1
 
 Input: grid = [
   ["1","1","0","0","0"],
   ["1","1","0","0","0"],
   ["0","0","1","0","0"],
   ["0","0","0","1","1"]
 ]
 Output: 3
 */

void testNumberOfIslands() {
    vector<vector<char>> grid = {
        {'1','0','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'},
    };
    cout << Solution().numIslands(grid) << endl;
}

bool _existIslands(vector<vector<char>> &grid, pair<int, int> point) {
    if (grid[point.first][point.second] == '0') {
        return false;
    }
    // find island, traverse around sides points
    grid[point.first][point.second] = '0';
    if (point.first > 0) {
        _existIslands(grid, make_pair(point.first-1, point.second));
    }
    if (point.first < grid.size() - 1) {
        _existIslands(grid, make_pair(point.first+1, point.second));
    }
    if (point.second > 0) {
        _existIslands(grid, make_pair(point.first, point.second-1));
    }
    if (point.second < grid[0].size() - 1) {
        _existIslands(grid, make_pair(point.first, point.second+1));
    }
    return true;
}

int Solution::numIslands(vector<vector<char>> &grid) {
    int result = 0;
    const int height = (int)grid.size();
    const int width = (int)grid[0].size();
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (_existIslands(grid, make_pair(i, j))) {
                result++;
            }
        }
    }
    
    return result;
}
