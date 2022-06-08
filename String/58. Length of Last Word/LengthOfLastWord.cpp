//
//  LengthOfLastWord.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/6/7.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "LengthOfLastWord.hpp"

/**
 Given a string s consisting of words and spaces, return the length of the last word in the string.
 
 A word is a maximal substring consisting of non-space characters only.
 
 Input: s = "Hello World"
 Output: 5
 Explanation: The last word is "World" with length 5.
 
 Input: s = "   fly me   to   the moon  "
 Output: 4
 Explanation: The last word is "moon" with length 4.
 */

void testLengthOfLastWord() {
    cout << Solution().lengthOfLastWord(" ") << endl;
}

int Solution::lengthOfLastWord(string s) {
    vector<string> words = string_split(s, " ");
    
    const int length = (int)s.length();
    int result = 0;
    bool findWord = false;
    for (int i = length - 1; i >= 0; i--) {
        if (findWord && s[i] == ' ') {
            break;
        }
        if (s[i] != ' ') {
            findWord = true;
        }
        if (findWord && s[i] != ' ') {
            result++;
        }
    }
    
    return result;
}
