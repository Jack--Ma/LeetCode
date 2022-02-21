//
//  ReshapeTheMatrix.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/19.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "ReshapeTheMatrix.hpp"

/**
 Input: mat = [[1,2],[3,4]], r = 1, c = 4
 Output: [[1,2,3,4]]
 
 Input: mat = [[1,2],[3,4]], r = 2, c = 4
 Output: [[1,2],[3,4]]
 
 [[1,2],[3,4]] 4 1 --> [[1],[2],[3],[4]]
 */

// my solution
vector<vector<int>> Solution::matrixReshape(vector<vector<int>> &mat, int r, int c) {
    // illegal input r&c, retuen mat
    auto mat_h = mat.size();
    auto mat_w = mat.at(0).size();
    if (mat_h * mat_w != r *c) {
        return mat;
    }
    
    // r mean how many array
    // c mean how many number in array
    vector<vector<int>> result;
    vector<int> resultArray;
    int numberOfArray = c;
    for (int i = 0; i < mat.size(); i++) {
        vector<int> mat_i = mat[i];
        for (int j = 0; j < mat_i.size(); j++) {
            int num = mat_i[j];
            // build result array when num<0
            if (numberOfArray != 0) {
                resultArray.push_back(num);
                numberOfArray--;
            }
            // modify result by array when num=0
            if (numberOfArray == 0) {
                result.push_back(resultArray);
                numberOfArray = c;
                resultArray.clear();
            }
        }
    }
    return result;
}

// other best solution
vector<vector<int>> otherMatrixReshape(vector<vector<int>> &mat, int r, int c) {
    auto h=mat.size(), v=mat[0].size();
    // build result with filled 0
    vector<vector<int>> result(r, vector<int>(c, 0));
    
    // special case protect
    if (((h*v)!=(r*c)) || (h==r && v==c))
        return mat;
    
    int x=0,y=0;
    for (int i=0;i<h;i++) {
        for (int j=0;j<v;j++) {
            result[x][y]=mat[i][j];
            if (++y==c) {
                y=0;
                x++;
            }
        }
    }
    
    return result;
}

void testMatrixReshape() {
    vector<vector<int>> mat = {{1,2},{3,4},{5,6}};
    Solution().matrixReshape(mat, 3, 2);
}
