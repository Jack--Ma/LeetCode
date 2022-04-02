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

/// Insert sort array
vector<int> _sortArray_insert_sort(vector<int> &nums) {
    // fast point to the pivot index, from 1 to size-1
    int fast = 1;
    while (fast < nums.size()) {
        int fastVale = nums[fast];
        // slow point range is [0, fast-1], and reverse order
        int slow = fast - 1;
        while (slow >= 0) {
            int slowValue = nums[slow];
            // if slowValue is bigger, keep move slow backward
            if (slowValue > fastVale) {
                swap(nums[slow], nums[slow+1]);
            }
            slow--;
        }
        fast++;
    }
    
    return nums;
}

/// Select sort array
vector<int> _sortArray_select_sort(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        // find the smallest number
        int minIndex = i;
        for (int j = i+1; j < nums.size(); j++) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        // move minimum index to i index
        swap(nums[i], nums[minIndex]);
    }
    return nums;
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
    result = _sortArray_insert_sort(nums);
    
    return result;
}
