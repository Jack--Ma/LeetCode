//
//  LongestSubstringWithoutRepeatingCharacters.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/10.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "LongestSubstringWithoutRepeatingCharacters.hpp"

/**
 Given a string s, find the length of the longest substring without repeating characters.
 
 Input: s = "abcabcbb"
 Output: 3
 Explanation: The answer is "abc", with the length of 3.
 
 Input: s = "pwwkew"
 Output: 3
 Explanation: The answer is "wke", with the length of 3.
 Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

void testLengthOfLongestSubstring() {
    cout << Solution().lengthOfLongestSubstring("au") << endl;
}

int _lengthOfLongestSubstring_map(string s) {
    int maxLength = 0;
    const int ASCII_MAX = 255;
    int last[ASCII_MAX];
    fill(last, last+ASCII_MAX, -1);
    
    int start = 0;
    for (int i = 0; i < s.length(); i++) {
        char sChar = s[i];
        int appearedIndex = last[sChar];
        if (appearedIndex >= start) {
            // sChar has already appeared
            maxLength = max(maxLength, i - start);
            start = appearedIndex + 1;
        }
        last[sChar] = i;
    }
    // in case last-array contains all value are -1
    maxLength = max(maxLength, (int)s.length() - start);
    return maxLength;
}

int Solution::lengthOfLongestSubstring(string s) {
    int maxLength = 0;
    string subStr;
    /**
     eg.
     s="abcabcbb"
     subStr will be: abc-> bca-> cab-> abc-> cb-> b
     */
    for (char sChar : s) {
        size_t find = subStr.find(sChar);
        if (find != string::npos) {
            // find char, and split from find+1 index to end
            subStr = subStr.substr(find+1);
        }
        subStr.push_back(sChar);
        maxLength = max(maxLength, (int)subStr.length());
    }
    
    return maxLength;
}
