//
//  main.cpp
//  84-Largest_Rectangle_in_Histogram
//
//  Created by JackMa on 16/8/10.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea_Best(vector<int> &heights) {
    heights.push_back(0);//若最后的数呈递增态，则需要加0，再计算一次
    stack<int> stack;//stack存放height的下标，对应的高度是依次递增的
    int max_area = 0;
    int N = int(heights.size());
    
    int i = 0;
    while (i < N) {
        //为空或栈顶元素较小时，直接入栈，始终维持栈内是一个向上递增的状态
        //否则，计算面积
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

//This is not a good answer
//If heights array is [0...20000], the time limit will exceeded
int largestRectangleArea(vector<int> &heights) {
    int largest_sum = 0;
    for (int i = 0; i < heights.size(); i++) {
        int this_height = heights[i];
        int sum = 0;
        int left = i-1, right = i+1;
        //找到左右两边高度低于i柱子的left和right
        while (heights[i] <= heights[right] && right < heights.size()) {
            right++;
        }
        while (heights[i] <= heights[left] && left >= 0) {
            left--;
        }
        //right-left-1即为长度，this_height为高度
        sum = this_height * (right - left - 1);
        largest_sum = max(largest_sum, sum);
    }
    
    return largest_sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> heights = {2,1,5,6,2,3};
    cout << largestRectangleArea_Best(heights) << endl;
    
    return 0;
}
