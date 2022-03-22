//
//  MinimumRemoveToMakeValidParentheses.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/22.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <stack>
#include "MinimumRemoveToMakeValidParentheses.hpp"

/**
 Given a string s of '(' , ')' and lowercase English characters.
 Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

 Input: s = "lee(t(c)o)de)"
 Output: "lee(t(c)o)de"
 Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
 
 Input: s = "a)b(c)d"
 Output: "ab(c)d"
 
 Input: s = "))(("
 Output: ""
 */

void testMinRemoveToMakeValid() {
    cout << Solution().minRemoveToMakeValid("lee(t(c)o)de)") << endl;
}

// better solution by use only one stack
string _minRemoveToMakeValid_better(string s) {
    stack<int> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            if (st.empty()) {
                s[i] = '$';
            } else {
                st.pop();
            }
        }
    }
    while (!st.empty()) {
        s[st.top()] = '$';
        st.pop();
    }
    // remove all '$' char
    auto _remove = remove(s.begin(), s.end(), '$');
    s.erase(_remove, s.end());
    return s;
}

string Solution::minRemoveToMakeValid(string s) {
    string result = s;
    stack<pair<char, int>> charStack;
    
    for (int i = 0; i < s.length(); i++) {
        char sChar = s[i];
        switch (sChar) {
            case '(': {
                pair<char, int> charIndexPair = make_pair(sChar, i);
                charStack.push(charIndexPair);
            }
                break;
            case ')': {
                if (!charStack.empty() && charStack.top().first == '(') {
                    charStack.pop();
                } else {
                    charStack.push(make_pair(sChar, i));
                }
            }
                break;
            default:
                break;
        }
    }
    
    while (!charStack.empty()) {
        pair<char, int> topPair = charStack.top();
        result.erase(topPair.second, 1);
        charStack.pop();
    }
    
    return result;
}
