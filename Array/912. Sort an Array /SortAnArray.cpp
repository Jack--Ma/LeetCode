//
//  SortAnArray.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/1.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "SortAnArray.hpp"

/**
 Given an array of integers nums, sort the array in ascending order.

 Input: nums = [5,2,3,1]
 Output: [1,2,3,5]
 
 Input: nums = [5,1,1,2,0,0]
 Output: [0,0,1,1,2,5]
 */

void testSortArray() {
    vector<int> nums = {5,1,1,2,0,0};
    printVector(Solution().sortArray(nums));
}

/// Bubble sort array
vector<int> _sortArray_bubble_sort(vector<int> &nums) {
    const int size = (int)nums.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            // constantly swap the bigger number forward
            if (nums[j+1] < nums[j]) {
                swap(nums[j+1], nums[j]);
            }
        }
    }
    
    return nums;
}

/// Quick sort array
vector<int> _sortArray_quick_sort(vector<int> &nums, int low, int high) {
    if (low >= high) {
        return nums;
    }
    
    int pivot = (low + high) / 2;
    int pivotValue = nums[pivot];
    // move pivot to nums tail
    swap(nums[pivot], nums[high]);
    // use store index represent the pivot index after loop
    int storeIndex = low;
    // loop from low to high-1
    for (int i = low; i < high; i++) {
        // swap all numbers smaller than pivotValue
        if (nums[i] < pivotValue) {
            swap(nums[i], nums[storeIndex]);
            storeIndex++;
        }
    }
    swap(nums[storeIndex], nums[high]);
    
    // storeIndex is the new pivot
    _sortArray_quick_sort(nums, low, storeIndex - 1);
    _sortArray_quick_sort(nums, storeIndex + 1, high);
    return nums;
}

vector<int> Solution::sortArray(vector<int> &nums) {
    vector<int> result;
    result = _sortArray_bubble_sort(nums);
    
    return result;
}
