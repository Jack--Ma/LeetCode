//
//  PeakIndexInAMountainArray.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/21.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "PeakIndexInAMountainArray.hpp"

/**
 Let's call an array arr a mountain if the following properties hold:
    * arr.length >= 3
    * There exists some i with 0 < i < arr.length - 1 such that:
        * arr[0] < arr[1] < ... arr[i-1] < arr[i]
        * arr[i] > arr[i+1] > ... > arr[arr.length - 1]
 Given an integer array arr that is guaranteed to be a mountain, return any i such that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].
 
 Input: arr = [0,1,0]
 Output: 1
 
 Input: arr = [0,2,1,0]
 Output: 1
 
 Input: arr = [0,10,5,2]
 Output: 1
 */

void testPeakIndexInAMountainArray() {
    vector<int> arr = {3,5,3,2,0};
    cout << Solution().peakIndexInMountainArray(arr) << endl;
}

int Solution::peakIndexInMountainArray(vector<int> &arr) {
    // add MIN in head and tail, incase array out-of-bounds
    arr.insert(arr.begin(), INT_MIN);
    arr.insert(arr.end(), INT_MIN);
    int size = (int)arr.size();
    int left = 0, right = size-1;
    while (left <= right) {
        int p = (left + right) / 2;
        if (arr[p-1] < arr[p] && arr[p] < arr[p+1]) {
            // p in the mountain left side
            left = p+1;
        } else if (arr[p-1] > arr[p] && arr[p] > arr[p+1]) {
            // p in the mountain right side
            right = p-1;
        } else {
            return p-1;
        }
    }
    
    return 0;
}
