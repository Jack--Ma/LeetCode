//
//  FindTheDistanceValueBetweenTwoArrays.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/23.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "FindTheDistanceValueBetweenTwoArrays.hpp"

/**
 Given two integer arrays arr1 and arr2, and the integer d, return the distance value between the two arrays.
 
 The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.
 
 Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
 Output: 2
 Explanation:
 For arr1[0]=4 we have:
     |4-10|=6 > d=2
     |4-9|=5 > d=2
     |4-1|=3 > d=2
     |4-8|=4 > d=2
 For arr1[1]=5 we have:
     |5-10|=5 > d=2
     |5-9|=4 > d=2
     |5-1|=4 > d=2
     |5-8|=3 > d=2
 For arr1[2]=8 we have:
     |8-10|=2 <= d=2
     |8-9|=1 <= d=2
     |8-1|=7 > d=2
     |8-8|=0 <= d=2
 */

void testFindTheDistanceValueBetweenTwoArrays() {
    vector<int> arr1 = {4,5,8};
    vector<int> arr2 = {10,9,1,8};
    cout << Solution().findTheDistanceValue(arr1, arr2, 2) << endl;
}

int Solution::findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d) {
    sort(arr2.begin(), arr2.end());
    int result = 0;
    
    for (int i = 0; i < arr1.size(); i++) {
        int num_i = arr1[i];
        int left = 0, right = (int)arr2.size()-1;
        bool find = false;
        while (left <= right) {
            int j = (left+right) / 2;
            int num_j = arr2[j];
            if (abs(num_i-num_j) <= d) {
                find = true;
                break;
            } else {
                if (num_j > num_i) {
                    right = j-1;
                } else {
                    left = j+1;
                }
            }
        }
        if (!find) {
            result++;
        }
    }
    
    return result;
}
