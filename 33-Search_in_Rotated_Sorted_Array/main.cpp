//
//  main.cpp
//  33-Search_in_Rotated_Sorted_Array
//
//  Created by JackMa on 16/7/26.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//二分法
int otherSearch(vector<int> &nums, int target) {
    int start = 0, end = int(nums.size());
    while (start != end) {
        const int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        //由于数组排序不定，需要确定左右边界
        if (nums[start] <= nums[mid]) {
            if (nums[start] <= target && target < nums[mid]) {
                end = mid;
            } else {
                start = mid+1;
            }
        } else {
            if (nums[mid] < target && target <= nums[end-1]) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
    }
    
    return -1;
}

//直接遍历
int search(vector<int> &nums, int target) {
    int result = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            result = i;
            break;
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {8,9,10,1,2,3,4,5,6,7};
    int result = otherSearch(nums, 4);
    cout << result << endl;
    
    return 0;
}
