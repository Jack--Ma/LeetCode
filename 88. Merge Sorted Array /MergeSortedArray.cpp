//
//  MergeSortedArray.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/17.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "MergeSortedArray.hpp"

void printVector(const vector<int> &v) {
    for (int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}

/**
 Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 Output: [1,2,2,3,5,6]
 Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
 The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
*/
void Solution::merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> result;
    m = min((int)nums1.size(), m);
    n = min((int)nums2.size(), n);
    nums1 = vector<int>(nums1.begin(), nums1.begin()+m);
    nums2 = vector<int>(nums2.begin(), nums2.begin()+n);
    if (m == 0 && n == 0) {
        return;
    } else if (m == 0) {
        result = vector<int>(nums2.begin(), nums2.begin()+n);
    } else if (n == 0) {
        result = vector<int>(nums1.begin(), nums1.begin()+m);
    } else {
        int maxSize = max(m, n);
        // two pos to mark two list
        int i = 0, j = 0;
        while (i < maxSize && j < maxSize) {
            // prevent list cross
            if (i >= nums1.size()) {
                break;
            }
            if (j >= nums2.size()) {
                break;
            }
            int num1 = nums1[i];
            int num2 = nums2[j];
            // push the smaller num
            if (num1 <= num2) {
                result.push_back(num1);
                i++;
            } else {
                result.push_back(num2);
                j++;
            }
        }
        // insert the rest of list
        if (i < m) {
            result.insert(result.end(), nums1.begin()+i, nums1.end());
        }
        if (j < n) {
            result.insert(result.end(), nums2.begin()+j, nums2.end());
        }
    }
    printVector(result);
}

void testMerge() {
    vector<int> nums1 = {4,0,0,0,0,0};
    vector<int> nums2 = {1,2,3,5,6};
    Solution().merge(nums1, 1, nums2, 5);
}
