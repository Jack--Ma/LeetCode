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
    cout << isValidSudoku(board) << endl;
    
    return 0;
}
