//
//  Non-overlappingIntervals.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/9.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "Non-overlappingIntervals.hpp"

/**
 Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
 
 Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
 Output: 1
 Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
 
 Input: intervals = [[1,2],[1,2],[1,2]]
 Output: 2
 Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
 */

int Solution::eraseOverlapIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
        return (a[0] == b[0]) ? (a[1] > b[1]) : (a[0] < b[0]);
    });
    
    int result = 0;
    int start = -INT_MAX, end = -INT_MAX;
    for (auto interval : intervals) {
        // three situation
        if (interval[0] >= end) {
            // next interval‘begin is bigger than end
            // have not overlap
            start = interval[0];
            end = interval[1];
        } else if (interval[1] <= end) {
            // next interval'end is smaller than end
            result++;
            // choose the minimum interval
            start = interval[0];
            end = interval[1];
        } else {
            // have overlap between interval with [start, end]
            // such as: [1, 4] [2, 5], push the back interval
            result++;
        }
    }
    
    return (int)result;
}

void testEraseOverlapIntervals() {
    // {{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}}
    vector<vector<int>> intervals = {{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}};
    cout << Solution().eraseOverlapIntervals(intervals) << endl;
}
