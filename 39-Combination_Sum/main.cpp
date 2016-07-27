//
//  main.cpp
//  39-Combination_Sum
//
//  Created by JackMa on 16/7/27.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void findAllResults(vector<vector<int>> &results, vector<int> &result, int target, int start, vector<int> &nums) {
    if (target == 0) {
        vector<int> sort_result(result);
        sort(sort_result.begin(), sort_result.end());
        
        //有相等的直接返回
        for (int i = 0; i < results.size(); i++) {
            if (sort_result == results[i]) {
                return;
            }
        }

        results.push_back(sort_result);
        return;
    }
    
    for (int i = start; i < nums.size(); i++) {
        if (nums[i] <= target) {
            //保存i结点
            result.push_back(nums[i]);
            //进入i结点的子树
            findAllResults(results, result, target - nums[i], 0, nums);
            //弹出i结点的子结点，并进入i结点的下一个结点
            result.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int> &nums, int target) {
    vector<vector<int>> results = {};
    vector<int> result;
    
    //递归得到结果
    findAllResults(results, result, target, 0, nums);
    return results;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {2,3,6,7};
    vector<vector<int>> results = combinationSum(nums, 8);
    
    return 0;
}
