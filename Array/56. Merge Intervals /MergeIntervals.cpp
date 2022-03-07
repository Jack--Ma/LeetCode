//
//  MergeIntervals.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/7.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "MergeIntervals.hpp"

/**
 Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
 
 Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 Output: [[1,6],[8,10],[15,18]]
 Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 
 Input: intervals = [[1,4],[4,5]]
 Output: [[1,5]]
 Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 */

vector<vector<int>> Solution::mergeIntervals(vector<vector<int>>& intervals) {
//    sort(intervals.begin(), intervals.end());
    sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
        return a[0] < b[0];
    });
    
    vector<vector<int>> result;
    int start = intervals[0][0], end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
        vector<int> interval = intervals[i];
        // two situation
        if (interval[0] > end) {
            // 1. interval[0] bigger than start
            result.push_back({start,end});
            start = interval[0];
            end = interval[1];
        } else {
            // 2. interval overlap with [start,end]
            end = max(interval[1], end);
        }
    }
    result.push_back({start,end});
    
    return intervals;
}

void testMergeIntervals() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    Solution().mergeIntervals(intervals);
}
