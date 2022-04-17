//
//  Triangle.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/17.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "Triangle.hpp"

/**
 Given a triangle array, return the minimum path sum from top to bottom.
 
 For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
 
 Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 Output: 11
 Explanation: The triangle looks like:
    2
   3 4
  6 5 7
 4 1 8 3
 The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
 */

void testTriangle() {
    vector<vector<int>> tri = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3},
    };
    cout << Solution().minimumTotal(tri) << endl;
}

int Solution::minimumTotal(vector<vector<int>> &triangle) {
    const int height = (int)triangle.size();
    const int width = (int)triangle[height-1].size();
    
    /**
     f(1,1) = tri(1,1) + min(tri(2,1), tri(2,2))
     ...
     f(i,j) = tri(i,j) + min(tri(i+1,j), tri(i+1,j+1))
     */
    vector<int> cache(width+1, 0);
    // traverse from bottom to top
    for (int i = height - 1; i >= 0; i--) {
        vector<int> row = triangle[i];
        vector<int> lastCache(row.size()+1, 0);
        for (int j = 0; j < row.size(); j++) {
            int num = triangle[i][j];
            // build last layer cache
            lastCache[j] = num + min(cache[j], cache[j+1]);
        }
        cache = lastCache;
    }
    
    return cache[0];
}
