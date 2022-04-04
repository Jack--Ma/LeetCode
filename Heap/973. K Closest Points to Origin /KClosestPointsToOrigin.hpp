//
//  KClosestPointsToOrigin.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/4.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef KClosestPointsToOrigin_hpp
#define KClosestPointsToOrigin_hpp

#include <stdio.h>

// https://leetcode.com/problems/k-closest-points-to-origin/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k);
};

void testKClosest();

#endif /* KClosestPointsToOrigin_hpp */
