//
//  FindAllAnagramsInAString.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/11.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "FindAllAnagramsInAString.hpp"

/**
 Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
 
 An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 
 Input: s = "cbaebabacd", p = "abc"
 Output: [0,6]
 Explanation:
 The substring with start index = 0 is "cba", which is an anagram of "abc".
 The substring with start index = 6 is "bac", which is an anagram of "abc".
 
 Input: s = "abab", p = "ab"
 Output: [0,1,2]
 Explanation:
 The substring with start index = 0 is "ab", which is an anagram of "ab".
 The substring with start index = 1 is "ba", which is an anagram of "ab".
 The substring with start index = 2 is "ab", which is an anagram of "ab".
 */

void testFindAllAnagramsInAString() {
    printVector(Solution().findAnagrams("aaaaaaaaaa", "aaaaaaaaaaaaa"));
}

vector<int> Solution::findAnagrams(string s, string p) {
    vector<int> result;
    if (s.length() < p.length()) {
        return result;
    }
    // use map to represent the frequency of letters
    vector<int> pMap(26, 0);
    vector<int> sMap(26, 0);
    for (int i = 0; i < p.length(); i++) {
        pMap[p[i] - 'a']++;
        sMap[s[i] - 'a']++;
    }
    if (pMap == sMap) {
        result.push_back(0);
    }
    
    // sliding window begin 0, and length is p.length
    int begin = 0;
    int end = (int)p.length();
    while (end < s.length()) {
        // move window backward
        sMap[s[begin] - 'a']--;
        sMap[s[end] - 'a']++;
        if (pMap == sMap) {
            result.push_back(begin+1);
        }
        
        begin++;
        end++;
    }
    
    return result;
}
