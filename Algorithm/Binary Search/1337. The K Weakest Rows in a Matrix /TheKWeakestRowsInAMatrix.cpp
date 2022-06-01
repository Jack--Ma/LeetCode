//
//  TheKWeakestRowsInAMatrix.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/30.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "TheKWeakestRowsInAMatrix.hpp"
#include <queue>
#include <map>

/**
 You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.
 
 A row i is weaker than a row j if one of the following is true:
    * The number of soldiers in row i is less than the number of soldiers in row j.
    * Both rows have the same number of soldiers and i < j.
 Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.
 
 Input: mat =
 [[1,1,0,0,0],
  [1,1,1,1,0],
  [1,0,0,0,0],
  [1,1,0,0,0],
  [1,1,1,1,1]],
 k = 3
 Output: [2,0,3]
 Explanation:
 The number of soldiers in each row is:
 - Row 0: 2
 - Row 1: 4
 - Row 2: 1
 - Row 3: 2
 - Row 4: 5
 The rows ordered from weakest to strongest are [2,0,3,1,4].
 */

void testTheKWeakestRowsInAMatrix() {
    vector<vector<int>> mat = {
        {1,1,0,0,0},
        {1,1,1,1,0},
        {0,0,0,0,0},
        {1,1,0,0,0},
        {1,1,1,1,1}
    };
//    mat = {
//        {1,0},
//        {0,0},
//        {1,0},
//    };
    printVector(Solution().kWeakestRows(mat, 3));
}

struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (b.second > a.second) {
            return false;
        } else if (b.second == a.second) {
            return b.first < a.first;
        } else {
            return true;
        }
    }
};

vector<int> Solution::kWeakestRows(vector<vector<int>> &mat, int k) {
    vector<int> result;
    const int m = (int)mat.size();
    const int n = (int)mat[0].size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    
    for (int i = 0; i < m; i++) {
        vector<int> nums = mat[i];
        int left = 0, right = n-1;
        while (left <= right) {
            int p = (left+right) / 2;
            if (nums[p] == 0) {
                right = p-1;
            } else {
                left = p+1;
            }
        }
        // left means the first index of 0
        pq.push(make_pair(i, left));
    }
    
    while (!pq.empty()) {
        result.push_back(pq.top().first);
        if (result.size() == k) {
            break;
        }
        pq.pop();
    }
    
    return result;
}
