//
//  FloodFill.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/11.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <queue>
#include "FloodFill.hpp"

/**
 An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
 
 You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].
 
 To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.
 
 Return the modified image after performing the flood fill.
 
 Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
 Output: [[2,2,2],[2,2,0],[2,0,1]]
 Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
 Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
 */

void testFloodFill() {
    vector<vector<int>> image = {
        {0,0,1},
        {0,1,1},
    };
    printVector(Solution().floodFill(image, 1, 1, 1));
}

void _floodFill_dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int sColor) {
    if (sr < 0 || sr >= image.size() ||
        sc < 0 || sc >= image[0].size() ||
        image[sr][sc] == newColor ||
        image[sr][sc] != sColor) {
        return;
    }
    image[sr][sc] = newColor;
    _floodFill_dfs(image, sr, sc+1, newColor, sColor);
    _floodFill_dfs(image, sr, sc-1, newColor, sColor);
    _floodFill_dfs(image, sr+1, sc, newColor, sColor);
    _floodFill_dfs(image, sr-1, sc, newColor, sColor);
}

// solution by use recursion
vector<vector<int>> _floodFill_recursion(vector<vector<int>>& image, int sr, int sc, int newColor) {
    _floodFill_dfs(image, sr, sc, newColor, image[sr][sc]);
    return image;
}

// solution by use queue
vector<vector<int>> Solution::floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    const int height = (int)image.size();
    const int width = (int)image[0].size();
    
    int direction[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
    // save s-point value
    int s = image[sr][sc];
    image[sr][sc] = newColor;
    
    queue<pair<int, int>> sQueue;
    sQueue.push(make_pair(sr, sc));
    while (!sQueue.empty()) {
        pair<int, int> top = sQueue.front();
        sQueue.pop();
        // 4 direction
        for (int i = 0; i < 4; i++) {
            // calculate next s point
            int next_sr = top.first + direction[i][1];
            int next_sc = top.second + direction[i][0];
            if (next_sr < 0 || next_sr >= height ||
                next_sc < 0 || next_sc >= width ||
                image[next_sr][next_sc] != s ||
                image[next_sr][next_sc] == newColor) {
                continue;
            }
            image[next_sr][next_sc] = newColor;
            sQueue.push({next_sr, next_sc});
        }
    }
    
    return image;
}
