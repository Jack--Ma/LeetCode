//
//  GenerateParentheses.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/27.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef GenerateParentheses_hpp
#define GenerateParentheses_hpp

#include <stdio.h>

// https://leetcode.com/problems/generate-parentheses/
class Solution {
private:
    int N;
    void _generateParenthesis(string p, int leftSize, int rightSize);
    
public:
    vector<string> result;
    vector<string> generateParenthesis(int n);
};

void testGenerateParentheses();

#endif /* GenerateParentheses_hpp */
