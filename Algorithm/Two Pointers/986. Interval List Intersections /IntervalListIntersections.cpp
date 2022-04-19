//
//  IntervalListIntersections.cpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/4/19.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "IntervalListIntersections.hpp"

/**
 You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.
 
 Return the intersection of these two interval lists.
 
 Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
 Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 */

void testIntervalListIntersections() {
    vector<vector<int>> firstList = {{3,10}};
    vector<vector<int>> secondList = {{5,10}};
    printVector(Solution().intervalIntersection(firstList, secondList));
}

vector<vector<int>> Solution::intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
    vector<vector<int>> result;
    
    const int size1 = (int)firstList.size();
    const int size2 = (int)secondList.size();
    
    int first = 0, second = 0;
    while (first < size1 && second < size2) {
        vector<int> firstPair = firstList[first];
        vector<int> secondPair = secondList[second];
        
        // 1st. determine which pair tail is bigger
        // we need jump the smaller pair in next loop
        if (firstPair[1] < secondPair[1]) {
            first++;
            // 2rd. judge which situation exist interval certainly
            if (secondPair[0] <= firstPair[1]) {
                // such as: [0,2] and [1,5]
                result.push_back({max(firstPair[0], secondPair[0]), min(firstPair[1], secondPair[1])});
            }
        } else {
            second++;
            if (firstPair[0] <= secondPair[1]) {
                // such as: [1,5] and [5,10]
                result.push_back({max(firstPair[0], secondPair[0]), min(firstPair[1], secondPair[1])});
            }
        }
    }
    
    return result;
}
