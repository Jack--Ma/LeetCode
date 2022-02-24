//
//  ValidAnagram.cpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/2/24.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "ValidAnagram.hpp"

/**
 An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 
 Input: s = "anagram", t = "nagaram"
 Output: true
 
 Input: s = "rat", t = "car"
 Output: false
 */

// my solution
bool Solution::isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }
    
    // 1st make string map, key is a~z, value is letter count
    int sMap[26] = {0}, tMap[26] = {0};
    for (int i = 0; i < s.length(); i++) {
        int charIndex = s.at(i) - 'a';
        sMap[charIndex]++;
    }
    for (int j = 0; j < t.length(); j++) {
        int charIndex = t[j] - 'a';
        tMap[charIndex]++;
    }
    
    // 2rd compare two string letter count
    for (int i = 0; i < 26; i++) {
        if (sMap[i] != tMap[i]) {
            return false;
        }
    }
    
    return true;
}

// other solution
bool otherIsAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }
    
    // only use one array
    int letters[26] = {0};
    for (int i = 0; i < s.length(); i++) {
        letters[s[i] - 'a']++;
        letters[t[i] - 'a']--;
    }
    
    // cnt equal 0 mean the char appear same count in 2 string
    for (auto cnt: letters) {
        if (cnt != 0) {
            return false;
        }
    }
  
    return true;
}

void testIsAnagram() {
    cout << Solution().isAnagram("anagram", "nagaram") << endl;
}
