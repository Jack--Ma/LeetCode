//
//  main.cpp
//  35-Search_Insert_Position
//
//  Created by JackMa on 16/7/27.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//二分法
int searchInsert(vector<int> &nums, int target) {
    int position = 0;
    int start = 0, end = int(nums.size());
    
    while (start <= end) {
        const int mid = start + (end - start) / 2;
        if (mid == nums.size()) {
            return mid;
        }
        if (target < nums[mid]) {
            end = mid - 1;
            //target在start前
            if (end < start) {
                position = start;
                break;
            }
        } else if (target > nums[mid]) {
            start = mid +1;
            //target在start后
            if (start > end) {
                position = start;
                break;
            }
        } else {
            position = mid;
            break;
        }
        
    }
    
    return position;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums ={1};
    int position = searchInsert(nums, -1);
    cout << position << endl;
    
    return 0;
}
