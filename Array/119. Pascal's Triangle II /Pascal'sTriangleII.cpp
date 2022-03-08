//
//  Pascal'sTriangleII.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/8.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "Pascal'sTriangleII.hpp"

/**
 Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
 
 Input: rowIndex = 3
 Output: [1,3,3,1]
 
 Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
 */

vector<int> Solution::getRow(int rowIndex) {
    vector<int> result = {1};
    
    for (int i = 0; i < rowIndex; i++) {
        for (int j = (int)result.size()-1; j >= 1; j--) {
            // must reverse from result'tail to head
            result[j] += result[j-1];
        }
        result.push_back(1);
    }
    
    return result;
    
    // time longer method
//    for (int i = 1; i < rowIndex+1; i++) {
//        int rowCount = i+1;
//        vector<int> rowNums(rowCount, 1);
//        for (int j = 1; j <= result.size()-1; j++) {
//            rowNums[j] = result[j-1]+result[j];
//        }
//        result = rowNums;
//    }
//
//    return result;
}

void testGetRow() {
    printVector(Solution().getRow(5));
}
