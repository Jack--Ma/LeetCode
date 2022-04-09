//
//  MaximalRectangle.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/9.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <stack>
#include "MaximalRectangle.hpp"

/**
 Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
 
 Input: matrix = [
 ["1","0","1","0","0"],
 ["1","0","1","1","1"],
 ["1","1","1","1","1"],
 ["1","0","0","1","0"]
 ]
 Output: 6
 Explanation: The maximal rectangle is shown in the above picture.
 */

void testMaximalRectangle() {
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'},
    };
    cout << Solution().maximalRectangle(matrix) << endl;
}

/// use monotonous stack
int _largestRectangleArea(vector<int> &heights) {
    int maxArea = 0;
    heights.push_back(-1);
    const int size = (int)heights.size();
    stack<int> monoStack;
    monoStack.push(-1);
    
    for (int i = 0; i < size; i++) {
        while (monoStack.size() > 1 && heights[monoStack.top()] >= heights[i]) {
            int top = monoStack.top();
            monoStack.pop();
            // left minimum
            int top_left = monoStack.top();
            // right minimum
            int top_right = i;
            // area
            int height = heights[top];
            int width = top_right - top_left - 1;
            maxArea = max(maxArea, width * height);
        }
        monoStack.push(i);
    }
    
    return maxArea;
}

int Solution::maximalRectangle(vector<vector<char>> &matrix) {
    int maxRect = 0;
    const int height = (int)matrix.size();
    const int width = (int)matrix[0].size();
    
    vector<int> heights(width, 0);
    for (int i = 0; i < height; i++) {
        vector<char> row = matrix[i];
        // build every row's heights
        for (int j = 0; j < width; j++) {
            if (row[j] == '1') {
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }
        int largestArea = _largestRectangleArea(heights);
        maxRect = max(maxRect, largestArea);
    }
    
    return maxRect;
}
