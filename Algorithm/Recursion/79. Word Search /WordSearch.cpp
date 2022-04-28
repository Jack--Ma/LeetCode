//
//  WordSearch.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/28.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "WordSearch.hpp"

/**
 Given an m x n grid of characters board and a string word, return true if word exists in the grid.

 The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
 
 Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
 Output: true
 
 Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
 Output: true
 */

void testWordSearch() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    cout << Solution79().wordSearch(board, "SEET") << endl;
}

void Solution79::_wordSearch(int i, int j, string leftWord) {
    char backChar = leftWord.front();
    // find the correct char
    if (backChar == board[i][j]) {
        string nextWord = string(leftWord.begin()+1, leftWord.end());
        // return when find full word
        if (nextWord.empty()) {
            result = true;
            return;
        }
        board[i][j] = '#';
        if (i > 0) {
            _wordSearch(i-1, j, nextWord);
        }
        if (i < board.size()-1) {
            _wordSearch(i+1, j, nextWord);
        }
        if (j > 0) {
            _wordSearch(i, j-1, nextWord);
        }
        if (j < board[0].size()-1) {
            _wordSearch(i, j+1, nextWord);
        }
        // revert original scene
        board[i][j] = backChar;
    }
}

bool Solution79::wordSearch(vector<vector<char>> &board, string word) {
    this->board = board;
    this->word = word;
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            _wordSearch(i, j, word);
        }
    }
    
    return result;
}
