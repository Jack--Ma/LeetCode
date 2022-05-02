//
//  UniquePaths.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/2.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "UniquePaths.hpp"

/**
 There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
 
 Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

 The test cases are generated so that the answer will be less than or equal to 2 * 109.
 
 Input: m = 3, n = 7
 Output: 28
 
 Input: m = 3, n = 2
 Output: 3
 Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
 1. Right -> Down -> Down
 2. Down -> Down -> Right
 3. Down -> Right -> Down
 */

void testUniquePaths() {
    cout << Solution().uniquePaths(3, 5) << endl;
}

int Solution::uniquePaths(int m, int n) {
    /**
     every node in path map means the paths from (0,0) to (i,j)
     eg m=3, n=5
     1 1 1 1 1
     1 2 3 4 5
     1 3 6 10 15
     f(i,j) = f(i-1,j) + f(i,j-1)
     */
    vector<vector<int>> pathMap(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            pathMap[i][j] = pathMap[i-1][j] + pathMap[i][j-1];
        }
    }
    return pathMap[m-1][n-1];
}
