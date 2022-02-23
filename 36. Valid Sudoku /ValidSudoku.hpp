//
//  ValidSudoku.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/22.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef ValidSudoku_hpp
#define ValidSudoku_hpp

#include <stdio.h>

// https://leetcode.com/problems/valid-sudoku/
class Solution {
public:
    std::basic_string<char> extracted(int i, int j, std::basic_string<char> (^rowIndexblock)(int, int));
    
    bool isValidSudoku(vector<vector<char>>& board);
};

void testIsValidSudoku();

#endif /* ValidSudoku_hpp */
