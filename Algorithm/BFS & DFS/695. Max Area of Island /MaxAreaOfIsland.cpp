//
//  MaxAreaOfIsland.cpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/4/12.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "MaxAreaOfIsland.hpp"

/**
 You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
 
 The area of an island is the number of cells with a value 1 in the island.
 
 Return the maximum area of an island in grid. If there is no island, return 0.
 
 Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 Output: 6
 Explanation: The answer is not 11, because the island must be connected 4-directionally.
 */

void testMaxAreaOfIsland() {
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    cout << Solution().maxAreaOfIsland(grid) << endl;
}

/// solution by use dfs recursion
int _areaOfIsland_recursion(vector<vector<int>> &grid, int i, int j) {
    if (i < 0 || i >= grid.size() ||
        j < 0 || j >= grid[0].size() ||
        grid[i][j] == 0) {
        return 0;
    }
    int area = 1;
    grid[i][j] = 0;
    area += _areaOfIsland_recursion(grid, i-1, j);
    area += _areaOfIsland_recursion(grid, i+1, j);
    area += _areaOfIsland_recursion(grid, i, j-1);
    area += _areaOfIsland_recursion(grid, i, j+1);
    
    return area;
}

int Solution::maxAreaOfIsland(vector<vector<int>> &grid) {
    const int height = (int)grid.size();
    const int width = (int)grid[0].size();
    int maxArea = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int area = _areaOfIsland_recursion(grid, i, j);
            maxArea = max(maxArea, area);
        }
    }
    
    return maxArea;
}
