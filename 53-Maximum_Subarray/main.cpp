//
//  main.cpp
//  53-Maximum_Subarray
//
//  Created by JackMa on 16/7/29.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    int largest_sum = nums[0]-1;
    int sum = -abs(nums[0])-1;//...使第一次循环后sum=num[0]
    
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] >= sum + nums[i]) {
            sum = nums[i];//nums[i]大于前面sum+nums[i]，则取最大值
        } else {
            sum += nums[i];//否则，sum加上nums[i]
        }
        largest_sum = max(largest_sum, sum);
    }
    
    return largest_sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {31,-41,59,26,-53,58,97,-93,-23,84};
    int max = maxSubArray(nums);
    cout << max << endl;
    
    return 0;
}
