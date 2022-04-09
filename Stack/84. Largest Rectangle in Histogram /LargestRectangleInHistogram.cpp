//
//  LargestRectangleInHistogram.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/9.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <stack>
#include "LargestRectangleInHistogram.hpp"

/**
 Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
 
 Input: heights = [2,1,5,6,2,3]
 Output: 10
 Explanation: The above is a histogram where width of each bar is 1.
 The largest rectangle is shown in the red area, which has an area = 10 units.
 */

void testLargestRectangleInHistogram() {
    vector<int> heights = {1,1};
    cout << Solution().largestRectangleArea(heights) << endl;
}

/// solution by use traversal
/// @note Time complexity O(n*n) Time Limit Exceeded
int _largestRectangleArea_traverse(vector<int> &heights) {
    int maxArea = 0;
    const int size = (int)heights.size();
    
    for (int i = 0; i < size; i++) {
        int height = heights[i];
        // find [0, i) first index which height is smaller
        int left = i;
        while (left >= 0 && heights[left] >= height) {
            left--;
        }
        // find (i, size-1] first index which height is smaller
        int right = i;
        while (right < size && heights[right] >= height) {
            right++;
        }
        int width = right - left - 1;
        maxArea = max(maxArea, width * height);
    }
    
    return maxArea;
}

/// solution by use monotonous stack
int _largestRectangleArea_monotonous_stack(vector<int> &heights) {
    int maxArea = 0;
    const int size = (int)heights.size();
    
    vector<int> left(size, -1);
    stack<int> leftStack;
    for (int i = 0; i < size; i++) {
        // from left to right, keep stack is incremental
        while (!leftStack.empty() && heights[leftStack.top()] >= heights[i]) {
            leftStack.pop();
        }
        left[i] = (leftStack.empty() ? -1 : leftStack.top());
        leftStack.push(i);
    }
    vector<int> right(size, size);
    stack<int> rightStack;
    for (int j = size - 1; j >= 0; j--) {
        // from right to left, keep stack is incremental
        while (!rightStack.empty() && heights[rightStack.top()] >= heights[j]) {
            rightStack.pop();
        }
        right[j] = (rightStack.empty() ? size : rightStack.top());
        rightStack.push(j);
    }
    // calculate max area
    for (int k = 0; k < size; k++) {
        int height = heights[k];
        int width = right[k] - left[k] - 1;
        maxArea = max(maxArea, height * width);
    }
    
    return maxArea;
}

/// solution by use monotonous stack after optimization
int _largestRectangleArea_monotonous_stack_optimize(vector<int> &heights) {
    int maxArea = 0;
    // in order to traverse all stack elements
    heights.push_back(-1);
    const int size = (int)heights.size();
    
    stack<int> monoStack;
    monoStack.push(-1);
    for (int i = 0; i < size; i++) {
        while (monoStack.size() > 1 && heights[monoStack.top()] >= heights[i]) {
            int top = monoStack.top();
            // after element [top] pop of stack
            monoStack.pop();
            // top_right mean the new element [i] is the first smaller number afer [top]
            int top_right = i;
            // top_left mean the stack's top element is the first smaller number before [top]
            int top_left = monoStack.top();
            // calculate area
            int height = heights[top];
            int width = top_right - top_left - 1;
            maxArea = max(maxArea, width*height);
        }
        monoStack.push(i);
    }

    return maxArea;
}

int Solution::largestRectangleArea(vector<int> &heights) {
    return _largestRectangleArea_monotonous_stack_optimize(heights);
}
