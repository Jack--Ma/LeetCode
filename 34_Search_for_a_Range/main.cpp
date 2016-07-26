//
//  main.cpp
//  34_Search_for_a_Range
//
//  Created by JackMa on 16/7/26.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> result;
    int start = 0, end = int(nums.size());
    int first_location = -1, second_location = -1;
    while (start <= end) {
        const int mid = start + (end - start)/2;
        if (nums[mid] < target) {
            start = mid + 1;
        } else if (nums[mid] > target){
            end = mid - 1;
        } else {
            first_location = mid;
            end = mid - 1;
        }
    }
    
    start = 0;
    end = int(nums.size());
    while (start <= end) {
        const int mid = start + (end - start)/2;
        if (nums[mid] < target) {
            start = mid + 1;
        } else if (nums[mid] > target){
            end = mid - 1;
        } else {
            second_location = mid;
            start = mid + 1;
        }
    }
    
    result.push_back(first_location);
    result.push_back(second_location);
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {0,0,0,0,2,2,3,3,4,4,5,5,5,6,7,7,8,9,9,9,10};
    vector<int> result = searchRange(nums, 10);
    
    return 0;
}
