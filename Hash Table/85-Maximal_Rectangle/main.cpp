//
//  main.cpp
//  85-Maximal_Rectangle
//
//  Created by JackMa on 16/9/4.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//use No.84's method
int largestRectangleArea_Best(vector<int> &heights) {
    int max_area = 0;
    stack<int> stack;
    const int N = int(heights.size());
    
    int i = 0;
    while (i < N) {
        if (stack.empty() || heights[i] >= heights[stack.top()]) {
            stack.push(i++);
        } else {
            int top_index = stack.top();
            stack.pop();
            int height = heights[top_index];
            int width = stack.empty() ? i : i - stack.top() - 1;
            max_area = max(max_area, height * width);
        }
    }
    
    return max_area;
}

int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.size() == 0) {
        return 0;
    }
    const int M = int(matrix[0].size());//width
    const int N = int(matrix.size());//height
    int max_rect = 0;
    
    vector<int> heights(M+1, 0);
    for (int i = 0; i < N; i++) {
        //以行为底，向上的1的长度的高
        for (int j = 0; j < M; j++) {
            matrix[i][j] == '1' ? heights[j]++ : heights[j] >= 1 ? heights[j] = 0 : NULL;
        }
        
        max_rect = max(max_rect, largestRectangleArea_Best(heights));
    }
    
    return max_rect;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout << maximalRectangle(matrix) << endl;
    
    return 0;
}
