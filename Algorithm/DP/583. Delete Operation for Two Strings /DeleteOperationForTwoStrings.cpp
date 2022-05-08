//
//  DeleteOperationForTwoStrings.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/8.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "DeleteOperationForTwoStrings.hpp"

/**
 Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
 
 In one step, you can delete exactly one character in either string.
 
 Input: word1 = "sea", word2 = "eat"
 Output: 2
 Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
 
 Input: word1 = "leetcode", word2 = "etco"
 Output: 4
 */

void testDeleteOperationForTwoStrings() {
    cout << Solution().minDistance("a", "b") << endl;
}

/// Solution by use DP
int _minDistance_DP(string word1, string word2) {
    const int L1 = (int)word1.length();
    const int L2 = (int)word2.length();
    
    // find word1 and word2 LCS
    vector<vector<int>> DP(L2+1, vector<int>(L1+1, 0));
    for (int i = 1; i <= L2; i++) {
        for (int j = 1; j <= L1; j++) {
            if (word2[i-1] == word1[j-1]) {
                DP[i][j] = DP[i-1][j-1]+1;
            } else {
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
    }
//    printVector(DP);
    
    int lcs = DP[L2][L1];
    return L1+L2-lcs*2;
}
    
int Solution::minDistance(string word1, string word2) {
    return _minDistance_DP(word1, word2);
}
