//
//  FloodFill.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/11.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef FloodFill_hpp
#define FloodFill_hpp

#include <stdio.h>

// https://leetcode.com/problems/flood-fill/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor);
};

void testFloodFill();

#endif /* FloodFill_hpp */
