//
//  ReverseString.cpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/4/7.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "ReverseString.hpp"

/**
 Write a function that reverses a string. The input string is given as an array of characters s.

 You must do this by modifying the input array in-place with O(1) extra memory.

 Input: s = ["h","e","l","l","o"]
 Output: ["o","l","l","e","h"]
 
 Input: s = ["H","a","n","n","a","h"]
 Output: ["h","a","n","n","a","H"]
 */

void testReverseString() {
    vector<char> s = {'h','e','l','l','o'};
    Solution().reverseString(s);
    printVector(s);
}

void Solution::reverseString(vector<char> &s) {
    int p = 0, q = (int)s.size() - 1;
    while (p < q) {
        swap(s[p], s[q]);
        p++;
        q--;
    }
}
