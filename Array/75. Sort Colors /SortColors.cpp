//
//  SortColors.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/7.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "SortColors.hpp"

/**
 Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
 
 We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
 
 You must solve this problem without using the library's sort function.
 
 Input: nums = [2,0,2,1,1,0]
 Output: [0,0,1,1,2,2]
 */

// other solution by in-place algorithm
void _sortColors_inPlace(vector<int> &nums) {
    // Do not use another memory space like map/vector
    int start = 0, mid = 0, end = (int)nums.size()-1;
    while (mid <= end) {
        if (nums[mid] == 2) {
            // put 2 to list tail
            swap(nums[mid], nums[end]);
            end--;
        } else if (nums[mid] == 1) {
            mid++;
        } else if(nums[mid] == 0) {
            // put 0 to list head
            swap(nums[mid], nums[start]);
            start++;
            mid++;
        }
    }
}

// my solution
void Solution::sortColors(vector<int> &nums) {
    unordered_map<int, vector<int>> colorMap;
    for (int num : nums) {
        vector<int> colors = colorMap[num];
        colors.push_back(num);
        colorMap[num] = colors;
    }
    vector<int> redColors = colorMap[0];
    vector<int> whiteColors = colorMap[1];
    vector<int> blueColors = colorMap[2];
    nums.clear();
    nums.insert(nums.end(), redColors.begin(), redColors.end());
    nums.insert(nums.end(), whiteColors.begin(), whiteColors.end());
    nums.insert(nums.end(), blueColors.begin(), blueColors.end());
}

void testSortColors() {
    vector<int> nums = {2,0,1};
//    Solution().sortColors(nums);
    _sortColors_inPlace(nums);
    printVector(nums);
}
