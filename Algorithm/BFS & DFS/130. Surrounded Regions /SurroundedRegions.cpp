//
//  SurroundedRegions.cpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/4/24.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <queue>
#include "SurroundedRegions.hpp"

/**
 Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
 A region is captured by flipping all 'O's into 'X's in that surrounded region.
 
 Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
 */

void testSurroundedRegions() {
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'},
    };
//    board = {
//        {'O','O'},
//        {'O','O'}
//    };
    Solution().solve(board);
    printVector(board);
}

int W, H;
/// BFS solution is Time Limit Exceeded
void _surroundedRegions_BFS(vector<vector<char>> &board, int i, int j) {
    if (board[i][j] == 'X' || board[i][j] == 'W') {
        return;
    }
    
    queue<pair<int, int>> boardQueue;
    boardQueue.push(make_pair(i, j));
    while (!boardQueue.empty()) {
        int size = (int)boardQueue.size();
        for (int k = 0; k < size; k++) {
            pair<int, int> p = boardQueue.front();
            boardQueue.pop();
            // set 'W' to mark node
            board[p.first][p.second] = 'W';
            // judge around O node
            if (p.first > 0 && board[p.first-1][p.second] == 'O') {
                boardQueue.push(make_pair(p.first-1, p.second));
            }
            if (p.first < H-1 && board[p.first+1][p.second] == 'O') {
                boardQueue.push(make_pair(p.first+1, p.second));
            }
            if (p.second > 0 && board[p.first][p.second-1] == 'O') {
                boardQueue.push(make_pair(p.first, p.second-1));
            }
            if (p.second < W-1 && board[p.first][p.second+1] == 'O') {
                boardQueue.push(make_pair(p.first, p.second+1));
            }
        }
    }
}

/// DFS solution is better
void _surroundedRegions_DFS(vector<vector<char>> &board, int i, int j) {
    if (board[i][j] == 'X') {
        return;
    }
    board[i][j] = 'W';
    if (i > 0 && board[i-1][j] == 'O') {
        _surroundedRegions_DFS(board, i-1, j);
    }
    if (i < H-1 && board[i+1][j] == 'O') {
        _surroundedRegions_DFS(board, i+1, j);
    }
    if (j > 0 && board[i][j-1] == 'O') {
        _surroundedRegions_DFS(board, i, j-1);
    }
    if (j < W-1 && board[i][j+1] == 'O') {
        _surroundedRegions_DFS(board, i, j+1);
    }
}

void Solution::solve(vector<vector<char>> &board) {
    H = (int)board.size();
    W = (int)board[0].size();
    if (H < 3 || W < 3) {
        return;
    }
    
    // left/right border
    for (int i = 0; i < H; i++) {
        _surroundedRegions_DFS(board, i, 0);
        _surroundedRegions_DFS(board, i, W-1);
    }
    
    // top/bottom border
    for (int i = 1; i < W-1; i++) {
        _surroundedRegions_DFS(board, 0, i);
        _surroundedRegions_DFS(board, H-1, i);
    }
    
    // 'W' mean the node(i,j) is connected to the border
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == 'W') {
                board[i][j] = 'O';
            }
        }
    }
}
