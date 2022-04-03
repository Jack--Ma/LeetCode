//
//  TopKFrequentElements.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/3.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <unordered_map>
#include <unordered_set>
#include <queue>
#include "TopKFrequentElements.hpp"

/**
 Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 Input: nums = [1,1,1,2,2,3], k = 2
 Output: [1,2]
 Input: nums = [1], k = 1
 Output: [1]
 */

void testTopKFrequent() {
    vector<int> nums = {4,1,-1,2,-1,2,3};
    printVector(Solution().topKFrequent(nums, 2));
}

// override
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

/// other solution by use priority queue
vector<int> _topKFrequent_priority_queue(vector<int>& nums, int k) {
    // key is the number is nums, value is the frequent of this key
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        map[num]++;
    }
    
    // priority queue store the TopK pair
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> queue;
    for (auto pair : map) {
        queue.push(pair);
        // pop the smallest frequent pair
        if (queue.size() > k) {
            queue.pop();
        }
    }
    
    vector<int> result;
    while (!queue.empty()) {
        result.push_back(queue.top().first);
        queue.pop();
    }
    
    return result;
}

/// my solution by use counting-sort
vector<int> Solution::topKFrequent(vector<int> &nums, int k) {
    return _topKFrequent_priority_queue(nums, k);
    
    // key is the number is nums, value is the frequent of this key
    unordered_map<int, int> map;
    int minValue = 1, maxValue = 1;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        map[num]++;
        minValue = min(minValue, map[num]);
        maxValue = max(maxValue, map[num]);
    }
    
    /**
     using counting-sort method
     */
    
    // build a counting array, store the frequent appear count
    vector<int> counting(maxValue - minValue + 1, 0);
    for (auto pair : map) {
        int count = pair.second;
        counting[count - minValue]++;
    }
    
    // set contains the TopK frequent number
    unordered_set<int> set;
    for (int i = (int)counting.size() - 1; i >= 0; i--) {
        if (k == 0) {
            break;
        }
        int countingValue = counting[i];
        k -= countingValue;
        set.insert(i+minValue);
    }

    vector<int> result;
    for (auto pair : map) {
        // find TopK frequent, and add its number
        if (set.find(pair.second) != set.end()) {
            result.push_back(pair.first);
        }
    }
    return result;
}
