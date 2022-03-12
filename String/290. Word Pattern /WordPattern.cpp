//
//  WordPattern.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/12.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "WordPattern.hpp"

/**
 Given a pattern and a string s, find if s follows the same pattern.

 Input: pattern = "abba", s = "dog cat cat dog"
 Output: true
 
 Input: pattern = "abba", s = "dog cat cat fish"
 Output: false
 */

void testWordPattern() {
    cout << Solution().wordPattern("abbaa", "dog cat cat dog") << endl;
}

bool Solution::wordPattern(string pattern, string s) {
    unordered_map<char, string> patternSMap;
    unordered_map<string, char> sPatternMap;
    s.push_back(' ');
    
    string subStr;
    int patternNum = 0;
    for (char sChar : s) {
        if (sChar == ' ') {
            char patternChar = pattern[patternNum];
            // check subStr to pattern
            if (sPatternMap.find(subStr) == sPatternMap.end()) {
                sPatternMap[subStr] = patternChar;
            } else {
                // every subStr correspond a char in pattern
                if (sPatternMap[subStr] != patternChar) {
                    return false;
                }
            }
            // check pattern to subStr
            if (patternSMap.find(patternChar) == patternSMap.end()) {
                patternSMap[patternChar] = subStr;
            } else {
                // every pattern correspond a subStr in s
                if (patternSMap[patternChar] != subStr) {
                    return false;
                }
            }
            patternNum++;
            subStr.clear();
        } else {
            subStr.push_back(sChar);
        }
    }
    
    // maybe pattern'size is bigger then s subStr'size
    return patternNum == pattern.size();
}
