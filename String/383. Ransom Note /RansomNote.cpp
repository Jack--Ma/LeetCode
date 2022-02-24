//
//  RansomNote.cpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/2/24.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "RansomNote.hpp"

/**
 Input: ransomNote = "a", magazine = "b"
 Output: false
 
 Input: ransomNote = "aa", magazine = "ab"
 Output: false
 
 Input: ransomNote = "aa", magazine = "aab"
 Output: true
 */

// my solution
bool Solution::canConstruct(string ransomNote, string magazine) {
    int ransomNoteMap[26] = {0}, magazineMap[26] = {0};
    for (int i = 0; i < ransomNote.size(); i++) {
        int charIndex = ransomNote[i] - 'a';
        ransomNoteMap[charIndex]++;
    }
    for (int i = 0; i < magazine.size(); i++) {
        int charIndex = magazine[i] - 'a';
        magazineMap[charIndex]++;
    }
    
    for (int i = 0; i < 26; i++) {
        int ransomNoteCharNum = ransomNoteMap[i];
        int magazineCharNum = magazineMap[i];
        if (ransomNoteCharNum > magazineCharNum) {
            return false;
        }
    }
    
    return true;
}

void testCanConstruct() {
    cout << Solution().canConstruct("aa", "ab") << endl;
}
