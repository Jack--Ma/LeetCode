//
//  LongestPalindrome.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/12.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "LongestPalindrome.hpp"

/**
 Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

 Input: s = "abccccdd"
 Output: 7
 Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
 */

void testLongestPalindrome() {
    cout << Solution().longestPalindrome("abccccdd") << endl;
}

int Solution::longestPalindrome(string s) {
    int result = 0;
    unordered_map<char, int> sMap;
    
    for (char sChar : s) {
        sMap[sChar]++;
    }
    
    bool odd = false;
    for (auto sPair : sMap) {
        if (sPair.second % 2 == 0) {
            result += sPair.second;
        } else {
            result += sPair.second - 1;
            odd = true;
        }
    }
    if (odd) {
        result++;
    }
    return result;
}
