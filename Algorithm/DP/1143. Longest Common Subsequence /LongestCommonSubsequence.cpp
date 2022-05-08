//
//  LongestCommonSubsequence.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/7.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "LongestCommonSubsequence.hpp"

/**
 Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

 A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

 For example, "ace" is a subsequence of "abcde".
 A common subsequence of two strings is a subsequence that is common to both strings.
 
 Input: text1 = "abcde", text2 = "ace"
 Output: 3
 Explanation: The longest common subsequence is "ace" and its length is 3.
 
 Input: text1 = "abc", text2 = "def"
 Output: 0
 Explanation: There is no such common subsequence, so the result is 0.
 */

void testLongestCommonSubsequence() {
    /**
     "bsbininm"
     "jmjkbkjkv"
     "bmvcnwrmxcfcxabkxcvgbozmpspsbenazglyxkpibgzq"
     "bmpmlstotylonkvmhqjyxmnqzctonqtobahcrcbibgzgx"
     */
    cout << Solution().longestCommonSubsequence("bmvcnwrmxcfcxabkxcvgbozmpspsbenazglyxkpibgzq", "bmpmlstotylonkvmhqjyxmnqzctonqtobahcrcbibgzgx") << endl;
}

/// Solution by use recursion
/// Time complexity is O(2^n) Time Limit Exceeded
int _longestCommonSubsequence_recursion(string text1, string text2) {
    if (text1.empty() || text2.empty()) {
        return 0;
    }
    int lcs = 0;
    if (text1.front() == text2.front()) {
        // LCS(abcde,ace) = 1 + LCS(bcde,ace)
        lcs++;
        string nextText1 = text1.substr(1);
        string nextText2 = text2.substr(1);
        lcs+=_longestCommonSubsequence_recursion(nextText1, nextText2);
    } else {
        // LCS(bcde,ace) = max(LCS(bcde,ce), LCS(cde,ace))
        string nextText1 = text1.substr(1);
        string nextText2 = text2.substr(1);
        int leftLCS = _longestCommonSubsequence_recursion(nextText1, text2);
        int rightLCS = _longestCommonSubsequence_recursion(text1, nextText2);
        lcs += max(leftLCS, rightLCS);
    }
    
    return lcs;
}

/// Solution by use DP
int _longestCommonSubsequence_DP(string text1, string text2) {
    const int L1 = (int)text1.length();
    const int L2 = (int)text2.length();
    
    vector<vector<int>> DP(L2+1, vector<int>(L1+1, 0));
    /**
     Construct a DP with width=(L1+1), height=(L2+1), the left-top border default is 0
      j a b c d e
    i 0 0 0 0 0 0
    a 0 1 1 1 1 1
    c 0 1 1 2 2 2
    e 0 1 1 2 2 3
     
     Traverse from left-right and top-bottom.
     i mean DP row index, j mean DP column index.
     The formula is:
     DP[i][j] = max(DP[i-1][j], DP[i][j-1]) when s1[j-1] != s2[i-1]
     DP[i][j] = 1+DP[i-1][j-1] when s1[j-1] == s2[i-1]
     */
    for (int i = 1; i <= L2; i++) {
        for (int j = 1; j <= L1; j++) {
            if (text1[j-1] == text2[i-1]) {
                DP[i][j] = 1+DP[i-1][j-1];
            } else {
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
    }
//    printVector(DP);
    
    return DP[L2][L1];
}

int Solution::longestCommonSubsequence(string text1, string text2) {
    return _longestCommonSubsequence_DP(text1, text2);
}
