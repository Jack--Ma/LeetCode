//
//  PartitionLabels.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/12.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "PartitionLabels.hpp"

/**
 You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

 Input: s = "ababcbaca defegde hijhklij"
 Output: [9,7,8]
 Explanation:
 The partition is "ababcbaca", "defegde", "hijhklij".
 This is a partition so that each letter appears in at most one part.
 A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
 
 Input: s = "eccbbbbdec"
 Output: [10]
 */
void testPartitionLabels() {
    printVector(Solution().partitionLabels("ababcbacadefegdehijhklij"));
}

vector<int> Solution::partitionLabels(string s) {
    vector<int> result;
    
    vector<int> charIndex(26, 0);
    // find every char the last index in s
    for (int i = 0; i < s.size(); i++) {
        charIndex[s[i] - 'a'] = i;
    }
    
    int maxIndex = -1, lastIndex = 0;
    for (int i = 0; i < s.size(); i++) {
        int charNum = s[i] - 'a';
        // find maxIndex in partition of s
        maxIndex = max(maxIndex,  charIndex[charNum]);
        // when find, mean before s[i] exist a partition
        if (i == maxIndex) {
            result.push_back(maxIndex - lastIndex + 1);
            lastIndex = i + 1;
        }
    }
    
    return result;
}
