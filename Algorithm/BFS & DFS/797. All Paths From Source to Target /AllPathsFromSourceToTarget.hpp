//
//  AllPathsFromSourceToTarget.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/24.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef AllPathsFromSourceToTarget_hpp
#define AllPathsFromSourceToTarget_hpp

#include <stdio.h>

// https://leetcode.com/problems/all-paths-from-source-to-target/
class Solution {
private:
    vector<vector<int>> graph;
    int target;
    void _allPathsSourceTarget(int level, vector<int> path);
    
public:
    vector<vector<int>> result;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph);
};

void testAllPathsFromSourceToTarget();

#endif /* AllPathsFromSourceToTarget_hpp */
