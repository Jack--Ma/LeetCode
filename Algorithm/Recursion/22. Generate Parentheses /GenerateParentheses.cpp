//
//  GenerateParentheses.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/27.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "GenerateParentheses.hpp"

/**
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 
 Input: n = 3
 Output: ["((()))","(()())","(())()","()(())","()()()"]
 
 Input: n = 1
 Output: ["()"]
 */

void testGenerateParentheses() {
    printVector(Solution().generateParenthesis(3));
}

void Solution::_generateParenthesis(string p, int leftSize, int rightSize) {
    // find parenthesis
    if (p.length() == N*2) {
        result.push_back(p);
        return;
    }

    // remaind '(' and could push '('
    if (leftSize > 0) {
        p.push_back('(');
        _generateParenthesis(p, leftSize-1, rightSize);
        p.pop_back();
    }
    // exist unpaired '(' is p, and could push ')'
    if (rightSize > leftSize) {
        p.push_back(')');
        _generateParenthesis(p, leftSize, rightSize-1);
    }
}

vector<string> Solution::generateParenthesis(int n) {
    N = n;
    _generateParenthesis("", n, n);
    return result;
}
