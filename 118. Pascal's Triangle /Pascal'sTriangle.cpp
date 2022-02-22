//
//  Pascal'sTriangle.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/21.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "Pascal'sTriangle.hpp"

/**
 Input: numRows = 5
 Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 */

// my solution
vector<vector<int>> Solution::generate(int numRows) {
    vector<vector<int>> result;
    
    for (int i = 0; i < numRows; i++) {
        // nums count is i+1
        vector<int> nums(i+1, 1);
        for (int j = 0; j < i+1; j++) {
            if (j != 0 && j != i) {
                nums[j] = result[i-1][j-1]+result[i-1][j];
            }
        }
        result.push_back(nums);
    }
    
    return result;
}

void testGenerate() {
    Solution().generate(5);
}
