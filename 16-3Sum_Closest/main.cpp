//
//  main.cpp
//  16-3Sum_Closest
//
//  Created by JackMa on 16/7/23.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int current_min = INT_MAX;
    
    for (int i = 0; i < nums.size(); i++) {
        //从双侧夹逼
        int start = i+1, end = int(nums.size())-1;
        
        while (start < end) {
            //计算三数的和
            int three_num_sum = nums[i]+nums[start]+nums[end];
            
            //更接近0的，进行赋值
            if (abs(target-three_num_sum) <= labs(target-current_min)) {
                current_min = three_num_sum;
            }
            
            //根据大小，判断start和end移动
            target-three_num_sum > 0 ? start++ : end--;
        }
    }
    
    return current_min;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {0,0,0,-1,-1,-2};
    int target = -2;
    int result = threeSumClosest(nums, target);
    cout << result << endl;
    
    return 0;
}
