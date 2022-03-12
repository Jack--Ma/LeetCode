//
//  SubarraySumEqualsK.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/11.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "SubarraySumEqualsK.hpp"
#include <numeric>
/**
 Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
 
 Input: nums = [1,1,1], k = 2
 Output: 2
 
 Input: nums = [1,2,3,1], k = 3
 Output: 2
*/

void testSubarraySum() {
    vector<int> nums = {1,2,0,3,0};
    cout << Solution().subarraySum(nums, 3) << endl;
}

// better solution
int Solution::subarraySum(vector<int> &nums, int k) {
    int result = 0;
    
    // map save the frequency with subArray sum, such as: [0,0]/[0,1]/[0,2]/[0,3]......
    // eg. nums is {1,2,0,3,0}, and map will be {1->1, 3->2, 6->2}
    unordered_map<int, int> sumFrequencyMap;
    sumFrequencyMap[0]++;
    int numsSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        numsSum += num;
        // in every loop, find leftNum
        int leftNum = numsSum - k;
        
        // if leftNum in map, that mean before this num, the subArray exist
        if (sumFrequencyMap.find(leftNum) != sumFrequencyMap.end()) {
            result += sumFrequencyMap[leftNum];
        }
        
        sumFrequencyMap[numsSum]++;
    }
    
    return result;
}

// timeout solution, time consume is n*n/2
int _subarraySum_timeout(vector<int> &nums, int k) {
    int numSum = accumulate(nums.begin(), nums.end(), 0);
    int numCount = (int)nums.size();
    
    vector<int> subArray;
    int result = numSum == k ? 1 : 0;
    for (int j = 0; j < numCount - 1; j++) {
        int subSum = 0;
        // from j to num count - 1
        for (int i = j; i < numCount - 1; i++) {
            int num = nums[i];
            subSum += num;
            if (subSum == k) {
                result++;
            }
            if (j == 0 && (numSum - subSum == k)) {
                result++;
            }
        }
        numSum -= nums[j];
    }
    
    return result;
}
