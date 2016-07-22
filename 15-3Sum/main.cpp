//
//  main.cpp
//  15-3Sum
//
//  Created by JackMa on 16/7/22.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> results = {};
    
    sort(nums.begin(), nums.end());//从小到大排序
    for (int i = 0; i < nums.size(); i++) {
        //存在相邻的相同两个数，跳过
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        int start = i + 1, end = int(nums.size()) - 1;
        int num_to_zero = -nums[i];
        
        while (start < end) {
            //i后面有两个相同的数字，则跳过第二个
            if (start > i+1 && nums[start] == nums[start-1]) {
                start++;
                continue;
            }
            //三种情况的处理
            if (nums[start] + nums[end] < num_to_zero) {
                start++;
            } else if (nums[start] + nums[end] > num_to_zero) {
                end--;
            } else {
                vector<int> result = {nums[i], nums[start], nums[end]};
                results.push_back(result);
                start++;
            }
        }
    }
    return results;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {-1,0,1,2,-1,-4,2};
    vector<vector<int>> results = threeSum(nums);
    
    return 0;
}
