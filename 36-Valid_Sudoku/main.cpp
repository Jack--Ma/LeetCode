//
//  main.cpp
//  36-Valid_Sudoku
//
//  Created by JackMa on 16/8/4.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//Better answer
bool bestIsValidSudoku(vector<vector<char>> &board) {
    //check row
    for (int i = 0; i < 9; i++) {
        vector<bool> row_chars(9, false);
        for (int j = 0; j < 9; j++) {
            int k = board[i][j] - '0';
            if (isdigit(board[i][j])) {
                if (row_chars[k-1] || k == 0) {
                    return false;
                }
                row_chars[k-1] = true;
            }
        }
    }
    
    //check col
    for (int i = 0; i < 9; i++) {
        vector<bool> col_chars(9, false);
        for (int j = 0; j < 9; j++) {
            int k = board[j][i] - '0';
            if (isdigit(board[j][i])) {
                if (col_chars[k-1] || k == 0) {
                    return false;
                }
                col_chars[k-1] = true;
            }
        }
    }
    
    //check 3*3 area
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int row_begin = i * 3;
            int col_begin = j * 3;
            vector<bool> area_chars(9, false);
            
            for (int m = row_begin; m < row_begin+3; m++) {
                for (int n = col_begin; n < col_begin+3; n++) {
                    int k = board[m][n] - '0';
                    
                    if (isdigit(board[m][n])) {
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

//My answer
bool checkValid(vector<char> &chars) {
    unordered_set<char> set_chars(chars.begin(), chars.end());
    if (chars.size() != set_chars.size()) {
        return false;
    }
    return true;
}

bool isValidSudoku(vector<vector<char>> &board) {
    vector<vector<char>> area_chars(9);
    for (int i = 0; i < 9; i++) {
        vector<char> col_chars;//行
        vector<char> row_chars;//列

        //设置区域
        for (int j = 0; j < 9; j++) {
            //不符合题意
            if (!(board[i][j] == '.' || (board[i][j] <= '9' && board[i][j] >= '1'))) {
                return false;
            }
            
            if (board[i][j] <= '9' && board[i][j] >= '1') {
                col_chars.push_back(board[i][j]);//行
                
                int k = i / 3 * 3 + j / 3;//找到这个i,j对应的块
                area_chars[k].push_back(board[i][j]);//块
            }
            
            if (board[j][i] <= '9' && board[j][i] >= '1') {
                row_chars.push_back(board[j][i]);//列
            }
        }
        //检测行和块
        if (!checkValid(col_chars) || !checkValid(row_chars)) {
            return false;
        }
    }
    //检测列
    for (int i = 0; i < area_chars.size(); i++) {
        if (!checkValid(area_chars[i])) {
            return false;
        }
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<char>> board = {
        {'.','8','7','6','5','4','3','2','1'},
        {'2','.','.','.','.','.','.','.','.'},
        {'3','.','.','.','.','.','.','.','.'},
        {'4','.','.','.','.','.','.','.','.'},
        {'5','.','.','.','.','.','.','.','.'},
        {'6','.','.','.','.','.','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'8','.','.','.','.','.','.','.','.'},
        {'9','.','.','.','.','.','.','.','.'}};
    cout << bestIsValidSudoku(board) << endl;
    
    return 0;
}
