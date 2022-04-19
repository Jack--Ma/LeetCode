//
//  BackspaceStringCompare.cpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/4/19.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <stack>
#include "BackspaceStringCompare.hpp"

/**
 Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
 
 Note that after backspacing an empty text, the text will continue empty.
 
 Input: s = "ab#c", t = "ad#c"
 Output: true
 Explanation: Both s and t become "ac".
 
 Input: s = "ab##", t = "c#d#"
 Output: true
 Explanation: Both s and t become "".
 
 Input: s = "a#c", t = "b"
 Output: false
 Explanation: s becomes "c" while t becomes "b".
 */

void testBackspaceStringCompare() {
    cout << Solution().backspaceCompare("y#fo##f", "y#f#o##f") << endl;
}

bool Solution::backspaceCompare(string s, string t) {
    stack<char> stack_s, stack_t;
    int p = 0, q = 0;
    while (p < s.length()) {
        char sChar = s[p];
        if (sChar == '#') {
            if (!stack_s.empty()) {
                stack_s.pop();
            }
        } else {
            stack_s.push(sChar);
        }
        p++;
    }
    while (q < t.length()) {
        char tChar = t[q];
        if (tChar == '#') {
            if (!stack_t.empty()) {
                stack_t.pop();
            }
        } else {
            stack_t.push(tChar);
        }
        q++;
    }
    
    if (stack_s.size() != stack_t.size()) {
        return false;
    }
    while (!stack_s.empty()) {
        if (stack_s.top() != stack_t.top()) {
            return false;
        }
        stack_s.pop();
        stack_t.pop();
    }
    return true;
}
