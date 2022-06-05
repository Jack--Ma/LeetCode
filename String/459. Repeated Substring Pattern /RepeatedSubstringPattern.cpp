//
//  RepeatedSubstringPattern.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/6/4.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "RepeatedSubstringPattern.hpp"

/**
 Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
 
 Input: s = "abab"
 Output: true
 Explanation: It is the substring "ab" twice.
 
 Input: s = "aba"
 Output: false
 */

void testRepeatedSubstringPattern() {
    cout << Solution().repeatedSubstringPattern("aba") << endl;
}

bool Solution::repeatedSubstringPattern(string s) {
    /**
     abab + abab = abababab
     remove head and tail, = bababa
     bababa contains string abab
     */
    string ts = s + s;
    string subTs = ts.substr(1, ts.length()-2);
    return subTs.find(s) != string::npos;
}
