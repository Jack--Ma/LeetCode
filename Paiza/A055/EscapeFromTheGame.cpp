//
//  EscapeFromTheGame.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/5.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <queue>
#include "EscapeFromTheGame.hpp"

/**
 入力例1
     7 6
     ######
     #....#
     #.##.#
     #.#S.#
     #.####
     #.....
     ######
 出力例1
 YES
 
 入力例2
     7 6
     ......
     ......
     .####.
     #..S.#
     #....#
     .####.
     ......
 出力例2
 NO
 */

class Solution {
private:
    int k = 4;
    // step[0~3] mean right-bottom-left-up
    int step[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    queue<int> qx[101];
    queue<int> qy[101];
    
public:
    int height, width;
    int x_0, y_0;
    char data[101][101];
    int flag[101][101];

    int bfs() {
        qx[0].push(x_0);
        qy[0].push(y_0);
        flag[x_0][y_0] = 1;
        int i = 0;
        for (;;i++) {
            while (!qx[i].empty()) {
                int tx = qx[i].front();
                qx[i].pop();
                int ty = qy[i].front();
                qy[i].pop();
                for (int j = 0; j < k; j++) {
                    int tx_after = tx + step[j][0], ty_after = ty + step[j][1];
                    if ((tx_after >= 0) && (tx_after < height) &&
                        (ty_after >= 0) && (ty_after) < width &&
                        flag[tx_after][ty_after] == 0 &&
                        data[tx_after][ty_after] != '#') {
                        qx[i+1].push(tx_after);
                        qy[i+1].push(ty_after);
                        flag[tx_after][ty_after] = 1;
                    }
                }
            }
            if (qx[i+1].empty()) {
                break;
            }
        }
        return i;
    }

};

void testEscapeFromTheGame() {
    Solution solution = Solution();
    cin >> solution.height >> solution.width;
    for (int i = 0; i < solution.height; i++) {
        for (int j = 0; j < solution.width; j++) {
            cin >> solution.data[i][j];
            if (solution.data[i][j] == 'S') {
                solution.x_0 = i;
                solution.y_0 = j;
            }
        }
    }
    // ans is the largest escape length
    int ans = solution.bfs();
    for (int i = 0; i < solution.height; i++) {
        for (int j = 0; j < solution.width; j++) {
            if (solution.flag[i][j] == 0 && solution.data[i][j] == '.') {
                // There are walls all around point(x_0, y_0)
                ans = 0;
                break;
            }
        }
    }
    if (ans == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}
