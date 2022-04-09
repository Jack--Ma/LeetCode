//
//  BossHome.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/9.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <stack>
#include "BossHome.hpp"

/**
 あなたはゲームエンジニアで、ダンジョンゲームの開発をしています。
 ダンジョンのマップは縦 H マス × 横 W マスからなっており、このダンジョンのいくつかのマスは塞がっています。
 あなたは、塞がっていないマスのみからなる長方形のうちで、面積が最大となる長方形をボスの部屋にしようと考えています。
 このとき、ボスの部屋の面積を出力してください。
 
 入力例1
     4 5
     .##..
     .....
     ...##
     #.###
 
 出力例1
     6
 
 Leetcode: https://leetcode.com/problems/maximal-rectangle/
 */

class Solution {
public:
    int width, height;
    
    int largestRectangleArea_left_right(vector<int> heights) {
        int n = (int)heights.size();
        vector<int> left(n, 0), right(n, 0);
        // stack store index of heights, and are increase stacks
        stack<int> st1, st2;
        // find i left&right side height which is smallest and nearest
        for (int i = 0; i < n; i++) {
            while (!st1.empty() && heights[st1.top()] >= heights[i]) {
                // pop when top value is bigger, keep stack is incremental
                st1.pop();
            }
            left[i] = (st1.empty () ? -1 : st1.top());
            st1.push(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st2.empty() && heights[st2.top()] >= heights[i]) {
                // pop when top value is bigger, keep stack is incremental
                st2.pop();
            }
            right[i] = (st2.empty () ? n : st2.top());
            st2.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int height = heights[i];
            int width = right[i] - left[i] - 1;
            ans = max(ans, height * width);
        }
        return ans;
    }
    
    // find largest area
    int largestRectangleArea(vector<int> heights) {
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
    
    int bossHome(vector<vector<char>> data) {
        vector<int> heights(width, 0);
        int maxLargest = 1;
        for (int i = 0; i < height; i++) {
            /**
             heights will be:
             [1,0,0,1,1] largest area is 1*2=2
             [2,1,1,2,2] largest area is 1*5=5
             [3,2,2,0,0] largest area is 2*3=6
             [0,3,0,0,0] largest area is 3*1=3
             */
            for (int j = 0; j < width; j++) {
                if (data[i][j] == '.') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            int largest = largestRectangleArea_left_right(heights);
            maxLargest = max(maxLargest, largest);
        }
        
        return maxLargest;
    }
};

void testBossHome() {
    Solution solution = Solution();
    cin >> solution.height >> solution.width;
    
    vector<vector<char>> data;
    data = vector<vector<char>>(solution.height, vector<char>(solution.width, '#'));
    for (int i = 0; i < solution.height; i++) {
        for (int j = 0; j < solution.width; j++) {
            cin >> data[i][j];
        }
    }
    
    cout << solution.bossHome(data) << endl;
}
