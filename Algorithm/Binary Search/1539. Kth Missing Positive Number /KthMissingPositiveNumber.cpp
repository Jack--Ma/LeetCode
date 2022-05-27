//
//  KthMissingPositiveNumber.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/26.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "KthMissingPositiveNumber.hpp"

/**
 Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
 
 Find the kth positive integer that is missing from this array.
 
 Input: arr = [2,3,4,7,11], k = 5
 Output: 9
 Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
 
 Input: arr = [1,2,3,4], k = 2
 Output: 6
 Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
 */

void testKthMissingPositiveNumber() {
    /**
     [1,10,21,22,25]
     12
     */
    vector<int> arr = {2,3,4,7,11};
    cout << Solution().findKthPositive(arr, 5) << endl;
}

int _findKthPositive_DP(vector<int> &arr, int k)  {
    // result must bigger than k
    int result = k;
    for (int i = 0; i < arr.size(); i++) {
        /**
         eg. [2 3 4 7 11] k=5
         1. result begin with 5, because now arr is empty []
         2. for number [2]      5>2, so jump this numebr, result+1=6
         3. for number [3]      6>3, so jump this numebr, result+1=7
         4. for number [4]      7>4, so jump this numebr, result+1=8
         5. for number [7]      8>4, so jump this numebr, result+1=9
         6. for number [11]     9<11, so finish loop
         */
        // arr[i] is smaller
        if (arr[i] <= result) {
            result++;
        }
    }
    return result;
}

int Solution::findKthPositive(vector<int> &arr, int k) {
    return _findKthPositive_DP(arr, k);
    if (k < arr[0]) {
        return k;
    }
    int size = (int)arr.size();
    int maxNum = arr[size-1];
    
    if (maxNum-size >= k) {
        // kth int must lower than maxNum
        int left = 0, right = size-1;
        while (left < right) {
            int p = (left + right) / 2;
            int num_p = arr[p];
            // after p position, and distance is k, is [p+k]
            // if arr[p] smaller, mean kth is after p
            if (num_p < p + k + 1) {
                left = p+1;
            } else {
                right = p;
            }
        }
        return left+k;
    } else {
        // kth int must bigger than maxNum
//        return maxNum + (k-(maxNum-size));
        return k+size;
    }
}
