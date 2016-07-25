//
//  main.cpp
//  26-Remove_Duplicates_from_Sorted_Array
//
//  Created by JackMa on 16/7/25.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//LeetCode answer
int otherRemoveDuplicates(vector<int> &nums) {
    if (nums.size() == 0) {
        return 0;
    }
    
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[i] != nums[j]) {
            i++;
            nums[i] = nums[j];
        }
    }
    
    return i+1;
}

//My answer
int removeDuplicates(vector<int> &nums) {
    for (auto i = nums.begin(); i != nums.end(); i++) {
        auto j = i+1;
        while (j != nums.end() && *j == *i) {
            nums.erase(j);
            j = i+1;
        }
    }
    
    return int(nums.size());
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1,1,1,2,2,3,4,7};
    int result = otherRemoveDuplicates(nums);
    cout << result << endl;
    
    return 0;
}
