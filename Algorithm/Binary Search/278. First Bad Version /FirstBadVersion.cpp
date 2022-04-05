//
//  FirstBadVersion.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/5.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "FirstBadVersion.hpp"

/**
 You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
 
 Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
 
 You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
 
 Input: n = 5, bad = 4
 Output: 4
 Explanation:
 call isBadVersion(3) -> false
 call isBadVersion(5) -> true
 call isBadVersion(4) -> true
 Then 4 is the first bad version.
 */

void testFirstBadVersion() {
    cout << Solution().firstBadVersion(5) << endl;
}

bool isBadVersion(uint64_t version) {
    if (version >= 1) {
        return true;
    }
    return false;
}

int Solution::firstBadVersion(int n) {
    uint64_t first = INT_MAX;
    uint64_t start = 1, end = n;
    
    while (start <= end) {
        uint64_t i = (start + end) / 2;
        if (isBadVersion(i)) {
            end = i - 1;
            first = min(first, i);
        } else {
            start = i + 1;
        }
    }
    
    return (int)first;
}
