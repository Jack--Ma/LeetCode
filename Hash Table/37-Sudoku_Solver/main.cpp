//
//  main.cpp
//  37-Sudoku_Solver
//
//  Created by JackMa on 16/8/4.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool sudokuCharsVaild(vector<vector<char>> &board, int row, int col) {
    if (!isdigit(board[row][col])) {
        return false;
    }
    
    //检查行和列
    char value = board[row][col];
    for (int i = 0; i < 9; i++) {
        if (value == board[row][i] && col != i) {
            return false;
        }
        if (value == board[i][col] && row != i) {
            return false;
        }
    }
    
    //检查3*3区域
    int row_begin = row / 3 * 3;
    int col_begin = col / 3 * 3;
    
    for (int i = row_begin; i < row_begin+3; i++) {
        for (int j = col_begin; j < col_begin+3; j++) {
            if (value == board[i][j] && i != row && j != col) {
                return false;
            }
        }
    }
    
    return true;
}

bool checkBoardValid(vector<vector<char>> &board, int row, int col) {
    //最后一个位置
    if (row == 9 && col == 0) {
        return true;
    }
    
    int next_row = col == 8 ? row+1 : row;
    int next_col = col == 8 ? 0 : col+1;
    //是数字，则检查是否符合
    if (isdigit(board[row][col])) {
        //不符合，返回false
        if (!sudokuCharsVaild(board, row, col)) {
            return false;
        }
        //迭代下一个位置
        return checkBoardValid(board, next_row, next_col);
    }
    //是'.'则，循环检查1-9
    for (int i = 1; i <= 9; i++) {
        board[row][col] = '0' + i;
        //只有当前位置符合且下一个位置符合才满足
        if (sudokuCharsVaild(board, row, col) && checkBoardValid(board, next_row, next_col)) {
            return true;
        }
    }
    
    board[row][col] = '.';
    return false;
}

void solveSudoku(vector<vector<char>> &board) {
    checkBoardValid(board, 0, 0);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //["..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."]
    vector<vector<char>> board = {
        {'.','.','9','7','4','8','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'.','2','.','1','.','9','.','.','.'},
        {'.','.','7','.','.','.','2','4','.'},
        {'.','6','4','.','1','.','5','9','.'},
        {'.','9','8','.','.','.','3','.','.'},
        {'.','.','.','8','.','3','.','2','.'},
        {'.','.','.','.','.','.','.','.','6'},
        {'.','.','.','2','7','5','9','.','.'}};
    
    solveSudoku(board);
    
    return 0;
}
