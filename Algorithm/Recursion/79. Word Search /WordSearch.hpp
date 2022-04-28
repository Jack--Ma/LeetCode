//
//  WordSearch.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/28.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef WordSearch_hpp
#define WordSearch_hpp

#include <stdio.h>

// https://leetcode.com/problems/word-search/
class Solution79 {
private:
    vector<vector<char>> board;
    string word;
    void _wordSearch(int i, int j, string leftWord);
    
public:
    bool result;
    bool wordSearch(vector<vector<char>>& board, string word);
};

void testWordSearch();

#endif /* WordSearch_hpp */
