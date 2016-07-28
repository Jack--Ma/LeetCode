//
//  main.cpp
//  41-First_Missing_Positive
//
//  Created by JackMa on 16/7/27.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int otherFirstMissingPositive(vector<int> nums) {
    //循环遍历，使每个数组的数刚好对应到数组的下标，即1放到1号位置，4放到4号位置
    //若出现负数或者超过数组边界的数，则直接跳过
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[nums[i]]) {
            swap(nums[i], nums[nums[i]]);
            i--;
        }
    }
    
    //找到第一个对应下标的数字
    int k = 1;
    while (k < nums.size() && nums[k] == k) {
        k++;
    }
    //k等于size时单独判断返回值
    if (k < nums.size() || nums.size() == 0) {
        return k;
    } else {
        return nums[0] == k ? k + 1 : k;
    }
}

int firstMissingPositive(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int result = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            if (nums[i] - result > 1) {
                return result + 1;
            }
            result = nums[i];
        }
    }
    
    return result + 1;
}

int max(int x, int y) {
    return x;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {};
    cout << otherFirstMissingPositive(nums) << endl;
    
    return 0;
}
