//
//  ValidParentheses.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/26.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <stack>
#include "ValidParentheses.hpp"

/**
 Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

 Input: s = "()[]{}"
 Output: true
 
 Input: s = "(]"
 Output: false
 
 Input: s = ")("
 Output: false
 */

// my solution
bool Solution::isValid(string s) {
    stack<char> charStack;
    
    for (char c : s) {
        char topChar = charStack.size() > 1 ? charStack.top() : ' ';
        switch (c) {
            case '(':case '[':case '{': {
                charStack.push(c);
            }
                break;
            case ')': {
                if (topChar == '(') {
                    charStack.pop();
                } else {
                    return false;
                }
            }
                break;
            case ']': {
                if (topChar == '[') {
                    charStack.pop();
                } else {
                    return false;
                }
            }
                break;
            case '}': {
                if (topChar == '{') {
                    charStack.pop();
                } else {
                    return false;
                }
            }
                break;
            default:
                break;
        }
    }
    
    return charStack.size() == 0;
}

void testIsValid() {
    cout << Solution().isValid("([{[[]]}])") << endl;
}
