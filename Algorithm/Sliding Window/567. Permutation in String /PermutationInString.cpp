//
//  PermutationInString.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/10.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "PermutationInString.hpp"

/**
 Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
 In other words, return true if one of s1's permutations is the substring of s2.
 
 Input: s1 = "ab", s2 = "eidbaooo"
 Output: true
 Explanation: s2 contains one permutation of s1 ("ba").
 
 Input: s1 = "ab", s2 = "eidboaoo"
 Output: false
 */

void testPermutationInString() {
    cout << Solution().checkInclusion("ab", "eidbaooo") << endl;
}

/// my solution O(n^2) time complexity
/// Time Limit Exceeded
bool _checkInclusion_timeout(string s1, string s2) {
    const int size_s2 = (int)s2.length();
    
    unordered_map<char, int> _s1Map;
    for (char char_s1 : s1) {
        _s1Map[char_s1]++;
    }
    
    for (int i = 0; i < size_s2; i++) {
        char char_s2 = s2[i];
        unordered_map<char, int> s1Map = _s1Map;
        if (s1Map.find(char_s2) != s1Map.end()) {
            // try to find string from i
            for (int j = i; j < size_s2; j++) {
                char char_j = s2[j];
                auto pair = s1Map.find(char_j);
                if (pair != s1Map.end()) {
                    if (pair->second == 1) {
                        s1Map.erase(char_j);
                    } else {
                        s1Map[char_j]--;
                    }
                } else {
                    break;
                }
            }
            if (s1Map.empty()) {
                // contains a permutation
                return true;
            }
        }
    }
    
    return false;
}

bool Solution::checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length()) {
        return false;
    }
    // map: key is a~z, value is letter appear frequency
    vector<int> s1Map(26, 0);
    vector<int> s2Map(26, 0);
    for (int i = 0; i < s1.length(); i++) {
        s1Map[s1[i]-'a']++;
        s2Map[s2[i]-'a']++;
    }
    if (s1Map == s2Map) {
        return true;
    }
    
    // the window begin from 0, and length is s1.length
    // window move backward, reduce begin frequency, increase end frequency
    int begin = 0;
    int end = (int)s1.length();
    while (end < s2.length()) {
        // operate s2 map
        s2Map[s2[begin] - 'a']--;
        s2Map[s2[end] - 'a']++;
        
        if (s1Map == s2Map) {
            return true;
        }
        begin++;
        end++;
    }
    
    return false;
}
    
