//
//  DecodeWays.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/4.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "DecodeWays.hpp"

/**
 A message containing letters from A-Z can be encoded into numbers using the following mapping:
 'A' -> "1"
 'B' -> "2"
 ...
 'Z' -> "26"
 
 To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:
 "AAJF" with the grouping (1 1 10 6)
 "KJF" with the grouping (11 10 6)
 
 Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".
 Given a string s containing only digits, return the number of ways to decode it.
 The test cases are generated so that the answer fits in a 32-bit integer.
 
 Input: s = "12"
 Output: 2
 Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
 
 Input: s = "226"
 Output: 3
 Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 */

void testDecodeWays() {
    cout << Solution().decodeWays("0") << endl;
}

/// Solution bu use recursion
/// Time complexity is O(2^n), Time Limit Exceeded
int _decodeWays_recursion(string s, int index) {
    const int N = (int)s.length();
    if (index == N) {
        return 1;
    }
    if (s[index] == '0') {
        return 0;
    }
    int result = 0;
    // DFS traverse s
    result += _decodeWays_recursion(s, index+1);
    // A two-letter word is valid or not
    if (index < N-1 && (s[index]=='1' || (s[index]=='2' && s[index+1]<'7'))) {
        result += _decodeWays_recursion(s, index+2);
    }
    return result;
}

// solution by use DP
int _decodeWays_DP(string s) {
    const int N = (int)s.length();
    /**
     DP array represents the appear times in each index
     such as 2267 from tail to head:
     7: DP[3] = 1
     6: DP[2] = 1 (because 6-7 is valid, 67 is invalid)
     2: DP[1] = 1+1 (because 2-6-7 is valid, 26-7 is valid)
     2: DP[0] = 2+1 (3 is DP[1]+1, 2 is DP[2]+1)
     
     So the formula is: DP[n] = DP[n+1] + DP[n+2]
     */
    // default from every index decode ways is 1, eg. 8888
    vector<int> DP(N+1, 1);
    for (int i = N-1; i >= 0; i--) {
        int num = s[i] - '0';
        if (num == 0) {
            DP[i] = 0;
            continue;
        }
        // [i,i] must be a valid word
        DP[i] = DP[i+1];
        int nextNum = s[i+1] - '0';
        if (i+1 < N && (num == 1 || (num == 2 && nextNum < 7))) {
            // [i,i+1] is a valid word
            DP[i] += DP[i+2];
        }
    }
    
    return DP[0];
}

int Solution::decodeWays(string s) {
    return _decodeWays_DP(s);
}
