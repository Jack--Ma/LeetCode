//
//  ImplementStrStr().cpp
//  LeetCode-main
//
//  Created by jackma on 2022/6/3.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "ImplementStrStr().hpp"

/**
 Implement strStr().
 
 Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 
 Input: haystack = "hello", needle = "ll"
 Output: 2
 
 Input: haystack = "aaaaa", needle = "bba"
 Output: -1
 */

void testImplementStrStr() {
    cout << Solution().strStr("hello", "lr") << endl;
}

int Solution::strStr(string haystack, string needle) {
    const int L1 = (int)haystack.length();
    const int L2 = (int)needle.length();
    
    int p = 0;
    while (p <= (L1-L2)) {
        string subStr = haystack.substr(p, L2);
        if (subStr == needle) {
            return p;
        }
        p++;
    }
    return -1;
}
