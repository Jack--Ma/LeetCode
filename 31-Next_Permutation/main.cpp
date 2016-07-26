//
//  main.cpp
//  31-Next_Permutation
//
//  Created by JackMa on 16/7/26.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//直接调用next_permutation求得下一数列...
void otherNextPermutation(vector<int> &nums) {
    next_permutation(nums.begin(), nums.end());
}

//My answer
void nextPermutation(vector<int> &nums) {
    if (nums.size() == 1) {
        return;
    }
    
    //找到交换的第一个数字
    int first_num = -1;
    for (int i = int(nums.size()-1); i > 0; i--) {
        if (nums[i-1] < nums[i]) {
            first_num = i-1;
            break;
        }
    }
    
    //原数组降序排列
    if (first_num == -1) {
        sort(nums.begin(), nums.end());
        return;
    }
    
    //找到交换的第二个数字
    int second_num = -1;
    for (int i = int(nums.size()-1); i > first_num; i--) {
        if (nums[i] > nums[first_num]) {
            second_num = i;
            break;
        }
    }
    
    //交换两个数，并对first_num后的数组按升序排列
    swap(nums[first_num], nums[second_num]);
    auto temp = nums.begin()+first_num+1;
    sort(temp, nums.end());
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1,2,3};
    nextPermutation(nums);
//    otherNextPermutation(nums);
    
    return 0;
}
