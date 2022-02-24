//
//  FirstUniqueCharacterInAString.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/23.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <unordered_map>
#include "FirstUniqueCharacterInAString.hpp"

/**
 Input: s = "leetcode"
 Output: 0
 
 Input: s = "loveleetcode"
 Output: 2
 
 Input: s = "aabb"
 Output: -1
 */

// my solution
int Solution::firstUniqChar(string s) {
    // key: mean a~z,
    // value: mean char index in s, will be -1 when char repeat appear
    unordered_map<char, int> charMap;
    for (int i = 0; i < (int)s.length(); i++) {
        char s_char = s.at(i);
        if (charMap.find(s_char) == charMap.end()) {
            // not find char, set index
            charMap[s_char] = i;
        } else {
            // find char, set -1
            charMap[s_char] = -1;
        }
    }
    
    // find charMap each char smallest index
    int result = (int)s.length();
    for (auto charPair : charMap) {
        if (charPair.second != -1) {
            result = min(result, charPair.second);
        }
    }
    
    return result == s.length() ? -1 : result;
}

// other solution
int otherFirstUniqChar(string s) {
    // mark a~z index in s
    int a[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        // s[i]-'a' mean a~z letter index in s
        a[s[i]-'a']++;
    }
    for (int i = 0; i < s.size(); i++) {
        // appear once
        if (a[s[i]-'a'] == 1)
            return i;
    }
    return -1;
}

void testFirstUniqChar() {
    cout << Solution().firstUniqChar("loveleetcode") << endl;
}
