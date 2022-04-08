//
//  LongestSwipe.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/8.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "LongestSwipe.hpp"

/**
 「パイザ」では縦横に数字が N 個並んでおり。
 縦、横、あるいは斜めに一直線上に並んでいて、かつ連続している数字をスワイプすることができます。
 プログラマーであるあなたは、最長で何個の数字をスワイプできるのかを計算するプログラムを書くことにしました。
 
 Input:
 4
 1314
 1213
 2134
 3124
 
 Output:
 4
 */

class Solution {
private:
    int direction[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    vector<vector<int>> nums;
    vector<vector<int>> flag;
    int size;
    
    int _longestStep(int i, int j, int d0, int d1) {
        int step = 1;
        int _i = i+d0, _j = j+d1;
        int diff = nums[_i][_j] - nums[i][j];
        // increase or decrease
        if (diff == 1 || diff == -1) {
            while (_i < size && _j < size) {
                if (nums[_i][_j] - nums[i][j] == diff) {
                    step++;
                } else {
                    break;
                }
                i = _i;j = _j;
                _i = i+d0;_j = j+d1;
            }
        }
        
        return step;
    }
    
public:
    int longestSwipe(vector<vector<int>> data) {
        size = (int)data.size();
        nums = data;
        flag = vector<vector<int>>(size, vector<int>(size, 0));
        int maxStep = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                // 8 direction
                for (int d = 0; d < 8; d++) {
                    int _i = i+direction[d][0];
                    int _j = j+direction[d][1];
                    // must in data range and first calculate
                    if (_i < 0 || _i >= size ||
                        _j < 0 || _j >= size ||
                        flag[_i][_j] == 1) {
                        continue;
                    }
                    int step = _longestStep(i, j, direction[d][0], direction[d][1]);
                    maxStep = max(maxStep, step);
                }
                
                flag[i][j] = 1;
            }
        }
        
        return maxStep;
    }
};

void testLongestSwipe() {
    int wh = 0;
    cin >> wh;
    
    // build data
    vector<vector<int>> data(wh, vector<int>(wh, 0));
    for (int i = 0; i < wh; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < wh; j++) {
            int num = str[j] - '0';
            data[i][j] = num;
        }
    }
    cout << Solution().longestSwipe(data) << endl;
}
