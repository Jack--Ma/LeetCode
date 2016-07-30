//
//  main.cpp
//  54-Spiral_Matrix
//
//  Created by JackMa on 16/7/29.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void next_num(int &last_x, int &last_y, int n, int m, int i) {
    //last_x代指第几列，last_y代指第几行
    if (last_y == i && last_x < m-1+i) {
        last_x++;
        return;
    }
    if (last_x == m-1+i && last_y < n-1+i) {
        last_y++;
        return;
    }
    if (last_y == n-1+i && last_x > i) {
        last_x--;
        return;
    }
    if (last_x == i && last_y >i) {
        last_y--;
        return;
    }
}

vector<int> spiralMatrix(vector<vector<int>> &matrix) {
    if (matrix.empty()) {
        return {};
    }
    const int N = int(matrix.size());//N行
    const int M = int(matrix[0].size());//M列
    vector<int> result(N*M, 0);
    
    int x = 0, y = 0;//类比于坐标轴
    int time = 0;//记录向内的次数
    for (int i = 0; i < N*M; i++) {
        result[i] = matrix[y][x];
        next_num(x, y, N-time*2, M-time*2, time);
        
        if (i != 0 && x == y && x <= (min(N,M)-1)/2) {
            x++;
            y++;
            time++;
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> nums = {{1,2,3,4,5,6,7,8,9,10},{11,12,13,14,15,16,17,18,19,20},{21,22,23,24,25,26,27,28,29,30},{31,32,33,34,35,36,37,38,39,40},{41,42,43,44,45,46,47,48,49,50}};
    vector<int> result = spiralMatrix(nums);
    
    return 0;
}
