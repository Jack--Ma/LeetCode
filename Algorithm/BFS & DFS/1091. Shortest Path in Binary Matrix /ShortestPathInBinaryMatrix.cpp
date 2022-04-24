//
//  ShortestPathInBinaryMatrix.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/23.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <queue>
#include "ShortestPathInBinaryMatrix.hpp"

/**
 Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
 
 A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
    * All the visited cells of the path are 0.
    * All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
 The length of a clear path is the number of visited cells of this path.
 
 Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
 Output: 4
 */

void testShortestPathInBinaryMatrix() {
    vector<vector<int>> grid = {
        {0,0,0},
        {1,1,0},
        {1,1,0}
    };
    cout << Solution().shortestPathBinaryMatrix(grid) << endl;
}

int Solution::shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    // 8-directions
    int dir[8][2] = {{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
    const int WH = (int)grid.size();
    if (grid[0][0] == 1 ||
        grid[WH-1][WH-1] == 1) {
        return -1;
    }
    int minPath = 0;
    
    queue<pair<int, int>> gridQueue;
    gridQueue.push(make_pair(0, 0));
    grid[0][0] = 1;
    while (!gridQueue.empty()) {
        minPath++;
        // find all queue's nodes nearby nodes
        int size = (int)gridQueue.size();
        for (int i = 0; i < size; i++) {
            pair<int, int> p = gridQueue.front();
            gridQueue.pop();
            // find the target point
            if (p.first == p.second && p.first == WH - 1) {
                return minPath;
            }

            for (int j = 0; j < 8; j++) {
                int next_p_h = p.first + dir[j][0];
                int next_p_w = p.second + dir[j][1];
                if (next_p_h >= 0 && next_p_h < WH &&
                    next_p_w >= 0 && next_p_w < WH &&
                    grid[next_p_h][next_p_w] == 0) {
                    // nearby node is valid
                    gridQueue.push(make_pair(next_p_h, next_p_w));
                    grid[next_p_h][next_p_w] = 1;
                }
            }
        }
    }
    
    return -1;
}
