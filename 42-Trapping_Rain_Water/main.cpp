//
//  main.cpp
//  42-Trapping_Rain_Water
//
//  Created by JackMa on 16/7/28.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//使用stack
int otherTrap(vector<int> &nums) {
    const int N = int(nums.size());
    stack<pair<int, int>> s;
    int water = 0;
    
    for (int i = 0; i < N; i++) {
        int height = 0;
        
        while (!s.empty()) {
            int bar = s.top().first;//柱子高度
            int pos = s.top().second;//柱子位置
            //width 为这一块的宽度
            int width = i - pos - 1;
            //min(bar, nums[i]) - height 为这一块的高度
            water += (min(bar, nums[i]) - height) * width;
            //保存这次计算过的height，下一次计算height以上的面积
            height = bar;
            
            if (nums[i] < bar) {
                break;
            } else {
                s.pop();
            }
        }
        
        s.push(make_pair(nums[i], i));
    }
    
    return water;
}

//按柱子逐一计算
int trap(vector<int> &height) {
    int result = 0;
    vector<int> left_maxs, right_maxs;
    int left_max = 0, right_max = 0;
    
    //获取每个柱子左侧柱子的最大高度
    for (int i = 0; i < height.size(); i++) {
        left_maxs.push_back(left_max);
        if (height[i] > left_max) {
            left_max = height[i];
        }
    }
    
    //获取每个柱子右侧柱子的最大高度
    for (int i = int(height.size())-1; i >= 0; i--) {
        right_maxs.push_back(right_max);
        if (height[i] > right_max) {
            right_max = height[i];
        }
    }
    
    //遍历，求每个柱子对应的盛水量
    for (int i = 0; i < height.size(); i++) {
        //取两侧最低的柱子
        int min_height = min(left_maxs[i], right_maxs[height.size()-1-i]);
        //计算这个柱子对应盛水量
        int water = min_height - height[i];
        //大于0，则加入result
        if (water > 0) {
            result += water;
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {0,1,0,2,1,0,0,3,2,1,2,1};
    int water = otherTrap(nums);
    cout << water << endl;
    
    return 0;
}
