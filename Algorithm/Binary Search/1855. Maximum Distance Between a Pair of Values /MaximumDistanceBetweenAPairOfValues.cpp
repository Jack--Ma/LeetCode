//
//  MaximumDistanceBetweenAPairOfValues.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/6/1.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "MaximumDistanceBetweenAPairOfValues.hpp"

/**
 You are given two non-increasing 0-indexed integer arrays nums1​​​​​​ and nums2​​​​​​.
 
 A pair of indices (i, j), where 0 <= i < nums1.length and 0 <= j < nums2.length, is valid if both i <= j and nums1[i] <= nums2[j]. The distance of the pair is j - i​​​​.
 
 Return the maximum distance of any valid pair (i, j). If there are no valid pairs, return 0.
 
 Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
 Output: 2
 Explanation: The valid pairs are (0,0), (2,2), (2,3), (2,4), (3,3), (3,4), and (4,4).
 The maximum distance is 2 with pair (2,4).
 */

void testMaximumDistanceBetweenAPairOfValues() {
    vector<int> nums1 = {55,30,5,4,2};
    vector<int> nums2 = {100,20,10,10,5};
    cout << Solution().maxDistance(nums1, nums2) << endl;
}

int Solution::maxDistance(vector<int> &nums1, vector<int> &nums2) {
    const int size1 = (int)nums1.size();
    const int size2 = (int)nums2.size();
    int result = 0;
    
    for (int i = 0; i < size1; i++) {
        int num1 = nums1[i];
        
        // find all index which num2 is bigger than num1
        int left = i, right = size2-1;
        while (left <= right) {
            int p = (left+right) / 2;
            int num2 = nums2[p];
            if (num2 >= num1) {
                // get the distance between index1 and index2
                int distance = p - i;
                result = max(result, distance);
                left = p + 1;
            } else {
                right = p - 1;
            }
        }
    }
    
    return result;
}
