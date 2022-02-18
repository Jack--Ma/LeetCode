//
//  IntersectionOfTwoArraysII.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/17.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <unordered_map>
#include "IntersectionOfTwoArraysII.hpp"

/**
 Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 Output: [4,9]
 Explanation: [9,4] is also accepted.
 */

// my solution
vector<int> Solution::intersect(vector<int> &nums1, vector<int> &nums2) {
    vector<int> result;
    unordered_map<int, int> map;
    for (int i : nums1) {
        // mark the number appeared
        if (map.find(i) == map.end()) {
            map[i] = 1;
        } else {
            int num = map[i];
            map[i] = ++num;
        }
    }
    for (int j : nums2) {
        // find same number and decrease mark num
        if (map.find(j) != map.end()) {
            int num = map[j];
            map[j] = --num;
            // erase mark when num equal zero
            if (num == 0) {
                map.erase(j);
            }
            result.push_back(j);
        }
    }
    return result;
}

// other solution
vector<int> otherIntersect(vector<int> &nums1, vector<int> &nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int p1 = 0, p2 = 0;
    vector<int> result;
    
    while (p1 < nums1.size() && p2 < nums2.size()) {
        if (nums1[p1] == nums2[p2]) {
            result.push_back(nums1[p1]);
            p1++;p2++;
        } else if (nums1[p1] < nums2[p2]) {
            p1++;
        } else {
            p2++;
        }
    }
    return result;
}

void testIntersect() {
    vector<int> nums1 = {4,9,5,8};
    vector<int> nums2 = {9,4,9,8,4};
    Solution().intersect(nums1, nums2);
}
