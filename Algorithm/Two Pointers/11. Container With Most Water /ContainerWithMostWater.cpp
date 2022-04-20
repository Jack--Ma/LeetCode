//
//  ContainerWithMostWater.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/19.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "ContainerWithMostWater.hpp"

/**
 You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
 
 Find two lines that together with the x-axis form a container, such that the container contains the most water.
 
 Return the maximum amount of water a container can store.
 
 Input: height = [1,8,6,2,5,4,8,3,7]
 Output: 49
 Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
 */

void testContainerWithMostWater() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << Solution().maxArea(height) << endl;
}

/// solution by use only one-level loop
int _maxArea_better(vector<int> &height) {
    int maxArea = 0;
    int size = (int)height.size();
    int left = 0, right = size - 1;
    while (left < right) {
        int minHeight = min(height[left], height[right]);
        int width = right - left;
        int area = width * minHeight;
        maxArea = max(maxArea, area);
        // move left or right pointer
        if (height[left] <= height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return maxArea;
}

/// solution by use two-level loop
int Solution::maxArea(vector<int> &height) {
//    return _maxArea_better(height);
    int maxArea = 0;
    int size = (int)height.size();
    
    int leftMax = 0;
    // a pointer from left side
    for (int i = 0; i < size; i++) {
        int leftNum = height[i];
        // no need to deal with number below max
        if (leftMax >= leftNum) {
            continue;
        }
        leftMax = leftNum;
        // new pointer from right side
        int area = 0;
        int rightMax = 0;
        for (int j = size - 1; j > i; j--) {
            int rightNum = height[j];
            int width = j - i;
            // no need to deal with number below max
            if (rightMax >= rightNum) {
                continue;
            }
            rightMax = rightNum;
            // the area maxHeight is leftNum
            if (rightNum > leftNum) {
                area = max(area, leftNum * width);
                break;
            }
            // area is already biggest
            if (area >= width*max(leftNum, rightNum)) {
                break;
            }
            area = max(area, width*min(leftNum, rightNum));
        }
        maxArea = max(maxArea, area);
    }
    
    return maxArea;
}
