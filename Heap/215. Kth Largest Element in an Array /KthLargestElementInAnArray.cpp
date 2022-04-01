//
//  KthLargestElementInAnArray.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/31.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "KthLargestElementInAnArray.hpp"
#include <queue>

/**
 Given an integer array nums and an integer k, return the kth largest element in the array.

 Note that it is the kth largest element in the sorted order, not the kth distinct element.
 
 Input: nums = [3,2,1,5,6,4], k = 2
 Output: 5
 
 Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
 Output: 4
 */

void testFindKthLargest() {
    vector<int> nums = {3,2,4,5,6,1};
    cout << Solution().findKthLargest(nums, 2) << endl;
}

// solution by use sort
int _findKthLargest_sort(vector<int>& nums, int k)  {
    sort(nums.begin(), nums.end(), [](int a, int b) {
        return a >= b;
    });
    
    return nums[k];
}

// solution by use priority queue
int _findKthLargest_priority(vector<int>& nums, int k)  {
    // priority queue, save number in greater order
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (auto i : nums) {
        pq.push(i);
        
        // only k numbers are saved in pq
        if (pq.size() > k) {
            // pop the smallest number
            pq.pop();
        }
    }
    
    return pq.top();
}

/// make numbers before pivot are smaller than pivot
/// @param nums original nums array
/// @param left left index in nums
/// @param right right index in nums
int partition(vector<int>& nums, int left, int right) {
    // 1. we take the middle element
    int pivot_idx = (left+right)/2;
    int pivot_val = nums[pivot_idx];
    // 2. swap the pivot element to last
    swap(nums[pivot_idx], nums[right]);
    // 3. we swap all elements smaller than pivot to the left
    int store_idx = left;
    for (int i = left; i < right; ++i) {
        if (nums[i] < pivot_val) {
            swap(nums[i], nums[store_idx]);
            store_idx++;
        }
    }
    // 4. move pivot back to its place
    swap(nums[store_idx], nums[right]);
    return store_idx;
}

// solution by use divide-and-conquer
int Solution::findKthLargest(vector<int>& nums, int k) {
    int left = 0;
    int right = (int)nums.size()-1;
    int pivotIdx = (int)nums.size();
    
    while (pivotIdx != nums.size()-k) {
        pivotIdx = partition(nums, left, right);
        if (pivotIdx < nums.size()-k) {
            left = pivotIdx+1;
        } else {
            right = pivotIdx-1;
        }
    }
    return nums[pivotIdx];
}
