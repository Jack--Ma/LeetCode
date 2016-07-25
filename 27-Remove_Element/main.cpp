//
//  main.cpp
//  27-Remove_Element
//
//  Created by JackMa on 16/7/25.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int otherRemoveElement(vector<int> &nums, int val) {
    int i = 0;
    int n = int(nums.size());
    
    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n-1];
            n--;
        } else {
            i++;
        }
    }
    
    return n;
}

int removeElement(vector<int> &nums, int val) {
    auto i = remove(nums.begin(), nums.end(), val);
    nums.erase(i, nums.end());
    
    return int(nums.size());
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {3,2,2,1,4,1,8,3};
    int result = removeElement(nums, 3);
    cout << result << endl;
    
    return 0;
}
