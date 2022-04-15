//
//  LetterCasePermutation.cpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/4/14.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "LetterCasePermutation.hpp"

/**
 Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
 Return a list of all possible strings we could create. Return the output in any order.
 
 Input: s = "a1b2"
 Output: ["a1b2","a1B2","A1b2","A1B2"]
 
 Input: s = "3z4"
 Output: ["3z4","3Z4"]
 */

void testLetterCasePermutation() {
    printVector(Solution().letterCasePermutation("3z4"));
}

void _letterCasePermutation_recursion(vector<string>& result, string s, string newStr) {
    if (newStr.length() == s.length()) {
        result.push_back(newStr);
        return;
    }
    
    int index = (int)newStr.length();
    if (index < s.length()) {
        char sChar = s[index];
        if (sChar >= '0' && sChar <= '9') {
            _letterCasePermutation_recursion(result, s, newStr+sChar);
        } else if (sChar >= 'a' && sChar <= 'z') {
            char upperSChar = sChar + ('A'-'a');
            _letterCasePermutation_recursion(result, s, newStr+sChar);
            _letterCasePermutation_recursion(result, s, newStr+upperSChar);
        } else if (sChar >= 'A' && sChar <= 'Z') {
            char lowerSChar = sChar + ('a'-'A');
            _letterCasePermutation_recursion(result, s, newStr+sChar);
            _letterCasePermutation_recursion(result, s, newStr+lowerSChar);
        }
    }
}

vector<string> Solution::letterCasePermutation(string s) {
    vector<string> result;
    _letterCasePermutation_recursion(result, s, "");
    return result;
}
