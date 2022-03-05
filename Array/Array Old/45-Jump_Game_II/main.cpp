//
//  main.cpp
//  45-Jump_Game_II
//
//  Created by JackMa on 16/7/28.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//Best answer
int bestJump(vector<int> &nums) {
    const int N = int(nums.size());
    int step = 0;
    int last = 0;
    int curr = 0;
    for (int i = 0; i < N; ++i) {
        //当i > last的时候，说明last之前的已经遍历完成
        //此时curr即为下一步的正确位置
        if (i > last) {
            last = curr;
            ++step;
        }
        curr = max(curr, i+nums[i]);
    }
    
    return step;
}

//从后向前递归
//LeetCode上会超时
void otherJump(vector<int> &nums, int N, vector<int> &result) {
    if (N == 0) {
        return;
    }
    //index是N之前的能到达N的最远位置
    int index = 0;
    for (int i = N-1; i >= 0; i--) {
        if (nums[i] + i >= N) {
            index = i;
        }
    }
    result.push_back(index);
    otherJump(nums, index, result);
}

//My answer
int jump(vector<int> &nums) {
    const int N = int(nums.size());

    if (N == 1 || N == 0) {
        return 0;
    }
    int step = 0;//步数
    int next_step_min = 0;//当前这一步对应下一步的范围的最小值
    int next_step_max = 0;//当前这一步对应下一步的范围的最大值
    while (next_step_min <= next_step_max) {
        step++;
        int next_step_max_temp = next_step_max;//临时
        //在[min, max]范围内找到下一步的范围的最大值
        for (int j = next_step_min; j <= next_step_max_temp; j++) {
            int max_step = j + nums[j];
            if (max_step >= N-1) {
                return step;
            }
            if (max_step > next_step_max) {
                next_step_max = max_step;
            }
        }
        //下一步范围的最小值为max+1
        next_step_min = next_step_max_temp + 1;
    }

    
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {2,2,2,2,2};
    vector<int> result = {};
    int jump_num = bestJump(nums);
    otherJump(nums, int(nums.size()-1), result);
    cout << jump_num << endl;
    cout << result.size() << endl;
    
    return 0;
}
