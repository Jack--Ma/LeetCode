//
//  MinimumNumberOfVerticesToReachAllNodes.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/28.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef MinimumNumberOfVerticesToReachAllNodes_hpp
#define MinimumNumberOfVerticesToReachAllNodes_hpp

#include <stdio.h>

// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges);
};

void testFindSmallestSetOfVertices();

#endif /* MinimumNumberOfVerticesToReachAllNodes_hpp */
