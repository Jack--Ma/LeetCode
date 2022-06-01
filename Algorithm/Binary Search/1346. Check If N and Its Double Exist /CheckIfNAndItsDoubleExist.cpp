//
//  CheckIfNAndItsDoubleExist.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/6/1.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "CheckIfNAndItsDoubleExist.hpp"

/**
 Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).

 More formally check if there exists two indices i and j such that :
    * i != j
    * 0 <= i, j < arr.length
    * arr[i] == 2 * arr[j]
 
 Input: arr = [10,2,5,3]
 Output: true
 Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.
 
 Input: arr = [3,1,7,11]
 Output: false
 Explanation: In this case does not exist N and M, such that N = 2 * M.
 */

void testCheckIfNAndItsDoubleExist() {
    vector<int> arr = {3,1,7,11};
    cout << Solution().checkIfExist(arr) << endl;
}

bool Solution::checkIfExist(vector<int> &arr) {
    unordered_set<int> set;
    for (int i = 0; i < arr.size(); i++) {
        int num = arr[i];
        if (set.find(num) != set.end()) {
            return true;
        }
        set.insert(num * 2);
        // even number
        if (num % 2 == 0) {
            set.insert(num / 2);
        }
    }
    
    return false;
}
