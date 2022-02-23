//
//  ValidSudoku.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/22.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include "ValidSudoku.hpp"

/**
 Input: board =
 [["5","3",".",".","7",".",".",".","."]
 ,["6",".",".","1","9","5",".",".","."]
 ,[".","9","8",".",".",".",".","6","."]
 ,["8",".",".",".","6",".",".",".","3"]
 ,["4",".",".","8",".","3",".",".","1"]
 ,["7",".",".",".","2",".",".",".","6"]
 ,[".","6",".",".",".",".","2","8","."]
 ,[".",".",".","4","1","9",".",".","5"]
 ,[".",".",".",".","8",".",".","7","9"]]
 Output: true
 */

// cube index is "cube+i/3+j/3"
static inline string cubeIndexBlock(int i, int j) {
    return "row"+to_string(i/3)+to_string(j/3);
}

// row index is "row+i"
static inline auto rowIndexblock(int i, int j) {
    return "row"+to_string(i);
}

// colum index is "col+j"
static inline string colIndexLambda(int i, int j) {
    ostringstream oss;
    oss << "col" << j;
    return oss.str();
}

// my solution
bool Solution::isValidSudoku(vector<vector<char>> &board) {
    unordered_map<string, unordered_set<char>> sudokuMap;
    
    for (int i = 0; i < board.size(); i++) {
        vector<char> boardRow = board[i];
        for (int j = 0; j < boardRow.size(); j++) {
            // every number could be in row/column/cube
            char charNum = boardRow[j];
            if (charNum != '.') {
                string rowIndex = rowIndexblock(i, j);
                // check row
                if (sudokuMap.find(rowIndex) == sudokuMap.end()) {
                    unordered_set<char> rowChars = {charNum};
                    sudokuMap[rowIndex] = rowChars;
                } else {
                    unordered_set<char> rowChars = sudokuMap[rowIndex];
                    // find same char num in row chars
                    if (rowChars.find(charNum) == rowChars.end()) {
                        rowChars.insert(charNum);
                        sudokuMap[rowIndex] = rowChars;
                    } else {
                        return false;
                    }
                }
                
                // check column
                string colIndex = colIndexLambda(i, j);
                if (sudokuMap.find(colIndex) == sudokuMap.end()) {
                    unordered_set<char> colChars = {charNum};
                    sudokuMap[colIndex] = colChars;
                } else {
                    unordered_set<char> colChars = sudokuMap.at(colIndex);
                    if (colChars.find(charNum) == colChars.end()) {
                        colChars.insert(charNum);
                        sudokuMap[colIndex] = colChars;
                    } else {
                        return false;
                    }
                }
                
                // check cube
                string cubeIndex = cubeIndexBlock(i, j);
                if (sudokuMap.find(cubeIndex) == sudokuMap.end()) {
                    unordered_set<char> cubeChars = {charNum};
                    sudokuMap[cubeIndex] = cubeChars;
                } else {
                    unordered_set<char> cubeChars = sudokuMap.find(cubeIndex)->second;
                    if (cubeChars.find(charNum) == cubeChars.end()) {
                        cubeChars.insert(charNum);
                        sudokuMap[cubeIndex] = cubeChars;
                    } else {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

// other answer
bool otherIsValidSudoku(vector<vector<char>> &board) {
    // check row
    for (int i = 0; i < 9; i++) {
        // indicate 1~9 number char appear or not
        vector<bool> row_chars(9, false);
        for (int j = 0; j < 9; j++) {
            char numChar = board[i][j];
            int k = numChar - '0';
            if (isdigit(numChar)) {
                // row_chars[k-1] is true mean the char did appear
                if (row_chars[k-1] || k == 0) {
                    return false;
                }
                row_chars[k-1] = true;
            }
        }
    }
    
    // check col
    for (int i = 0; i < 9; i++) {
        vector<bool> col_chars(9, false);
        for (int j = 0; j < 9; j++) {
            char numChar = board[i][j];
            int k = numChar - '0';
            if (isdigit(numChar)) {
                if (col_chars[k-1] || k == 0) {
                    return false;
                }
                col_chars[k-1] = true;
            }
        }
    }
    
    // check 3*3 area
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int row_begin = i * 3;
            int col_begin = j * 3;
            vector<bool> area_chars(9, false);
            
            for (int m = row_begin; m < row_begin+3; m++) {
                for (int n = col_begin; n < col_begin+3; n++) {
                    char numChar = board[i][j];
                    int k = numChar - '0';
                    if (isdigit(numChar)) {
                        if (area_chars[k-1] || k == 0) {
                            return false;
                        }
                        
                        area_chars[k-1] = true;
                    }
                }
            }
        }
    }
    return true;
}

void testIsValidSudoku() {
    vector<vector<char>> sudoku = {
         {'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}
    };
    otherIsValidSudoku(sudoku);
}
