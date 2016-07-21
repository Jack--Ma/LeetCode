//
//  main.cpp
//  1-Two_Sum
//
//  Created by JackMa on 16/7/21.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> hash;
    vector<int> result;
    
    //一边循环一边加入hash表
    for (int i = 0; i < nums.size(); i++) {
        int value = nums[i];
        int next_value = target - value;
        //hash[next_value]一定在i前面
        if (hash.find(next_value) != hash.end()) {
            result.push_back(hash[next_value]);
            result.push_back(i);
            return result;
        }
        hash[value] = i;
    }
    
    result.push_back(-1);
    result.push_back(-1);
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> p = {0,2,3,0};
    vector<int> results = twoSum(p, 6);
    
    for (int i = 0; i < results.size(); i++) {
        std::cout << results[i] << " " << endl;
    }
    
    return 0;
}
