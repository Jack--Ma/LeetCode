//
//  main.cpp
//  40-Combination_Sum_II
//
//  Created by JackMa on 16/7/27.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void findAllResules(vector<vector<int>> &results, vector<int> &result, int target, int start, vector<int> &nums) {
    if (target == 0) {
        vector<int> sort_result(result);
        sort(sort_result.begin(), sort_result.end());
        
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
            result.push_back(nums[i]);
            //和39唯一的不同，这里start设为i+1，表示每个数字只能用一次
            findAllResules(results, result, target - nums[i], i+1, nums);
            result.pop_back();
        }
    }
}

vector<vector<int>> combinationSum2(vector<int> &nums, int target) {
    vector<vector<int>> results;
    vector<int> resule;
    
    findAllResules(results, resule, target, 0, nums);
    sort(results.begin(), results.end());
    return results;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> results = combinationSum2(nums, 18);
    
    return 0;
}
