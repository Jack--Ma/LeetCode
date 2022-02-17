//
//  MergeSortedArray.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/17.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef MergeSortedArray_hpp
#define MergeSortedArray_hpp

#include <stdio.h>

// https://leetcode.com/problems/merge-sorted-array/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
};

void testMerge();

#endif /* MergeSortedArray_hpp */
