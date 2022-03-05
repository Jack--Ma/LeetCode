//
//  main.cpp
//  4-Median_of_Two_Sorted_Arrays
//
//  Created by JackMa on 16/7/21.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

double find_median_sorted_arrays(vector<int> &nums1, vector<int> &nums2) {
    int count1 = int(nums1.size());
    int count2 = int(nums2.size());
    int count = (count1 + count2) % 2 == 0 ? (count1 + count2) / 2 + 1: (count1 + count2 + 1) / 2;
    
    if (nums1.size() == 0 && nums2.size() == 0) {
        return 0.0;
    }
    if (nums1.size() == 0) {
        return (count1 + count2) % 2 == 0 ? (nums2[count-1] + nums2[count-2])/2.0 : nums2[count-1];
    }
    if (nums2.size() == 0) {
        return (count1 + count2) % 2 == 0 ? (nums1[count-1] + nums1[count-2])/2.0 : nums1[count-1];
    }
    
    nums2.push_back(INT_MAX);
    nums1.push_back(INT_MAX);
    
    vector<int> nums ;
    vector<int>::iterator vi1 = nums1.begin();
    vector<int>::iterator vi2 = nums2.begin();
    
    for (int i = 0; i < count1+count2; i++) {
        if (*vi1 <= *vi2) {
            nums.push_back(*vi1);
            vi1++;
        } else {
            nums.push_back(*vi2);
            vi2++;
        }
        if (nums.size() == count) {
            if ((count1 + count2) % 2 == 0) {
                //偶数个
                return (nums[count-1] + nums[count-2])/2.0;
            } else {
                //奇数个
                return nums[count-1];
            }
        }
    }
    
    return 0.0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    double result = find_median_sorted_arrays(nums1, nums2);
    cout << result << endl;

    return 0;
}
