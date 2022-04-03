//
//  SortAnArray.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/1.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "SortAnArray.hpp"

vector<int> _sortArray_insert_sort(vector<int> &nums);

/**
 Given an array of integers nums, sort the array in ascending order.

 Input: nums = [5,2,3,1]
 Output: [1,2,3,5]
 
 Input: nums = [5,1,1,2,0,0]
 Output: [0,0,1,1,2,5]
 */

void testSortArray() {
    vector<int> nums = {5,1,1,2,0,0,-1,-6};
    printVector(Solution().sortArray(nums));
}

// Bucket sort array
void _sortingArray_bucket_sort(vector<int> &nums) {
    int maxValue = nums[0], minValue = nums[0];
    for (int i = 1; i < nums.size(); i ++) {
        minValue = min(minValue, nums[i]);
        maxValue = max(maxValue, nums[i]);
    }
    
    // count of bucket
    const int BUCKET_COUNT = 5;
    // number count of a bucket
    int bucketCapacity = (maxValue - minValue) / BUCKET_COUNT + 1;
    
    // build bucket
    vector<vector<int>> buckets(BUCKET_COUNT, vector<int>());
    
    // distribute all number into bucket
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        int bucketIndex = (num - minValue) / bucketCapacity;
        buckets[bucketIndex].push_back(num);
    }
    
    vector<int> result;
    for (vector<int> bucket : buckets) {
        // sort every bucket numbers
        _sortArray_insert_sort(bucket);
        // and merge all buckets
        result.insert(result.end(), bucket.begin(), bucket.end());
    }
    
    nums = result;
}

/// Counting sort array
void _sortArray_counting_sort(vector<int> &nums) {
    // find the max abs(value) in nums, value may less than zero
    int maxValue = nums[0];
    for (int i = 1; i < nums.size(); i ++) {
        maxValue = max(maxValue, abs(nums[i]));
    }
    // num range is [0, maxValue]
    vector<int> numCounting(maxValue+1, 0);
    for (int i = 0; i < nums.size(); i ++) {
        int num = nums[i];
        numCounting[num]++;
    }
    
    vector<int> result;
    for (int i = 0; i < numCounting.size(); i++) {
        int count = numCounting[i];
        while (count-- > 0) {
            result.push_back(i);
        }
    }
    
    nums = result;
}

/// Merge sort array
void _sortArray_merge_sort(vector<int> &nums, int left, int right) {
    void (^MergeBlock)(vector<int>&, int, int, int) = ^(vector<int>& nums, int left, int right, int mid) {
        // merge two sub-array, sub-array is sorted
        // left array is nums[left, mid], right array is nums[mid+1, right]
        vector<int> leftArray(nums.begin() + left, nums.begin() + mid + 1);
        vector<int> rightArray(nums.begin() + mid + 1, nums.begin() + right + 1);
        // set the last value is INT_MAX
        leftArray.push_back(INT_MAX);
        rightArray.push_back(INT_MAX);
        int p = 0, q = 0;
        // replace nums[left, right] with leftArray and rightArray
        for (int i = left; i <= right; i++) {
            if (leftArray[p] < rightArray[q]) {
                nums[i] = leftArray[p];
                p++;
            } else {
                nums[i] = rightArray[q];
                q++;
            }
        }
    };
    
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    _sortArray_merge_sort(nums, left, mid);
    _sortArray_merge_sort(nums, mid+1, right);
    MergeBlock(nums, left, right, mid);
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
    _sortingArray_bucket_sort(nums);
    
    return nums;
}
