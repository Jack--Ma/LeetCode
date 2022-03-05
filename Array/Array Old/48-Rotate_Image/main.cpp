//
//  main.cpp
//  48-Rotate_Image
//
//  Created by JackMa on 16/7/29.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &matrix) {
    //先按水平中线上下互换
    for (int i = 0,j = int(matrix.size()-1); i < j; i++, j--) {
        vector<int> temp = matrix[j];
        matrix[j] = matrix[i];
        matrix[i] = temp;
    }
    //再沿(0, 0)--(N, N)线互换数字
    for (int i = 0; i < matrix.size()-1; i++) {
        for (int j = i+1; j < matrix.size(); j++) {
            int temp = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(matrix);
    
    return 0;
}
