//
//  MaxPointsOnALine.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/18.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "MaxPointsOnALine.hpp"

/**
 Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
 
 Input: points = [[1,1],[2,2],[3,3]]
 Output: 3
 
 Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 Output: 4
 */

void testMaxPointsOnALine() {
    vector<vector<int>> points = {
        {1,1},
        {3,2},
        {5,3},
        {2,3},
        {4,1},
        {1,4},
    };
    cout << Solution().maxPoints(points) << endl;
}

int Solution::maxPoints(vector<vector<int>> &points) {
    int result = 0;
    for (int i = 0; i < points.size(); i++) {
        int i_x = points[i][0], i_y = points[i][1];
        unordered_map<long double, int> map;
        // calculate the slope, and use a map represent slope and its count
        for (int j = i+1; j < points.size(); j++) {
            int j_x = points[j][0], j_y = points[j][1];
            // in case 0
            if (i_x == j_x) {
                map[INT_MAX]++;
            } else {
                long double slope = (long double)(j_y - i_y) / (long double)(j_x - i_x);
                map[slope]++;
            }
        }
        int slopeMax = 0;
        for (auto m : map) {
            slopeMax = max(slopeMax, m.second);
        }
        result = max(result, slopeMax);
    }
    
    return result+1;
}
