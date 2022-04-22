//
//  NumberOfProvinces.cpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/4/22.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "NumberOfProvinces.hpp"

/**
 There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
 A province is a group of directly or indirectly connected cities and no other cities outside of the group.
 
 You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
 Return the total number of provinces.
 
 Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 Output: 2
 
 Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 Output: 3
 */

void testNumberOfProvinces() {
    vector<vector<int>> isConnected = {
        {1,0,0,1},
        {0,1,1,0},
        {0,1,1,1},
        {1,0,1,1},
    };
    isConnected = {
        {1,1,1},
        {1,1,1},
        {1,1,1},
    };
    cout << Solution().findCircleNum(isConnected) << endl;
}

void _findCircleNum(vector<vector<int>> &isConnected, int &result, int row) {
    // city row is aleady connected with another city
    if (isConnected[row][row] == 0) {
        return;
    }
    // mark find out
    isConnected[row][row] = 0;
    for (int i = 0; i < isConnected.size(); i++) {
        // city i is already connected with another city
        if (isConnected[i][i] == 0) {
            continue;
        }
        if (isConnected[row][i] == 1) {
            // city row to i, and city i to row
            isConnected[row][i] = 0;
            isConnected[i][row] = 0;
            result--;
            // find next connected city i
            _findCircleNum(isConnected, result, i);
        }
    }
}

int Solution::findCircleNum(vector<vector<int>> &isConnected) {
    const int size = (int)isConnected.size();
    // circle num max is width/height
    int result = size;
    for (int i = 0; i < size; i++) {
        _findCircleNum(isConnected, result, i);
    }
    
    return result;
}
